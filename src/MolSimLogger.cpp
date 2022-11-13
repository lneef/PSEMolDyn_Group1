//
// Created by lukas on 13.11.22.
//


#include "MolSimLogger.h"
#include "spdlog/sinks/basic_file_sink.h"
namespace MolSimLogger{

    std::shared_ptr<spdlog::logger> logger(){
        return spdlog::get("MolSimLogger");
    }

    void init(){
        auto sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs.txt", true);
        auto logger = std::make_shared<spdlog::logger>("MolSimLogger", sink);
        spdlog::register_logger(logger);
    }
}
