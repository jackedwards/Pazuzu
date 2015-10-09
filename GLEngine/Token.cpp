#include "Token.hpp"

Token::Token()
{

}

Token::Token(std::string content, TokenType type)
{
	m_content = content;
	m_type = type;
}