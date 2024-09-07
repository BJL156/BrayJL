#include "Shader.h"

namespace brayjl {
	Shader::Shader(const std::string vertexFilepath, const std::string fragmentFilepath) {
		createShaderProgram(vertexFilepath, fragmentFilepath);
	}

	Shader::~Shader() {
		glDeleteProgram(m_id);
	}

	void Shader::use() {
		glUseProgram(m_id);
	}

	void Shader::setMat4(const std::string& uniformName, glm::mat4& mat4) {
		glUniformMatrix4fv(glGetUniformLocation(m_id, uniformName.c_str()), 1, GL_FALSE, glm::value_ptr(mat4));
	}

	void Shader::setMat3(const std::string& uniformName, glm::mat3& mat3) {
		glUniformMatrix3fv(glGetUniformLocation(m_id, uniformName.c_str()), 1, GL_FALSE, glm::value_ptr(mat3));
	}

	void Shader::setMat2(const std::string& uniformName, glm::mat2& mat2) {
		glUniformMatrix2fv(glGetUniformLocation(m_id, uniformName.c_str()), 1, GL_FALSE, glm::value_ptr(mat2));
	}

	void Shader::setVec4(const std::string& uniformName, glm::vec4& vec4) {
		glUniform4fv(glGetUniformLocation(m_id, uniformName.c_str()), 1, glm::value_ptr(vec4));
	}

	void Shader::setVec3(const std::string& uniformName, glm::vec3& vec3) {
		glUniform3fv(glGetUniformLocation(m_id, uniformName.c_str()), 1, glm::value_ptr(vec3));
	}

	void Shader::setVec2(const std::string& uniformName, glm::vec2& vec2) {
		glUniform2fv(glGetUniformLocation(m_id, uniformName.c_str()), 1, glm::value_ptr(vec2));
	}

	void Shader::setInt(const std::string& uniformName, int& integer) {
		glUniform1i(glGetUniformLocation(m_id, uniformName.c_str()), integer);
	}

	void Shader::setFloat(const std::string& uniformName, float& flt) {
		glUniform1f(glGetUniformLocation(m_id, uniformName.c_str()), flt);
	}

	void Shader::setDouble(const std::string& uniformName, double& dble) {
		glUniform1d(glGetUniformLocation(m_id, uniformName.c_str()), dble);
	}

	bool Shader::isShaderCompiled(unsigned int& shader) {
		int success{ };
		char infoLog[512]{ };

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
		int success{ };
		char infoLog[512]{ };

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

	void Shader::createShaderProgram(const std::string vertexFilepath, const std::string fragmentFilepath) {
		std::string vertexShaderCode = Utilities::getFileContents(vertexFilepath);
		std::string fragmentShaderCode = Utilities::getFileContents(fragmentFilepath);

		const char* vertexShaderSource = vertexShaderCode.c_str();
		unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
		glCompileShader(vertexShader);
		if (!isShaderCompiled(vertexShader)) {
			Logger::error("Failed to compile vertex shader.");
			return;
		}

		const char* fragmentShaderSource = fragmentShaderCode.c_str();
		unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
		glCompileShader(fragmentShader);
		if (!isShaderCompiled(fragmentShader)) {
			Logger::error("Failed to compile fragment shader.");
			return;
		}

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
}