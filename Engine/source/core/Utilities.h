#ifndef UTILITIES
#define UTILITIES

namespace brayjl {
	class Utilities {
	public:
		static bool getEnableDebugMessages();
	private:
#ifdef DEBUG
		static const bool m_enableDebugMessages = true;
#else
		static const bool m_enableDebugMessages = false;
#endif
	};
}

#endif