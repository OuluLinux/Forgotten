/*!$@FOG@$!
 *	Generated at Thu Sep 24 03:04:12 2020
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

#ifndef MANYCORE_HXX
#define MANYCORE_HXX

#ifndef CORE_HXX
#include <Core.hxx>
#endif

enum GLSLVersion
{
    GLSL150,
    GLSL440
};

class Program
{
public:
#line 23 "../../src/ManyCore/Program.fog"
    bool m_InVertexShader;
    bool m_InFragmentShader;
#line 26
    bool m_Bound;
#line 28
    GLSLVersion m_Version;
    bool m_GL_ARB_explicit_attrib_location;
    bool m_GL_ARB_explicit_uniform_location;
    bool m_GL_ARB_shading_language_420pack;
    
public:
    Program(GLSLVersion version = GLSL440);
#line 38
    inline ~Program();
};

namespace ManyCore
{
};

#line 38
inline Program::~Program() {};

#endif
