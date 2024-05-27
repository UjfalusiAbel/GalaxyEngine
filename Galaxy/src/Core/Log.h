#pragma once

#include "Utils.h"
#include "spdlog/spdlog.h"
#include <vector>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace Galaxy
{

    class Logger
    {
    private:
        Reference<spdlog::logger> coreLogger;
        bool isInitialised;
        static Logger* instance;
        Logger();
    public:
        ~Logger();
        static Logger* GetInstance();
        void Init();
        Reference<spdlog::logger>& GetCoreLogger();
        Logger(Logger const&) = delete;
        void operator=(Logger const&) = delete;
    };

#define GX_CORE_TRACE(...)    ::Galaxy::Logger::GetInstance()->GetCoreLogger()->trace(__VA_ARGS__)
#define GX_CORE_INFO(...)     ::Galaxy::Logger::GetInstance()->GetCoreLogger()->info(__VA_ARGS__)
#define GX_CORE_WARN(...)     ::Galaxy::Logger::GetInstance()->GetCoreLogger()->warn(__VA_ARGS__)
#define GX_CORE_ERROR(...)    ::Galaxy::Logger::GetInstance()->GetCoreLogger()->error(__VA_ARGS__)
#define GX_CORE_CRITICAL(...) ::Galaxy::Logger::GetInstance()->GetCoreLogger()->critical(__VA_ARGS__)
}


