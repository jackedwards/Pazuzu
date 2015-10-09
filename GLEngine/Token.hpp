#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>

enum TokenType
{
	OpeningTagStart,
	ClosingTagStart,
	TagEnd,
	TagName,
	TagContent,
	AttributeName,
	AttributeContent,
	EqualSign,
	DoubleQuote,
};

class Token
{
public:
	std::string m_content;
	TokenType m_type;

public:
	Token();
	Token(std::string content, TokenType type);
};

#endif