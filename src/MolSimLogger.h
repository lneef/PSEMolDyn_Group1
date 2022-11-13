//
// Created by lukas on 13.11.22.
//

#pragma once
#include "spdlog/spdlog.h"

namespace MolSimLogger{
    void init();

    std::shared_ptr<spdlog::logger> logger();

    template<class ...Args>
    void logInfo(fmt::format_string<Args...> fmt, Args&&... args){
        spdlog::get("MolSimLogger")-> info(fmt, std::forward<Args>(args)...);
    }

    template<class... Args>
    void logTrace(fmt::format_string<Args...> fmt, Args&&... args ){
        spdlog::get("MolSimLogger") -> trace(fmt, std::forward<Args>(args)...);
    }

    template<class... Args>
    void logDebug(fmt::format_string<Args...> fmt, Args&&... args ){
        spdlog::get("MolSimLogger") -> debug(fmt, std::forward<Args>(args)...);
    }

    template<class... Args>
    void logError(fmt::format_string<Args...> fmt, Args&&... args ) {
        spdlog::get("MolSimLogger")->error(fmt, std::forward<Args>(args)...);
    }

    template<class... Args>
    void logCritical(fmt::format_string<Args...> fmt, Args&&... args ) {
        spdlog::get("MolSimLogger")->critical(fmt, std::forward<Args>(args)...);
    }

    template<class ...Args>
    void logWarn(fmt::format_string<Args...> fmt, Args&&... args ){
        spdlog::get("MolSimLogger")->template warn(fmt, std::forward<Args>(args)...);
    }
}

