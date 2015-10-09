#include "XMLValue.hpp"

XMLValue::XMLValue()
{

}

XMLValue::XMLValue(std::string value)
{
	m_value = value;
}

void XMLValue::SetValue(std::string value)
{
	m_value = value;
}

std::string XMLValue::ToString()
{
	return m_value;
}

int XMLValue::ToInt()
{
	return std::stoi(m_value);
}

float XMLValue::ToFloat()
{
	return std::stof(m_value);
}

bool XMLValue::ToBool()
{
	std::string value = m_value;
	std::transform(value.begin(), value.end(), value.begin(), ::tolower);

	if (value == "true")
		return true;
	else if (value == "false")
		return false;

	return false;
}