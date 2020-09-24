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

#ifndef MANYCORE_CXX
#define MANYCORE_CXX

#ifndef MANYCORE_HXX
#include <ManyCore.hxx>
#endif

#line 34 "../../src/ManyCore/Program.fog"
Program::Program(GLSLVersion version)
:
    m_InVertexShader(false),
    m_InFragmentShader(false),
    m_Bound(false),
    m_Version(version),
    m_GL_ARB_explicit_attrib_location(false),
    m_GL_ARB_explicit_uniform_location(false),
    m_GL_ARB_shading_language_420pack(false)
{};

#endif
