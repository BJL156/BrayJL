#ifndef RESOURCE_MANAGER
#define RESOURCE_MANAGER

#include "Graphics/Shader.h"
#include "Graphics/Model.h"

#include <string>
#include <map>
#include <memory>

namespace brayjl {
	class ResourceManager {
	public:
		ResourceManager() = default;
		~ResourceManager() = default;

		std::shared_ptr<Shader> loadShader(const std::string& vertexFilepath, const std::string& fragmentFilepath, const std::string& name);
		std::shared_ptr<Shader> getShader(const std::string& name);

		std::shared_ptr<Model> loadModel(const std::string& filepath, const std::string& name);
		std::shared_ptr<Model> getModel(const std::string& name);
	private:
		std::map<std::string, std::shared_ptr<Shader>> m_shaders;
		std::map<std::string, std::shared_ptr<Model>> m_models;
	};
}

#endif