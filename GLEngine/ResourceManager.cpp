#include "ResourceManager.hpp"

std::unordered_map<std::string, Texture*> ResourceManager::m_textures;
std::vector<std::string> ResourceManager::m_texturePaths;
XMLFile ResourceManager::m_resourceInfo;

ResourceManager::ResourceManager() { }

void ResourceManager::LoadEverything()
{
	m_resourceInfo.Load("resources/resources.xml");
	LoadTextures();
}

Texture* ResourceManager::GetTexture(std::string name)
{
	return m_textures[name];
}

void ResourceManager::LoadTexture(std::string path, std::string name)
{
	Texture* p_texture = new Texture();
	p_texture->LoadFromFile(path);
	m_textures[name] = p_texture;
}

void ResourceManager::LoadTextures()
{
	std::vector<XMLTag*> tags = m_resourceInfo.m_root->GetFirstChild("Resources")->GetChildren("Texture");

	for (XMLTag* tag : tags)
	{
		LoadTexture(tag->m_attributes["path"].ToString(), tag->m_attributes["name"].ToString());
	}
}
