#ifndef TEXTFILE_HPP
#define TEXTFILE_HPP

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <map>

class TextFile
{
private:
	std::string m_path;
	std::vector<std::string> m_lines;
	std::map<std::string, std::string> m_pairs;

public:
	TextFile();
	TextFile(std::string path);
	~TextFile();
	void Load(std::string path);
	void Save();
	std::string Get(std::string key);
	void Set(std::string key, std::string value);
	void PrintAllPairs();
private:
	void LoadPairs();
};

#endif