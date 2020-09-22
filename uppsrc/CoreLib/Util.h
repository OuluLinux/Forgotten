#ifndef _CoreLib_Util_h_
#define _CoreLib_Util_h_


NAMESPACE_SDK_BEGIN


void GetDirectoryFiles(String dir, Index<String>& files);






class CommandLineArguments {
	static const int max_inputs = 300;
	static const int max_args = 100;
	
	
	struct Arg {
		char key;
		String desc;
		bool has_value;
	};
	
	struct Input {
		char key;
		String value;
	};
	
	Array<Arg> args;
	Array<Input> inputs;
	
public:
	CommandLineArguments() {}
	void AddArg(char key, const char* desc, bool has_value);
	bool Parse();
	void PrintHelp();
	int GetInputCount() const {return inputs.GetCount();}
	const Array<Input>& GetInputs() const {return inputs;}
	
};



NAMESPACE_SDK_END


#endif
