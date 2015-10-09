#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include <vector>
#include <unordered_map>
#include "Texture.hpp"

class ResourceManager
{
public:
	static std::unordered_map<std::string, Texture*> m_textures;
private:
	static std::vector<std::string> m_texturePaths;

public:
	static void LoadEverything();
	static Texture* GetTexture(std::string name);
	static void LoadTexture(std::string path, std::string name);
	static void LoadTextures();
};

#endif