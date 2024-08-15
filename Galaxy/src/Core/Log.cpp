#include "Log.hpp"

namespace Galaxy
{
    namespace Core
    {

        Unique<Logger> Logger::instance;

        Logger::Logger() :coreLogger(), isInitialised(false)
        {
        }

        Logger* Logger::GetInstance()
        {
            if (instance == NULL)
            {
                instance.reset(new Logger());
            }

            return instance.get();
        }

        void Logger::Init()
        {
            std::string folderPath = "Logs";
            if (!std::filesystem::exists(folderPath))
            {
                if (std::filesystem::create_directories(folderPath)) 
                {
                    std::cout << "The log folder was missing, created successfully." << std::endl;
                }
                else 
                {
                    std::cerr << "Failed to create the log folder, shutting down logger." << std::endl;
                    return;
                }
            }
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
    }
}