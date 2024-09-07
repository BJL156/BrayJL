#include "Utilities.h"

namespace brayjl {
	bool Utilities::getEnableDebugMessages() {
		return m_enableDebugMessages;
	}

	std::string Utilities::getFileContents(const std::string& filepath) {
		std::ifstream file(filepath);
		if (!file.is_open()) {
			Logger::warn("Failed to read file: " + filepath);
			return std::string();
		}

		std::string contents(
			(std::istreambuf_iterator<char>(file)),
			std::istreambuf_iterator<char>()
		);

		file.close();

		return contents;
	}
}