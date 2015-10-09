#ifndef XMLFILE_HPP
#define XMLFILE_HPP

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "XMLTag.hpp"
#include "Token.hpp"

enum State
{
	InsideTag,
	OutsideTag,
	InsideAttribute,
	InsideAttributeContent
};

class XMLFile
{
public:
	std::string m_path;
	std::string m_contents;
	XMLTag* m_root = new XMLTag();
private:
	std::vector<Token> m_tokens;

public:
	XMLFile();
	XMLFile(std::string path);
	~XMLFile();
	void Load(std::string path);
	void PrintAllData();
private:
	void Lex();
	void AddToken(std::string& text, TokenType type);
	void Parse();
	void PrintData(XMLTag* tag, int depth = 0);
};

#endif