#include "CoreLib.h"


NAMESPACE_SDK_BEGIN




bool IsDotString(String s) {return s == "." || s == "..";}

void GetDirectoryFiles(String dir, Index<String>& files) {
	files.Clear();
	
	
	#ifdef flagPOSIX
	DIR* dirp = opendir(dir.Begin());
    struct dirent * dp;
    while ((dp = readdir(dirp)) != NULL) {
        if (!IsDotString(dp->d_name))
            files.Add(dp->d_name);
    }
    closedir(dirp);
    #endif
    
    #ifdef flagWIN32
	String pattern = AppendFileName(dir, "*");
    WIN32_FIND_DATA data;
    HANDLE hFind;
    if ((hFind = FindFirstFile(pattern.Begin(), &data)) != INVALID_HANDLE_VALUE) {
        do {
            if (!IsDotString(data.cFileName))
                files.Add(data.cFileName);
        }
        while (FindNextFile(hFind, &data) != 0);
        FindClose(hFind);
    }
    #endif
}








void CommandLineArguments::AddArg(char key, const char* desc, bool has_value) {
	Arg& a = args.Add();
	a.key = key;
	a.desc = desc;
	a.has_value = has_value;
}

bool CommandLineArguments::Parse() {
	const Vector<String>& args = CommandLine();
	
	for(int i = 0; i < args.GetCount(); i++) {
		String arg = args[i];
		
		if (arg.GetCount() < 2) return false;
		
		bool found = false;
		
		if (arg[0] == '-') {
			char key = arg[1];
			if (key) {
				for(int j = 0; j < this->args.GetCount(); j++) {
					Arg& a = this->args[j];
					if (a.key == key) {
						found = true;
						Input& in = inputs.Add();
						in.key = key;
						if (a.has_value) {
							if (i+1 >= args.GetCount()) {
								Cerr() << "No value provided: " << arg << EOL;
								return false;
							}
							in.value = args[i+1];
							i++;
						}
						break;
					}
				}
			}
		}
		
		if (!found) {Cerr() << "Invalid argument: " << arg << endl; return false;}
	}
	
	return true;
}

void CommandLineArguments::PrintHelp() {
	String exe = GetExeFilePath();
	int i = exe.ReverseFind(DIR_SEPS);
	if (i >= 0)
		exe = exe.Mid(i+1);
	
	Cout() << exe << " [-";
	for(int i = 0; i < args.GetCount(); i++)
		if (args[i].has_value)
			Cout() << args[i].key;
	Cout() << " value]";
	
	Cout() << " [-";
	for(int i = 0; i < args.GetCount(); i++)
		if (!args[i].has_value)
			Cout() << args[i].key;
	Cout() << "]" << endl;
	
	for(int i = 0; i < args.GetCount(); i++) {
		Arg& a = args[i];
		Cout() << "\t-" << a.key;
		if (a.has_value)
			Cout() << " value";
		Cout() << ": " << a.desc << endl;
	}
}




NAMESPACE_SDK_END

