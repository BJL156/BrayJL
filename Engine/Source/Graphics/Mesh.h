#ifndef MESH_H
#define MESH_H

#include <GLAD/glad.h>
#include <GLM/glm.hpp>

#include "Shader.h"

#include <string>
#include <vector>

namespace brayjl {
	struct Vertex {
		glm::vec3 position;
		glm::vec2 normal;
		glm::vec2 texCoords;
	};

	struct Texture {
		unsigned int id;
		std::string type;
		std::string path;
	};

	class Mesh {
	public:
		Mesh(
			std::vector<Vertex> meshVertices,
			std::vector<unsigned int> meshIndices,
			std::vector<Texture> meshTextures
		);

		void draw(Shader& shader);

		std::vector<Vertex> vertices;
		std::vector<unsigned int> indices;
		std::vector<Texture> textures;
	private:
		void createMeshData();

		unsigned int m_vao, m_vbo, m_ebo;
	};
}

#endif