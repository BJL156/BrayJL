#include "ResourceManager.h"

namespace brayjl {
	std::shared_ptr<Shader> ResourceManager::loadShader(const std::string& vertexFilepath, const std::string& fragmentFilepath, const std::string& name) {
		std::shared_ptr<Shader> shader = std::make_shared<Shader>(vertexFilepath, fragmentFilepath);
		m_shaders[name] = shader;

		return shader;
	}

	std::shared_ptr<Shader> ResourceManager::getShader(const std::string& name) {
		return m_shaders.at(name);
	}

	std::shared_ptr<Model> ResourceManager::loadModel(const std::string& filepath, const std::string& name) {
		std::shared_ptr<Model> model = std::make_shared<Model>(filepath);
		m_models[name] = model;

		return model;
	}

	std::shared_ptr<Model> ResourceManager::getModel(const std::string& name) {
		return m_models.at(name);
	}
}