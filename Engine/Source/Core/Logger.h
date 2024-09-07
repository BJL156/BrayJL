#ifndef LOGGER_H
#define LOGGER_H

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include <stdexcept>
#include <string>
#include <memory>

namespace brayjl {
	class Logger {
	public:
		static void initialize();

		static void info(const std::string& message);
		static void warn(const std::string& message);
		static void error(const std::string& message);
	private:
		static std::shared_ptr<spdlog::logger> m_logger;
	};
}

#endif