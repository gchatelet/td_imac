module chapters;

import std.stdio;
import std.file;
import std.path;
import std.algorithm;
import std.conv;
import std.string;
import std.range;
import std.exception;

import vibe.d;

struct FileEntry {
	immutable int index;
	immutable string name;
	immutable string filename;
	
	this(DirEntry dirEntry) {
		filename = buildNormalizedPath(dirEntry.name);
		string basename = baseName(filename);
		if(dirEntry.isFile)
			basename = stripExtension(basename);
		const auto dashIndex = countUntil(basename,'-');
		if(dashIndex==-1) {
			index = -1;
			name = strip(basename);
		} else {
			index = to!uint(strip(basename[0..dashIndex]));
			name = strip(basename[dashIndex+1..$]);
		}
	}
}

class Chapter {
	immutable FileEntry file;
	Section[] sections;
	string[string] variables;
	
	this(FileEntry fileEntry) {
		file = fileEntry;
		foreach (DirEntry dirEntry; dirEntries(file.filename, SpanMode.shallow)) {
			if(dirEntry.isDir()) continue;
			auto section = new Section(FileEntry(dirEntry));
			if(section.file.index>-1)
				sections~=section;
			else
				variables[section.file.name] = section.render();
		}
		variables["title"] = file.name;
		sort!"a.file.index<b.file.index"(sections);
	}
	
	void render(HTTPServerRequest req, HTTPServerResponse res) {
		res.renderCompat!("td.dt", Section[], "sections", string[string], "variables")(sections, variables);
	}
	
	static Chapter[] readChapters() {
		Chapter[] chapters;
		foreach (DirEntry dirEntry; dirEntries("td", SpanMode.shallow)) {
			if(dirEntry.isFile()) continue;
			chapters ~= new Chapter(FileEntry(dirEntry));
		}
		sort!"a.file.index<b.file.index"(chapters);
		return chapters;
	}
}

class Section {
	FileEntry file;
	string content;
	string[string] variables;
	
	this(FileEntry fileEntry) {
		file = fileEntry;
		immutable string fullContent = readText(file.filename);
		string tmp = fullContent;
		if(skipOver(tmp, sep)) {
			auto triple = findSplit(tmp, newLineSep);
			if(triple[1].empty)
				throw new Exception("'"~file.filename~"' : invalid header");
			variables = extractVariables(triple[0]);
			content = triple[2];
		} else {
			content = fullContent;
		}
		variables["title"] = file.name;
	}
	
	string render() const {
		if(icmp(".md", extension(file.filename)) == 0){
			import std.array;
			auto result = appender!string();
			filterMarkdown(result, content);
			return result.data;
		}
		return content;
	}

private static {	
	string[string] extractVariables(string header) {
		string[string] variables;
		foreach(line ; splitLines(header)) {
			auto triple = findSplit(line, ":");
			const string key = strip(triple[0]);
			const string value = strip(triple[2]);
			enforce(!key.empty, "key must not be empty");
			enforce(!value.empty, "value must not be empty");
			variables[key] = value;
		}
		return variables;
	}

	immutable string newLineSep = "\n---\n";
	immutable string sep = newLineSep[1 .. $];
}
}