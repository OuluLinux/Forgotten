#include "Importer.h"

void ImportCrh(String path, Stream& content);

void ImportFile(String path) {
	if (!FileExists(path)) {
		COUT("File doesn't exist: " << path);
		return;
	}
	
	COUT("Importing: " << path);
	
	String content = LoadFile(path);
	COUT("File size: " << content.GetCount());
	
	StringStream ss(content);
	
	String ext = ToLower(GetFileExt(path));
	if (ext == ".crh")
		ImportCrh(path, ss);
	else {
		COUT("Unkown file format: " << ext);
	}
}

CONSOLE_APP_MAIN
{
	Vector<String> files;
	const Vector<String>& cmdline = CommandLine();
	for(int i = 0; i < cmdline.GetCount(); i++) {
		String arg = cmdline[i];
		
		files.Add(arg);
	}
	
	for(String file : files)
		ImportFile(file);
	
	
	
}
