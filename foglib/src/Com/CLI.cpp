#include "Com.h"

namespace CLI::Native {

struct TermValue {
	int glyph;
	short fg;
	short bg;
	unsigned char attr;
	char cb;
};

struct TermBuf {
	void* native_arg;
	
	TermValue* values;
	int w;
	int h;
	const char* title;
	
	int event_type;
	int key;
	int mouse_x;
	int mouse_y;
	int mouse_event;
	int mouse_wheel;
	
	
	void (*update_callback)(void*);
	void (*update_native)(void*);
};

void CreateNativeCLI(TermBuf* buf) {
	
	int* i = 0; *i = 0;
	
}


class StdTermCtrl {
	
	
public:
	StdTermCtrl();
	
	void Run();
	void MoveCursor(int x, int y);
	int GetWidth() const;
	int GetHeight() const;
	
	
};

}
