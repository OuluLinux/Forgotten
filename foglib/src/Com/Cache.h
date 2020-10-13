#ifndef _Com_Cache_h_
#define _Com_Cache_h_


#include <libmemcached/memcached.h>

namespace Cache::Native {

extern thread_local memcached_st *memc;
extern thread_local memcached_server_st *servers;

void InitMemcachedThread();
bool ClearMemcached(const char* key);
bool SetMemcached(const char* key, const char* value);
bool GetMemcached(const char* key, const char** value);

}

#endif
