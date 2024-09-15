#ifndef MODEL_H
#define MODEL_H

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <stb/stb_image.h>

#include "Core/Logger.h"
#include "Shader.h"
#include "Mesh.h"

#include <vector>
#include <string>
#include <string>
#include <iostream>

namespace brayjl {
	unsigned int textureFromFile(const char* path, const std::string& directory, bool gamma);

	class Model {
	public:
		Model() = default;
		Model(const std::string& filepath);

		void draw(Shader& shader);

		std::string getFilepath() const;
	private:
		void loadModel(std::string path);
		void processNode(aiNode* node, const aiScene* scene);
		Mesh processMesh(aiMesh* mesh, const aiScene* scene);
		std::vector<Texture> loadMaterialTextures(aiMaterial* mat, aiTextureType type, std::string typeName, bool gamma);

		std::vector<Mesh> m_meshes;
		std::string m_directory;

		std::vector<Texture> m_texturesLoaded;

		std::string m_filepath;
	};
}

#endif