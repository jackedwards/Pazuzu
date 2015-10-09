#ifndef XMLTAG_HPP
#define XMLTAG_HPP

#include <string>
#include <vector>
#include <unordered_map>
#include "XMLValue.hpp"

class XMLTag
{
public:
	std::string m_name;
	XMLValue m_value;
	std::unordered_map<std::string, XMLValue> m_attributes;
	XMLTag* mp_parent;
	std::vector<XMLTag*> m_children;

public:
	XMLTag();
	XMLTag(std::string name);
	~XMLTag();
	void AddChild(XMLTag* tag);
	XMLTag* GetFirstChild();
	XMLTag* GetFirstChild(std::string name);
	std::vector<XMLTag*> GetChildren(std::string name);
};

#endif