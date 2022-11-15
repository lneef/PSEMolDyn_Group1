
#include "MolSimLogger.h"
#include "spdlog/sinks/basic_file_sink.h"

std::shared_ptr<spdlog::logger> MolSimLogger::loggerMolSim = nullptr;

std::shared_ptr<spdlog::logger> MolSimLogger::logger() {
    return loggerMolSim;
}

void MolSimLogger::init() {
    auto sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs.txt", true);
    auto logger = std::make_shared<spdlog::logger>("MolSimLogger", sink);
    spdlog::register_logger(logger);
    spdlog::set_level(spdlog::level::info);
    loggerMolSim = spdlog::get("MolSimLogger");
}

