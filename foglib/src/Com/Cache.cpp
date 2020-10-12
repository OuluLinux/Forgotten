#include "Com.h"


namespace Memcached {
using namespace Upp;


thread__ memcached_st *memc = NULL;
thread__ memcached_server_st *servers = NULL;

void InitMemcachedThread() {
	if (memc == NULL) {
		memcached_return rc;
		memc = memcached_create(NULL);
		
		servers = memcached_server_list_append(servers, "localhost", 11211, &rc);
		if (rc != MEMCACHED_SUCCESS) {
			LOG("Memcache error: " << String(memcached_strerror(memc, rc)));
		}
		
		rc = memcached_server_push(memc, servers);
		if (rc != MEMCACHED_SUCCESS) {
			LOG("Memcache error: " << String(memcached_strerror(memc, rc)));
		}
		
		rc = memcached_server_push(memc, servers);
		if (rc != MEMCACHED_SUCCESS) {
			LOG("Memcache error: " << String(memcached_strerror(memc, rc)));
		}
	}
}

bool ClearMemcached(String key) {
	const char* empty_str = "";
	memcached_return rc = memcached_set(memc, key.Begin(), key.GetCount(), empty_str, 0, (time_t)0, (uint32_t)0);
	
	if (rc != MEMCACHED_SUCCESS) {
		LOG("Memcache error: " << String(memcached_strerror(memc, rc)));
		return false;
	} else {
		return true;
	}
}



struct MemcachedTester {
	
	void Process() {
		ASSERT(memc == NULL);
		InitMemcachedThread();
		
		String obj;
		ASSERT(GetMemcached("test", obj));
		
		LOG(Thread::GetCurrentId() << ": " << obj);
	}
	
	void Test() {
		InitMemcachedThread();
		
		String obj;
		obj = "testing123123";
		
		ASSERT(SetMemcached("test", obj));
		
		for(int i = 0; i < 100; i++) {
			Thread::Start(callback(Process));
		}
		Thread::ShutdownThreads();
		
		ASSERT(ClearMemcached("test"));
		ASSERT(!GetMemcached("test", obj));
	}
};

}



