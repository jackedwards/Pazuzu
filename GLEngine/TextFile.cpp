#include "TextFile.hpp"

TextFile::TextFile()
{

}

TextFile::TextFile(std::string path)
{
	m_path = path;
	Load(m_path);
}

TextFile::~TextFile()
{

}

void TextFile::Load(std::string path)
{
	std::string line;
	std::ifstream file(path);

	if (file.is_open())
	{
		while (getline(file, line))
		{
			this->m_lines.push_back(line);
		}
	}
	else
	{
		std::cout << "File: " + path + " could not be opened.\n";
	}

	file.close();

	LoadPairs();
}

void TextFile::Save()
{
	std::ofstream file(m_path);

	if (file.is_open())
	{
		for (auto& kv : m_pairs)
		{
			file << kv.first << "=" << kv.second << '\n';
		}
	}

	file.close();
}

void TextFile::LoadPairs()
{
	for (std::string line : m_lines)
	{
		int lineLen = line.length();

		for (int i = 0; i < lineLen; ++i)
		{
			if (line[i] == '=')
			{
				const int KEY_POS = 0;
				const int VAL_POS = i + 1;
				const int KEY_LEN = i;
				const int VAL_LEN = (lineLen - 1) - i;

				std::string key = line.substr(KEY_POS, KEY_LEN);
				std::string value = line.substr(VAL_POS, VAL_LEN);

				m_pairs[key] = value;
			}
		}
	}
}

std::string TextFile::Get(std::string key)
{
	return m_pairs[key];
}

void TextFile::Set(std::string key, std::string value)
{
	m_pairs[key] = value;
}

void TextFile::PrintAllPairs()
{
	for (auto& kv : m_pairs)
	{
		std::cout << kv.first << ": " << kv.second << '\n';
	}
}