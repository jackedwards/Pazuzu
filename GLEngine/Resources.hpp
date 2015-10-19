#ifndef RESOURCES_HPP
#define RESOURCES_HPP

#include <vector>
#include <unordered_map>
#include "Texture.hpp"
#include "XMLFile.hpp"
#include "ShaderProgram.hpp"

class Resources
{
private:
	static std::unordered_map<std::string, Texture*> m_textures;
	static std::unordered_map<std::string, std::shared_ptr<ShaderProgram> > m_shaderPrograms;
	static std::vector<std::string> m_texturePaths;
	static std::vector<std::string> m_shaderPaths;
	static XMLFile m_resourceInfo;

public:
	static void LoadEverything();
	static Texture* GetTexture(const std::string& name);
	static const std::shared_ptr<ShaderProgram>& GetShader(const std::string& name);
private:
	Resources();
	static void LoadTexture(const std::string& name, const std::string& path);
	static void LoadShaderProgram(const std::string& name, const std::string& vertexPath, const std::string& fragmentPath);
	static void LoadTextures();
	static void LoadShaderPrograms();
};

#endif