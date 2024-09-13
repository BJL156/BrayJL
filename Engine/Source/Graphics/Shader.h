#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <spdlog/spdlog.h>

#include "Core/Logger.h"
#include "Core/Utilities.h"

#include <string>

namespace brayjl {
	class Shader {
	public:
		Shader() = default;
		Shader(const std::string& vertexFilepath, const std::string& fragmentFilepath);
		~Shader();

		void use() const;

		void setMat4(const std::string& uniformName, const glm::mat4& mat4);
		void setMat3(const std::string& uniformName, const glm::mat3& mat3);
		void setMat2(const std::string& uniformName, const glm::mat2& mat2);

		void setVec4(const std::string& uniformName, const glm::vec4& vec4);
		void setVec3(const std::string& uniformName, const glm::vec3& vec3);
		void setVec2(const std::string& uniformName, const glm::vec2& vec2);

		void setInt(const std::string& uniformName, const int& integer);
		void setFloat(const std::string& uniformName, const float& flt);
		void setDouble(const std::string& uniformName, const double& dble);

		static bool isShaderCompiled(unsigned int& shader);
		static bool isProgramLinked(unsigned int& program);

		unsigned int getId() const;
	private:
		unsigned int createShader(const std::string& filepath, const unsigned int& type);
		void createShaderProgram(const std::string& vertexFilepath, const std::string& fragmentFilepath);
		int getUniformLocation(const std::string& name);

		unsigned int m_id;
	};
}

#endif