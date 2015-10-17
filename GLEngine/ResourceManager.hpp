#ifndef RESOURCEMANAGER_HPP
#define RESOURCEMANAGER_HPP

#include <vector>
#include <unordered_map>
#include "Texture.hpp"
#include "XMLFile.hpp"
#include "ShaderProgram.hpp"

class ResourceManager
{
private:
	static std::unordered_map<std::string, Texture*> m_textures;
	static std::unordered_map<std::string, ShaderProgram> m_shaderPrograms;
	static std::vector<std::string> m_texturePaths;
	static std::vector<std::string> m_shaderPaths;
	static XMLFile m_resourceInfo;

public:
	static void LoadEverything();
	static Texture* GetTexture(std::string name);
	static ShaderProgram& GetShaderProgram(std::string name);
private:
	ResourceManager();
	static void LoadTexture(std::string name, std::string path);
	static void LoadShaderProgram(std::string name, std::string vertexPath, std::string fragmentPath);
	static void LoadTextures();
	static void LoadShaderPrograms();
};

#endif