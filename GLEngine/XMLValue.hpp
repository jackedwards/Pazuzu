#ifndef XMLVALUE_HPP
#define XMLVALUE_HPP

#include <string>
#include <algorithm>
#include <cctype>

class XMLValue
{
private:
	std::string m_value;

public:
	XMLValue();
	XMLValue(std::string value);
	void SetValue(std::string value);
	std::string ToString();
	int ToInt();
	float ToFloat();
	bool ToBool();
};

#endif