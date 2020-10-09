#ifndef MAKE_CXX
#define MAKE_CXX

#include <new>

#ifndef MAKE_HXX
#include <Make.hxx>
#endif

namespace Make
{
#line 93 "../../src/Com/Make.fog"
    Assembly::Assembly() {};
    
#line 97
    void Assembly::AddPath(Text::String dir)
    {
#line 98
        if (dirs.Find(dir) >= 0)
#line 98
            return;
        dirs.Add(dir);
#line 101
        Container::Index < Text::String > files;
        Util::GetDirectoryFiles(dir, files);
#line 104
        for (int i = 0; i < files.GetCount(); i ++ )
            {
#line 105
                Text::String name = files[i];
                Text::String path = Util::AppendFileName(dir, name);
#line 108
                if (Util::DirectoryExists(path))
                {
#line 109
                    Text::String upp_file = Util::AppendFileName(path, name + ".upp");
                    if (Util::FileExists(upp_file))
                    {
#line 111
                        prj_paths.Add(name, upp_file);
                    }
                }
            }
    };
    
#line 23
    void Assembly::Dump()
    {
        {
            {
#line 23
                Util::Log() << "dirs" << " {" << "\n";
#line 23
                Util::Log().Flush();
            }
#line 23
            ;
#line 23
            for (int i = 0; i < dirs.GetCount(); i ++ )
                {
#line 23
                    Util::Log() << "\t[" << i << "]: " << Text::ToString(dirs[i]) << "\n";
#line 23
                    Util::Log().Flush();
                }
#line 23
            ;
            {
#line 23
                Util::Log() << "}" << "\n";
#line 23
                Util::Log().Flush();
            }
#line 23
            ;
        }
#line 23
        ;
        {
            {
#line 23
                Util::Log() << "prj_paths" << " {" << "\n";
#line 23
                Util::Log().Flush();
            }
#line 23
            ;
#line 23
            for (int i = 0; i < prj_paths.GetCount(); i ++ )
                {
#line 23
                    Util::Log() << "\t[" << i << "]: " << Text::ToString(prj_paths.GetKey(i)) << ": " << Text::ToString(prj_paths[i]) << "\n";
#line 23
                    Util::Log().Flush();
                }
#line 23
            ;
            {
#line 23
                Util::Log() << "}" << "\n";
#line 23
                Util::Log().Flush();
            }
#line 23
            ;
        }
#line 23
        ;
    };
    
#line 261
    Project& AssemblyData::GetProject(Text::String name)
    {
#line 262
        int i = as.FindProject(name);
        Text::String upp_path;
        if (i >= 0)
        {
#line 265
            upp_path = as.GetProjectPath(i);
        }
        else
        {
            {
#line 268
                if (!(as.GetDirectoryCount() > 0))
                {
#line 268
                    Lang::SysBreak("Assertion failed: as.GetDirectoryCount() > 0");
                }
            }
#line 269
            ;
#line 269
            Text::String dir = as.GetDirectory(0);
            upp_path = Util::AppendFileName(dir, name + "/" + name + ".upp");
        }
#line 273
        lock.Enter();
        i = prjs.Find(upp_path);
        if (i == - 1)
        {
            {
#line 276
                Util::Log() << "Load " << upp_path << "\n";
#line 276
                Util::Log().Flush();
            }
#line 277
            ;
#line 277
            i = prjs.GetCount();
            prjs.Add(upp_path).Load(name, upp_path);
        }
        Project & prj = prjs[i];
        lock.Leave();
        return prj;
    };
    
#line 136
    void Project::Clear()
    {
#line 137
        name = "";
#line 137
        path = "";
#line 137
        dir = "";
        uses.Clear();
        files.Clear();
        configs.Clear();
    };
    
#line 57
    void Project::Dump()
    {
        {
            {
#line 57
                Util::Log() << "path = " << Text::ToString(path) << "\n";
#line 57
                Util::Log().Flush();
            }
#line 57
            ;
        }
#line 57
        ;
        {
            {
#line 57
                Util::Log() << "dir = " << Text::ToString(dir) << "\n";
#line 57
                Util::Log().Flush();
            }
#line 57
            ;
        }
#line 57
        ;
        {
            {
#line 57
                Util::Log() << "uses" << " {" << "\n";
#line 57
                Util::Log().Flush();
            }
#line 57
            ;
#line 57
            for (int i = 0; i < uses.GetCount(); i ++ )
                {
#line 57
                    Util::Log() << "\t[" << i << "]: " << Text::ToString(uses[i]) << "\n";
#line 57
                    Util::Log().Flush();
                }
#line 57
            ;
            {
#line 57
                Util::Log() << "}" << "\n";
#line 57
                Util::Log().Flush();
            }
#line 57
            ;
        }
#line 57
        ;
        {
            {
#line 57
                Util::Log() << "files" << " {" << "\n";
#line 57
                Util::Log().Flush();
            }
#line 57
            ;
#line 57
            for (int i = 0; i < files.GetCount(); i ++ )
                {
#line 57
                    Util::Log() << "\t[" << i << "]: " << Text::ToString(files[i]) << "\n";
#line 57
                    Util::Log().Flush();
                }
#line 57
            ;
            {
#line 57
                Util::Log() << "}" << "\n";
#line 57
                Util::Log().Flush();
            }
#line 57
            ;
        }
#line 57
        ;
        {
            {
#line 57
                Util::Log() << "configs" << " {" << "\n";
#line 57
                Util::Log().Flush();
            }
#line 57
            ;
#line 57
            for (int i = 0; i < configs.GetCount(); i ++ )
                {
#line 57
                    Util::Log() << "\t[" << i << "]: " << Text::ToString(configs.GetKey(i)) << ": " << Text::ToString(configs[i]) << "\n";
#line 57
                    Util::Log().Flush();
                }
#line 57
            ;
            {
#line 57
                Util::Log() << "}" << "\n";
#line 57
                Util::Log().Flush();
            }
#line 57
            ;
        }
#line 57
        ;
    };
    
#line 248
    void Project::GetRecursiveUses(Container::Index < Text::String > & idx, AssemblyData& as)
    {
#line 249
        if (idx.Find(name) >= 0)
#line 249
            return;
        idx.Add(name);
        for (int i = 0; i < uses.GetCount(); i ++ )
            {
#line 252
                Project & prj = as.GetProject(uses[i]);
                prj.GetRecursiveUses(idx, as);
            }
    };
    
#line 180
    bool Project::Load(Text::String name, Text::String path)
    {
#line 181
        Clear();
        this -> name = name;
        this -> path = path;
        this -> dir = Util::TrimFileDirectory(path);
#line 186
        if (!Util::FileExists(path))
#line 186
            return false;
#line 188
        Text::String content = Stream::LoadFile(path);
#line 190
        Container::Vector < Text::String > lines;
        lines.Split(content, "\n");
#line 193
        int mode = - 1;
#line 195
        for (int i = 0; i < lines.GetCount(); i ++ )
            {
#line 196
                Text::String line = lines[i];
                bool intended = line.Left(1) == "\t";
#line 199
                line = TrimBoth(line);
                {
#line 200
                    Util::Log() << i << ": " << line << "\n";
#line 200
                    Util::Log().Flush();
                }
#line 201
                ;
                if (line == "uses")
                    mode = USES;
                else 
#line 204
                if (line == "file")
                    mode = FILES;
                else 
#line 206
                if (line == "mainconfig")
                    mode = CONFIGS;
                else 
#line 208
                if (intended)
                {
#line 209
                    if (line.IsEmpty())
#line 209
                        continue;
                    
#line 210
                    line = line.Left(line.GetCount() - 1);
                    int j = line.ReverseFind(" highlight ");
                    if (j >= 0)
                        line = line.Left(j);
#line 215
                    if (line.IsEmpty())
#line 215
                        continue;
                    
#line 216
                    if (mode == USES)
                        uses.FindAdd(line);
                    else 
#line 218
                    if (mode == FILES)
                        files.Add(line);
                    else 
#line 220
                    if (mode == CONFIGS)
                    {
#line 221
                        Text::String key;
                        Text::String value;
                        try
                        {
#line 224
                            int j = line.Find("=");
                            if (j < 0)
                                throw Text::Exc("Not found char '='");
#line 228
                            key = TrimBoth(line.Left(j));
                            if (key.GetCount() >= 2 && key.Left(1) == "\"" && key.Right(1) == "\"")
                                key = key.Mid(1, key.GetCount() - 2);
#line 232
                            value = TrimBoth(line.Mid(j + 1));
                            if (value.GetCount() >= 2 && value.Left(1) == "\"" && value.Right(1) == "\"")
                                value = value.Mid(1, value.GetCount() - 2);
#line 236
                            configs.Add(key, value);
                        }
                        catch (Text::Exc e)
                        {
                            {
#line 239
                                Util::Log() << e << "\n";
#line 239
                                Util::Log().Flush();
                            }
#line 240
                            ;
                        }
                    }
                }
            }
        return true;
    };
    
#line 150
    void Project::Store()
    {
#line 151
        if (path.IsEmpty())
#line 151
            return;
#line 153
        Util::RealizeDirectory(dir);
        {
            {
#line 154
                Util::Log() << "path = " << Text::ToString(path) << "\n";
#line 154
                Util::Log().Flush();
            }
#line 154
            ;
        }
#line 155
        ;
        Stream::FileOut upp_out(path);
#line 158
        if (uses.GetCount())
        {
#line 159
            upp_out << "uses\n";
            for (int i = 0; i < uses.GetCount(); i ++ )
                upp_out << "\t" << uses[i] << CommaOrSemicolon(i < uses.GetCount() - 1) << "\n";
        }
#line 164
        if (files.GetCount())
        {
#line 165
            upp_out << "file\n";
            for (int i = 0; i < files.GetCount(); i ++ )
                upp_out << "\t" << files[i] << CommaOrSemicolon(i < files.GetCount() - 1) << "\n";
        }
#line 170
        if (configs.GetCount())
        {
#line 171
            upp_out << "mainconfig\n";
            for (int i = 0; i < configs.GetCount(); i ++ )
                upp_out << "\t\"" << configs.GetKey(i) << "\" = \"" << configs[i] << "\"" << CommaOrSemicolon(i < configs.GetCount() - 1) << "\n";
        }
    };
    
};

#endif
