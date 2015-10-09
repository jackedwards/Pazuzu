#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include <vector>
#include <unordered_map>
#include "Texture.hpp"
#include "XMLFile.hpp"

class ResourceManager
{
private:
	static std::unordered_map<std::string, Texture*> m_textures;
	static std::vector<std::string> m_texturePaths;
	static XMLFile m_resourceInfo;

public:
	static void LoadEverything();
	static Texture* GetTexture(std::string name);
private:
	ResourceManager();
	static void LoadTexture(std::string path, std::string name);
	static void LoadTextures();
};

#endif