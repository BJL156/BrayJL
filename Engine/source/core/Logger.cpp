#include "Logger.h"

namespace brayjl {
	std::shared_ptr<spdlog::logger> Logger::m_logger = nullptr;

	void Logger::initialize() {
		m_logger = spdlog::stdout_color_mt("Engine logger");
	}

	void Logger::info(const std::string& message) {
		if (!m_logger) {
			return;
		}

		m_logger->info(message);
	}

	void Logger::warn(const std::string& message) {
		if (!m_logger) {
			return;
		}

		m_logger->warn(message);
	}

	void Logger::error(const std::string& message) {
		if (!m_logger) {
			return;
		}

		m_logger->error(message);
		throw std::runtime_error(message);
	}
}