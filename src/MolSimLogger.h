
#pragma once

#include "spdlog/spdlog.h"
/**
 * @brief class to provide wrapper functions for accessing the global logger with the same name
 */
class MolSimLogger {

private:
    /**
     * @brief static variable for saving pointer to logger for performance reasons
     * @see https://github.com/gabime/spdlog/wiki/2.-Creating-loggers#creating-multiple-file-loggers-with-the-same-output-file
     */
    //inspired by: https://stackoverflow.com/q/73744273
    static std::shared_ptr<spdlog::logger> loggerMolSim;

public:
    /**
     * @brief function to init the logger. A logger with name MolSimLogger is created and registered globally
     *
     * @warning this function or init_test() has to be called before any other function of this class is called
     */
    static void init();

    /**
     * @brief function to init the logger, A logger with MolSimLogger is created and registered globally, it is specifically
     * designed for test, as log_level is set to debug
     *
     * @warning this function or init() has to be called before using the lgger
     */
    static void init_test();

    /**
     * @brief function to access the global logger
     * @return shared pointer pointing to the global logger MolSimLogger
     */
    static std::shared_ptr<spdlog::logger>& logger();

    /**
     * @brief Wrapper function to log information for log_level info
     * @param fmt format string
     * @param args arguments for format string
     */
    template<class ...Args>
    static void logInfo(fmt::format_string<Args...> fmt, Args &&... args) {
        loggerMolSim->info(fmt, std::forward<Args>(args)...);
    }

    /**
     *
     * @brief Wrapper funtion to log information for log_level trace
     * @param fmt format string
     * @param args arguments for format string
     */
    template<class... Args>
    static void logTrace(fmt::format_string<Args...> fmt, Args &&... args) {
        loggerMolSim->trace(fmt, std::forward<Args>(args)...);
    }

    /**
     *
     * @brief Wrapper function to log information for log_level debug
     * @param fmt format string
     * @param args arguments for format string
     */
    template<class... Args>
    static void logDebug(fmt::format_string<Args...> fmt, Args &&... args) {
        loggerMolSim->debug(fmt, std::forward<Args>(args)...);
    }

    /**
     *
     * @brief Wrapper function to log information for log_level error
     * @param fmt format string
     * @param args arguments for format string
     */
    template<class... Args>
    static void logError(fmt::format_string<Args...> fmt, Args &&... args) {
        loggerMolSim->error(fmt, std::forward<Args>(args)...);
    }

    /**
     *
     * @brief Wrapper function to log information for log_level critical
     * @param fmt format string
     * @param args arguments for format string
     */
    template<class... Args>
    static void logCritical(fmt::format_string<Args...> fmt, Args &&... args) {
        loggerMolSim->critical(fmt, std::forward<Args>(args)...);
    }

    /**
     *
     * @brief Wrapper function to log warn messages
     * @param fmt format string
     * @param args arguments for format string
     */
    template<class ...Args>
    static void logWarn(fmt::format_string<Args...> fmt, Args &&... args) {
        loggerMolSim->template warn(fmt, std::forward<Args>(args)...);
    }

};

