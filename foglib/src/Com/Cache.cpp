#include "Com.h"

#if 0

namespace Cache::Native {

thread_local memcached_st *memc = 0;
thread_local memcached_server_st *servers = 0;
const char* memcached_error = 0;

const char* GetLastError() {return memcached_error;}

void InitMemcachedThread() {
	if (memc == NULL) {
		memcached_return rc;
		memc = memcached_create(NULL);
		
		servers = memcached_server_list_append(servers, "localhost", 11211, &rc);
		if (rc != MEMCACHED_SUCCESS) {
			memcached_error = memcached_strerror(memc, rc);
		}
		
		rc = memcached_server_push(memc, servers);
		if (rc != MEMCACHED_SUCCESS) {
			memcached_error = memcached_strerror(memc, rc);
		}
		
		rc = memcached_server_push(memc, servers);
		if (rc != MEMCACHED_SUCCESS) {
			memcached_error = memcached_strerror(memc, rc);
		}
	}
}

void DeinitMemcachedThread() {
	if (memc) {
		memcached_free(memc);
		memc = 0;
	}
}


bool ClearMemcached(const char* key, int keylen) {
	const char* empty_str = "";
	//int keylen = strnlen(key, 1024);
	memcached_return rc = memcached_set(memc, key, keylen, empty_str, 0, (time_t)0, (uint32_t)0);
	
	if (rc != MEMCACHED_SUCCESS) {
		memcached_error = memcached_strerror(memc, rc);
		return false;
	}
	else
		return true;
}

bool SetMemcached(const char* key, int keylen, const char* value, int valuelen) {
	if (!memc)
		InitMemcachedThread();
	
	//int keylen = strnlen(key, 1024);
	//int valuelen = strnlen(value, 100*1024*1024);
	memcached_return rc =
		memcached_set(memc, key, keylen, value, valuelen, (time_t)0, (uint32_t)0);
	
	if (rc != MEMCACHED_SUCCESS) {
		memcached_error = memcached_strerror(memc, rc);
		return false;
	}
	else
		return true;
}

bool GetMemcached(const char* key, int keylen, const char** value) {
	uint32_t flags;
	size_t value_len = 0;
	memcached_return rc;
	
	*value = (const char*)memcached_get(memc, key, keylen, &value_len, &flags, &rc);
	
	if (rc != MEMCACHED_SUCCESS) {
		memcached_error = memcached_strerror(memc, rc);
		if (*value) free((void*)*value);
		return false;
	}
	return true;
}





}


#endif
