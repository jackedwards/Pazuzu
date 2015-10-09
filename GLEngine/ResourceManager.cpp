#include "ResourceManager.hpp"

std::unordered_map<std::string, Texture*> ResourceManager::m_textures;
std::vector<std::string> ResourceManager::m_texturePaths;

void ResourceManager::LoadEverything()
{
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
	LoadTexture("resources/awesomeface.bmp", "awesomeface");
	LoadTexture("resources/bliss.bmp", "bliss");
}