#pragma once

#include "Utils.hpp"
#include "spdlog/spdlog.h"
#include <vector>
#include <filesystem>
#include <iostream>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace Galaxy
{
    namespace Core
    {
        /// @brief A singleton logger class that provides core logging functionality for the engine
        /// Must be initialised before use using the Init() function. Uses spdlog::logger. 
        class Logger
        {
        private:
            Reference<spdlog::logger> coreLogger;
            bool isInitialised;
            static Unique<Logger> instance;
            Logger();
        public:
            /// @brief Gets a reference to the logger singleton
            /// @return pointer to Logger singleton
            static Logger* GetInstance();
            /// @brief Initialises the logger. Must be called before logging functionality.
            void Init();
            /// @brief Returns a reference to the spdlog::logger shared pointer.
            /// @return Reference<spdlog::logger>&, reference to spdlog::logger inside logger to use for logging
            Reference<spdlog::logger>& GetCoreLogger();
            Logger(Logger const&) = delete;
            void operator=(Logger const&) = delete;
        };


        //Logging macros with 5 log levels: trace, info, warn, error, critical. Pass string to log as parameter
        #define GX_CORE_TRACE(...)    ::Galaxy::Core::Logger::GetInstance()->GetCoreLogger()->trace(__VA_ARGS__)
        #define GX_CORE_INFO(...)     ::Galaxy::Core::Logger::GetInstance()->GetCoreLogger()->info(__VA_ARGS__)
        #define GX_CORE_WARN(...)     ::Galaxy::Core::Logger::GetInstance()->GetCoreLogger()->warn(__VA_ARGS__)
        #define GX_CORE_ERROR(...)    ::Galaxy::Core::Logger::GetInstance()->GetCoreLogger()->error(__VA_ARGS__)
        #define GX_CORE_CRITICAL(...) ::Galaxy::Core::Logger::GetInstance()->GetCoreLogger()->critical(__VA_ARGS__)
    }
}


