#ifndef UTILITIES
#define UTILITIES

#include "Logger.h"

#include <fstream>
#include <string>

namespace brayjl {
	class Utilities {
	public:
		static bool getEnableDebugMessages();

		static std::string getFileContents(const std::string& filepath);
	private:
#ifdef DEBUG
		static const bool m_enableDebugMessages = true;
#else
		static const bool m_enableDebugMessages = false;
#endif
	};
}

#endif