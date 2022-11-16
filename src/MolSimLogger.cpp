
#include "MolSimLogger.h"
#include "spdlog/sinks/basic_file_sink.h"

std::shared_ptr<spdlog::logger> MolSimLogger::loggerMolSim = nullptr;

std::shared_ptr<spdlog::logger> MolSimLogger::logger() {
    return loggerMolSim;
}

void MolSimLogger::init() {
    //sink to write messages to log file
    auto sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs.txt", false);
    auto logger = std::make_shared<spdlog::logger>("MolSimLogger", sink);
    spdlog::register_logger(logger);
    loggerMolSim = spdlog::get("MolSimLogger");
}

void MolSimLogger::init_test(){
    //sink to write messages to log file
    auto sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs.txt", false);
    auto logger = std::make_shared<spdlog::logger>("MolSimLogger", sink);
    spdlog::register_logger(logger);

    //set loglevel on debug for tests
    spdlog::set_level(spdlog::level::debug);
    loggerMolSim = spdlog::get("MolSimLogger");
}


