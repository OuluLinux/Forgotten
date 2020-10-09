#ifndef MAKE_HXX
#define MAKE_HXX

#include <new>

#ifndef CONCURRENCY_HXX
#include <Concurrency.hxx>
#endif

#ifndef ABSTRACT_HXX
#include <Abstract.hxx>
#endif

namespace Make
{
    enum _anon_24
    {
        USES,
        FILES,
        CONFIGS
    };
    
#line 143 "../../src/Com/Make.fog"
    inline const char *CommaOrSemicolon(bool comma);
    
    class Assembly
    {
#line 9
        Container::Index < Text::String > dirs;
        Container::VectorMap < Text::String, Text::String > prj_paths;
        
    public:
#line 93
        Assembly();
#line 97
        void AddPath(Text::String dir);
#line 23
        void Dump();
#line 20
        inline int FindProject(Text::String name) const;
#line 19
        inline Text::String GetDirectory(int i) const;
#line 18
        inline int GetDirectoryCount() const;
#line 21
        inline Text::String GetProjectPath(int i) const;
    };
};

namespace Make {
class Project;
}

namespace Make
{
    struct AssemblyData
    {
#line 62
        const Assembly& as;
        Container::ArrayMap < Text::String, Project > prjs;
        Concurrency::Mutex lock;
        
#line 67
        inline AssemblyData(const Assembly& as);
#line 261
        Project& GetProject(Text::String name);
    };
    
    class Project
    {
#line 28
        Text::String name;
#line 28
        Text::String path;
#line 28
        Text::String dir;
#line 30
        Container::Index < Text::String > uses;
        Container::Vector < Text::String > files;
        Container::VectorMap < Text::String, Text::String > configs;
        
    public:
#line 46
        inline void AddFile(Text::String filename);
#line 136
        void Clear();
#line 48
        inline void ClearFiles();
#line 57
        void Dump();
#line 42
        inline int GetConfigCount() const;
#line 40
        inline Text::String GetConfigKey(int i) const;
        inline Text::String GetConfigValue(int i) const;
#line 47
        inline Text::String GetDirectory() const;
#line 38
        inline Text::String GetFile(int i) const;
        inline int GetFileCount() const;
#line 43
        inline Text::String GetFilePath() const;
        inline Text::String GetFilePath(int i) const;
        inline Text::String GetName() const;
#line 248
        void GetRecursiveUses(Container::Index < Text::String > & idx, AssemblyData& as);
#line 36
        inline Text::String GetUse(int i) const;
        inline int GetUseCount() const;
#line 180
        bool Load(Text::String name, Text::String path);
#line 54
        inline void Refresh();
#line 49
        inline void RemoveFile(int i);
#line 150
        void Store();
    };
};

namespace Make
{
#line 143
    inline const char *CommaOrSemicolon(bool comma)
    {
#line 144
        if (comma)
            return ",";
        else
            return ";";
    };
    
#line 20
    inline int Assembly::FindProject(Text::String name) const
    {
#line 20
        return prj_paths.Find(name);
    };
    
#line 19
    inline Text::String Assembly::GetDirectory(int i) const
    {
#line 19
        return dirs[i];
    };
    
#line 18
    inline int Assembly::GetDirectoryCount() const
    {
#line 18
        return dirs.GetCount();
    };
    
    inline Text::String Assembly::GetProjectPath(int i) const
    {
#line 21
        return prj_paths[i];
    };
    
#line 67
    inline AssemblyData::AssemblyData(const Assembly& as)
    :
        as(as)
    {};
    
#line 46
    inline void Project::AddFile(Text::String filename)
    {
#line 46
        files.Add(filename);
    };
    
#line 48
    inline void Project::ClearFiles()
    {
#line 48
        files.Clear();
    };
    
#line 42
    inline int Project::GetConfigCount() const
    {
#line 42
        return configs.GetCount();
    };
    
#line 40
    inline Text::String Project::GetConfigKey(int i) const
    {
#line 40
        return configs.GetKey(i);
    };
    
#line 41
    inline Text::String Project::GetConfigValue(int i) const
    {
#line 41
        return configs[i];
    };
    
#line 47
    inline Text::String Project::GetDirectory() const
    {
#line 47
        return dir;
    };
    
#line 38
    inline Text::String Project::GetFile(int i) const
    {
#line 38
        return files[i];
    };
    
#line 39
    inline int Project::GetFileCount() const
    {
#line 39
        return files.GetCount();
    };
    
#line 43
    inline Text::String Project::GetFilePath() const
    {
#line 43
        return path;
    };
    
#line 44
    inline Text::String Project::GetFilePath(int i) const
    {
#line 44
        return Util::AppendFileName(dir, files[i]);
    };
    
#line 45
    inline Text::String Project::GetName() const
    {
#line 45
        return name;
    };
    
#line 36
    inline Text::String Project::GetUse(int i) const
    {
#line 36
        return uses[i];
    };
    
#line 37
    inline int Project::GetUseCount() const
    {
#line 37
        return uses.GetCount();
    };
    
#line 54
    inline void Project::Refresh()
    {
#line 54
        Load(name, path);
    };
    
#line 49
    inline void Project::RemoveFile(int i)
    {
#line 49
        files.Remove(i);
    };
    
};

#endif
