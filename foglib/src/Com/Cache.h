#ifndef _Com_Cache_h_
#define _Com_Cache_h_


#include <libmemcached/memcached.h>

namespace Memcached {
using namespace Upp;

extern thread__ memcached_st *memc;
extern thread__ memcached_server_st *servers;

void InitMemcachedThread();

template <class T>
bool SetMemcached(String key, T& obj) {
	StringStream ss;
	ss.SetStoring();
	ss % obj;
	String result = ss.GetResult();
	
	memcached_return rc = memcached_set(memc, key.Begin(), key.GetCount(), result.Begin(), result.GetCount(), (time_t)0, (uint32_t)0);
	
	if (rc != MEMCACHED_SUCCESS) {
		LOG("Memcache error: " << String(memcached_strerror(memc, rc)));
		return false;
	} else {
		return true;
	}
}

template <class T>
bool GetMemcached(String key, T& obj) {
	uint32_t flags;
	size_t value_len = 0;
	memcached_return rc;
	char* value = memcached_get(memc, key.Begin(), key.GetCount(), &value_len, &flags, &rc);
	
	if (rc != MEMCACHED_SUCCESS) {
		LOG("Memcache error: " << String(memcached_strerror(memc, rc)));
		if (value) free(value);
		return false;
	} else {
		if (value) {
			MemStream mem(value, value_len);
			mem.Seek(0);
			mem.SetLoading();
			mem % obj;
			free(value);
			return true;
		}
		else return false;
	}
}

bool ClearMemcached(String key);

}

#endif
