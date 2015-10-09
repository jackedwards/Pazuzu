#include "XMLFile.hpp"

XMLFile::XMLFile() {}

XMLFile::XMLFile(std::string path)
{
	Load(path);
}

XMLFile::~XMLFile()
{
	delete m_root;
}

void XMLFile::Load(std::string path)
{
	if (m_contents != "")
		return;

	std::ifstream file(path);

	if (file.is_open())
	{
		std::string line;

		while (getline(file, line))
		{
			line += '\n';
			m_contents += line;
		}
	}
	else
	{
		std::cout << "File: " + path + " could not be opened.\n";
	}

	file.close();
	Lex();
	Parse();
}

void XMLFile::Lex()
{
	std::string token;
	State state = State::OutsideTag;

	for (size_t i = 0; i < m_contents.size(); ++i)
	{
		if (m_contents[i] == '\n' || m_contents[i] == '\t')
			continue;

		token += m_contents[i];

		switch (state)
		{
		case State::OutsideTag:
			if (token == "<")
			{
				if (m_contents[i + 1] == '/')
					continue;

				AddToken(token, TokenType::OpeningTagStart);
				state = State::InsideTag;
			}
			else if (token == "</")
			{
				AddToken(token, TokenType::ClosingTagStart);
				state = State::InsideTag;
			}
			else if (m_contents[i + 1] == '<')
			{
				AddToken(token, TokenType::TagContent);
			}

			break;
		case State::InsideTag:
			if (m_contents[i + 1] == '>' || m_contents[i + 1] == ' ')
			{
				AddToken(token, TokenType::TagName);
			}
			if (token == ">")
			{
				AddToken(token, TokenType::TagEnd);
				state = State::OutsideTag;
			}
			else if (token == " ")
			{
				token = "";
				state = State::InsideAttribute;
			}

			break;
		case State::InsideAttribute:
			if (m_contents[i + 1] == '=')
			{
				AddToken(token, TokenType::AttributeName);
			}
			if (token == "=")
			{
				AddToken(token, TokenType::EqualSign);
			}
			else if (token == "\"")
			{
				AddToken(token, TokenType::DoubleQuote);
				state = State::InsideAttributeContent;
			}

			break;
		case State::InsideAttributeContent:
			if (m_contents[i + 1] == '"')
			{
				AddToken(token, TokenType::AttributeContent);
			}
			if (token == "\"")
			{
				AddToken(token, TokenType::DoubleQuote);
				state = State::InsideTag;
			}

			break;
		}
	}
}

void XMLFile::AddToken(std::string& text, TokenType type)
{
	m_tokens.push_back(Token(text, type));
	text = "";
}

void XMLFile::Parse()
{
	XMLTag* parentTag = m_root;
	XMLTag* currentTag = nullptr;
	std::string attrName;
	std::string attrContent;

	for (Token token : m_tokens)
	{
		switch (token.m_type)
		{
		case TokenType::OpeningTagStart:
			currentTag = new XMLTag();
			parentTag->AddChild(currentTag);
			parentTag = currentTag;

			break;
		case TokenType::ClosingTagStart:
			parentTag = parentTag->mp_parent;

			break;
		case TokenType::TagName:
			if (currentTag->m_name == "")
				currentTag->m_name = token.m_content;

			break;
		case TokenType::TagContent:
			currentTag->m_value = token.m_content;

			break;
		case TokenType::AttributeName:
			attrName = token.m_content;

			break;
		case TokenType::AttributeContent:
			attrContent = token.m_content;
			currentTag->m_attributes[attrName] = attrContent;

			break;
		case TokenType::TagEnd:
			break;
		case TokenType::EqualSign:
			break;
		case TokenType::DoubleQuote:
			break;
		}
	}
}

void XMLFile::PrintData(XMLTag* tag, int depth)
{
	for (XMLTag* tag : tag->m_children)
	{
		std::string spaces = "";
		for (int i = 0; i < depth; ++i)
			spaces += "    ";
		std::cout << spaces;
		std::cout << tag->m_name;
		if (tag->m_value.ToString() != "")
			std::cout << " - " << tag->m_value.ToString();
		if (tag->m_attributes.size() > 0)
			for (auto& kv : tag->m_attributes)
				std::cout << " [" << kv.first << ": " << kv.second.ToString() << "]";
				
		std::cout << '\n';
		PrintData(tag, depth + 1);
	}
}

void XMLFile::PrintAllData()
{
	PrintData(m_root);
}