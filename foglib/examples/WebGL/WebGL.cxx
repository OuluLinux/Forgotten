/*!$@FOG@$!
 *	Generated at Wed Sep 23 13:38:23 2020
 *
 *	by fog 0.1.a of 08:09:34 Sep 23 2020
 *
 *	from
 *		../../src/Core/Core.fog
 *		../../src/Core/Stream.fog
 *		../../src/Core/String.fog
 *		../../src/MachCore/MachCore.fog
 *		../../src/MachLib/MachLib.fog
 *		../../src/ManyCore/ManyCore.fog
 *		../../src/ManyCore/Program.fog
 *		../../src/Math/Math.fog
 *		/home/sblo/Forgotten/prototyping/FogLib/examples/WebGL/WebGL.mfog
 */

#ifndef WEBGL_CXX
#define WEBGL_CXX

#ifndef WEBGL_HXX
#include <WebGL.hxx>
#endif

#line 15 "/home/sblo/Forgotten/prototyping/FogLib/examples/WebGL/WebGL.mfog"
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
