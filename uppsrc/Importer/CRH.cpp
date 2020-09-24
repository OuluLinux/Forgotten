#include "Importer.h"


void ImportCrh(String path, Stream& content) {
	String tmp_dir = ConfigFile("tmp");
	RealizeDirectory(tmp_dir);
	
	union {
		byte mb[4];
		uint32 magic;
	};
	mb[0] = 'M';
	mb[1] = 'D';
	mb[2] = 'm';
	mb[3] = 'd';
	
	uint32 cmagic;
	content.Get(&cmagic, sizeof(uint32));
	if (cmagic != magic) {
		COUT("Not correct file magic");
		return;
	}
	
	content.Seek(0x7A); // INDEX begin;
	
	struct File : Moveable<File> {
		String name;
		int offset, size;
		String data;
	};
	Vector<File> files;
	
	while (!content.IsEof()) {
		int64 pos = content.GetPos();
		char entry[0xE];
		content.Get(entry, 0xD);
		entry[0xD] = 0;
		if (entry[0] == 'M' && entry[1] == 'D' && entry[2] == 'm' && entry[3] == 'd') {
			content.Seek(pos);
			break;
		}
		
		int offset;
		content.Get(&offset, sizeof(offset));
		
		String entry_str(entry);
		COUT(files.GetCount() << ": " << entry_str << " (" << offset << ")");
		
		File& f = files.Add();
		f.name = TrimBoth(entry_str);
		f.offset = offset;
		f.size = -1;
	}
	COUT("Found " << files.GetCount() << " in index");
	
	if (files.IsEmpty())
		return;
	
	struct FileHeader {
		byte magic[4];
		byte pad[0x30-0xA];
		char name[0xD];
		char dir[0x50-0xD];
		
		void Fix() {name[0xD-1] = 0; dir[0x50-0xD-1] = 0;}
		bool Check() const {return magic[0] == 'M' && magic[1] == 'D' && magic[2] == 'm' && magic[3] == 'd';}
	};
	
	#define FILE_HEADER (0x30 - 6)
	int offset_diff = content.GetPos() - files[0].offset;
	int prev_offset = content.GetSize();
	for(int i = files.GetCount()-1; i >= 0; i--) {
		File& f = files[i];
		f.size = prev_offset - f.offset - sizeof(FileHeader);
		ASSERT(f.size >= 0);
		prev_offset = f.offset;
	}
	
	for(File& f: files) {
		int exp_pos = f.offset + offset_diff;
		if (exp_pos != content.GetPos()) {
			COUT("Unexpected position: " << exp_pos << " != " << content.GetPos());
			break;
		}
		
		FileHeader header;
		content.Get(&header, sizeof(header));
		if (!header.Check()) {
			COUT("Unexpected file size");
			break;
		}
		header.Fix();
		
		int dir_first = header.dir[0];
		
		String entry_str(TrimBoth(String(header.name)));
		String dir_str(TrimBoth(String(header.dir)));
		
		if (entry_str != f.name) {
			COUT("File name mismatch: " << entry_str << " != " << f.name);
			break;
		}
		
		if (dir_str.GetCount()) {
			COUT("Dir: " << dir_str);
		}
		
		COUT("Reading " << f.name << " (" << f.size << ") at " << content.GetPos());
		
		f.data = content.Get(f.size);
		
		
		String file = AppendFileName(tmp_dir, entry_str);
		FileOut fout(file);
		fout << f.data;
	}
	
	COUT("Dumped to: " << tmp_dir);
	
	COUT("Reading ready");
}
