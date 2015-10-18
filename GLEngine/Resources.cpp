#include "Resources.hpp"

std::unordered_map<std::string, Texture*> Resources::m_textures;
std::unordered_map<std::string, std::shared_ptr<ShaderProgram> > Resources::m_shaderPrograms;
std::vector<std::string> Resources::m_texturePaths;
std::vector<std::string> Resources::m_shaderPaths;
XMLFile Resources::m_resourceInfo;

Resources::Resources() { }

void Resources::LoadEverything()
{
	m_resourceInfo.Load("resources/resources.xml");
	LoadTextures();
	LoadShaderPrograms();
}

Texture* Resources::GetTexture(const std::string& name)
{
	return m_textures[name];
}

const std::shared_ptr<ShaderProgram>& Resources::GetShaderProgram(const std::string& name)
{
	return m_shaderPrograms[name];
}

void Resources::LoadTexture(const std::string& name, const std::string& path)
{
	Texture* texture = new Texture();
	texture->LoadFromFile(path);
	m_textures[name] = texture;
}

void Resources::LoadTextures()
{
	std::vector<XMLTag*> tags = m_resourceInfo.m_root->GetFirstChild("Resources")->GetChildren("Texture");

	for (XMLTag* tag : tags)
	{
		LoadTexture(tag->m_attributes["Name"].ToString(), tag->m_attributes["Path"].ToString());
	}
}

void Resources::LoadShaderProgram(const std::string& name, const std::string& vertexPath, const std::string& fragmentPath)
{
	VertexShader vertexShader(vertexPath);
	FragmentShader fragmentShader(fragmentPath);
	m_shaderPrograms[name] = std::make_shared<ShaderProgram>(vertexShader, fragmentShader);
}

void Resources::LoadShaderPrograms()
{
	std::vector<XMLTag*> tags = m_resourceInfo.m_root->GetFirstChild("Resources")->GetChildren("Shader");

	for (XMLTag* tag : tags)
	{
		LoadShaderProgram(tag->m_attributes["Name"].ToString(), tag->m_attributes["VertexPath"].ToString(), tag->m_attributes["FragmentPath"].ToString());
	}
}
