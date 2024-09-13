#include "Shader.h"

namespace brayjl {
	Shader::Shader(const std::string& vertexFilepath, const std::string& fragmentFilepath) {
		createShaderProgram(vertexFilepath, fragmentFilepath);
	}

	Shader::~Shader() {
		glDeleteProgram(m_id);
	}

	void Shader::use() const {
		glUseProgram(m_id);
	}

	void Shader::setMat4(const std::string& uniformName, const glm::mat4& mat4) {
		glUniformMatrix4fv(getUniformLocation(uniformName), 1, GL_FALSE, glm::value_ptr(mat4));
	}

	void Shader::setMat3(const std::string& uniformName, const glm::mat3& mat3) {
		glUniformMatrix3fv(getUniformLocation(uniformName), 1, GL_FALSE, glm::value_ptr(mat3));
	}

	void Shader::setMat2(const std::string& uniformName, const glm::mat2& mat2) {
		glUniformMatrix2fv(getUniformLocation(uniformName), 1, GL_FALSE, glm::value_ptr(mat2));
	}

	void Shader::setVec4(const std::string& uniformName, const glm::vec4& vec4) {
		glUniform4fv(getUniformLocation(uniformName), 1, glm::value_ptr(vec4));
	}

	void Shader::setVec3(const std::string& uniformName, const glm::vec3& vec3) {
		glUniform3fv(getUniformLocation(uniformName), 1, glm::value_ptr(vec3));
	}

	void Shader::setVec2(const std::string& uniformName, const glm::vec2& vec2) {
		glUniform2fv(getUniformLocation(uniformName), 1, glm::value_ptr(vec2));
	}

	void Shader::setInt(const std::string& uniformName, const int& integer) {
		glUniform1i(getUniformLocation(uniformName), integer);
	}

	void Shader::setFloat(const std::string& uniformName, const float& flt) {
		glUniform1f(getUniformLocation(uniformName), flt);
	}

	void Shader::setDouble(const std::string& uniformName, const double& dble) {
		glUniform1d(getUniformLocation(uniformName), dble);
	}

	bool Shader::isShaderCompiled(unsigned int& shader) {
		int success;
		char infoLog[512];

		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success) {
			glGetShaderInfoLog(shader, 512, nullptr, infoLog);
			const std::string inf = infoLog;
			Logger::error("GLSL Shader error:\n\t" + inf);
			return false;
		}

		return true;
	}

	bool Shader::isProgramLinked(unsigned int& program) {
		int success;
		char infoLog[512];

		glGetProgramiv(program, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(program, 512, nullptr, infoLog);
			const std::string inf = infoLog;
			Logger::error("Shader program error:\n\t" + inf);

			return false;
		}

		return true;
	}

	unsigned int Shader::getId() const {
		return m_id;
	}

	unsigned int Shader::createShader(const std::string& filepath, const unsigned int& type) {
		std::string shaderCode = Utilities::getFileContents(filepath);
		const char* shaderSource = shaderCode.c_str();

		unsigned int shader = glCreateShader(type);
		glShaderSource(shader, 1, &shaderSource, nullptr);
		glCompileShader(shader);
		if (!isShaderCompiled(shader)) {
			Logger::error("Failed to compile shader.");
		}

		return shader;
	}

	void Shader::createShaderProgram(const std::string& vertexFilepath, const std::string& fragmentFilepath) {
		unsigned int vertexShader = createShader(vertexFilepath, GL_VERTEX_SHADER);
		unsigned int fragmentShader = createShader(fragmentFilepath, GL_FRAGMENT_SHADER);

		m_id = glCreateProgram();
		glAttachShader(m_id, vertexShader);
		glAttachShader(m_id, fragmentShader);
		glLinkProgram(m_id);
		if (!isProgramLinked(m_id)) {
			Logger::error("Failed to link shader program.");
		}

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}

	int Shader::getUniformLocation(const std::string& name) {
		return glGetUniformLocation(m_id, name.c_str());
	}
}