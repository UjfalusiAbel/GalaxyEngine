#include "Log.h"

namespace Galaxy
{

    Logger* Logger::instance = nullptr;

    Logger::Logger() :coreLogger()
    {
    }

    Logger* Logger::GetInstance()
    {
        if (instance == NULL)
        {
            instance = new Logger();
        }

        return instance;
    }

    void Logger::Init()
    {
        std::vector<spdlog::sink_ptr> logSinks;
        logSinks.push_back(CreateReference<spdlog::sinks::stdout_color_sink_mt>());
        logSinks.push_back(CreateReference<spdlog::sinks::basic_file_sink_mt>("Logs/Galaxy.log", true));

        logSinks[0]->set_pattern("%^[%T] [%n]: %v%$");
        logSinks[1]->set_pattern("[%T] [%l] [%n]: %v");

        this->coreLogger = CreateReference<spdlog::logger>("GALAXY", begin(logSinks), end(logSinks));
        spdlog::register_logger(this->coreLogger);
        this->coreLogger->set_level(spdlog::level::trace);
        this->coreLogger->flush_on(spdlog::level::trace);
    }

    Reference<spdlog::logger>& Logger::GetCoreLogger()
    {
        return this->coreLogger;
    }

    Logger::~Logger()
    {
        delete instance;
    }

}