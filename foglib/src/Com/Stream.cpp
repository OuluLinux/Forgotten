#include "Com.h"

namespace Native {

struct FILE : public ::FILE {};

#ifdef flagPOSIX
inline int fopen_s(FILE **f, const char *name, const char *mode) {
    int ret = 0;
    ASSERT(f);
    *f = (FILE*)fopen(name, mode);
    /* Can't be sure about 1-to-1 mapping of errno and MS' errno_t */
    if (!*f)
        ret = errno;
    return ret;
}
#endif


void FileClose(FILE* s) {
	ASSERT(s);
	fclose(s);
}

void FileOpen(FILE** s, const char* path, bool rw, bool append) {
	ASSERT(s);
	if (!s) return;
	ASSERT(!*s);
	
	const char* flags;
	if (!rw && !append)
		flags = "r";
	else if (!rw && append) {
		ASSERT_(false, "Invalid args: can't do read-only and append at the same time");
		flags = "a+";
	}
	else if (rw && !append)
		flags = "w+";
	else if (rw && append)
		flags = "a+";
	
	fopen_s(s, path, flags);
}

int  FileTell(FILE* s) {
	ASSERT(s);
	return ftell(s);
}

int  FileWrite(const void* mem, int size, int nmemb, FILE* s) {
	ASSERT(s);
	return fwrite(mem, size, nmemb, s);
}

int  FileRead(void* buf, int size, int nmemb, FILE* s) {
	ASSERT(s);
	return fread(buf, size, nmemb, s);
}

void FileSeekSet(FILE* s, int offset) {
	ASSERT(s);
	fseek(s, offset, SEEK_SET);
}

void FileSeekEnd(FILE* s, int offset=0) {
	ASSERT(s);
	fseek(s, offset, SEEK_END);
}

bool IsFileEnd(FILE* s) {
	ASSERT(s);
	return feof(s);
}

void FileFlush(FILE* s) {
	ASSERT(s);
	fflush(s);
}

}
