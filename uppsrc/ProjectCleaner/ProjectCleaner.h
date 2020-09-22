#ifndef _ProjectCleaner_ProjectCleaner_h_
#define _ProjectCleaner_ProjectCleaner_h_

#include <CoreLib/CoreLib.h>
using namespace Upp;

#define LAYOUTFILE <ProjectCleaner/ProjectCleaner.lay>
#include <CtrlCore/lay.h>



class ProjectCleaner : public WithMainLayout<TopWindow> {
	String assembly_dir, prj_name;
	UppAssembly ass;
	UppAssemblyData ass_data;
	
public:
	typedef ProjectCleaner CLASSNAME;
	ProjectCleaner();
	
	
	bool Init(String assembly_dir, String prj_name);
	
	
};

#endif
