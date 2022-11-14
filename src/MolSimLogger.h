//
// Created by lukas on 13.11.22.
//

#pragma once
#include "spdlog/spdlog.h"
/**
 * @brief namespace to provide wrapper functions for accessing the global logger with the same name
 */
namespace MolSimLogger{

    /**
     * @brief function to init the logger. A logger with name MolSimLogger is created and registered globally
     *
     * @warning this function has to be called before any other function of this namespace is called
     */
    void init();

    /**
     * @brief function to access the global logger
     * @return shared pointer pointing to the global logger MolSimLogger
     */
    std::shared_ptr<spdlog::logger> logger();

    /**
     * @brief Wrapper function to log information for log_level info
     * @param fmt format string which is printed
     * @param args arguments for fromat string
     */
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

