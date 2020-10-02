#ifndef WEBGL_CXX
#define WEBGL_CXX

#include <new>

#ifndef WEBGL_HXX
#include <WebGL.hxx>
#endif

#line 15 "/home/sblo/Forgotten/foglib/examples/WebGL/WebGL.mfog"
int WebGLExample::Main()
{
#line 16
    Program program(GLSLVersion::GLSL440);
#line 18
    String str("Testing 123");
    Console::Put(str);
#line 28
    return 0;
};

#endif
