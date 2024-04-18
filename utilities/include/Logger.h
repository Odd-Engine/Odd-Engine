#ifndef LOGGER_H
#define LOGGER_H

#include <chrono>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string.h>

/**
 * LOG_LEVELS
 * TRACE >= 1
 * DEBUG >= 2
 * WARN >= 3
 * ERROR >= 4
 * FATAL *always*
 */

namespace Utils
{
/**
 * @brief Singleton class for logging errors to file (or if file handling fails, console)
 *
 * @warning This class will go from being a singleton to a static namespace in the future
 */
class ErrorLogger
{
 public:
  /**
   * @brief Gets the instance of the ErrorLogger singleton
   *
   * @return ErrorLogger& a reference to the singleton
   */
  static ErrorLogger& getInstance();

  /**
   * @brief Sets the logger to console-only mode. Irreversible
   */
  static void setConsoleOnly();

  /**
   * @brief logs the given string with a timestamp that looks like "Mon Nov 20
   * 23:28:22 2023"
   *
   * @param logString the string to log
   */
  void log(const std::string& logString);

 private:
  ErrorLogger();

  ~ErrorLogger();

  ErrorLogger(const ErrorLogger& other) = delete;

  void operator=(const ErrorLogger& rhs) = delete;

  std::string  m_filename;       //!< logfile name
  std::fstream m_file;           //!< internal file object
  bool         m_canWriteToFile; //!< true if there has been no issue opening the
                                 //!< file, false if there has been
};

} // namespace Utils

#define COMMON_ENDING(message) \
  std::string("        ") + std::string(message) + ": " + __FILE__ + "[" + std::to_string(__LINE__) + "]"

#if LOG_LEVEL <= 1
/**
 * @brief Logs at log level 1 or below. Use to trace a path through code
 * execution
 *
 * @param message must be able to convert to std::string
 */
#define TRACE(message)                                       \
  {                                                          \
    std::string output = "[TRACE]" + COMMON_ENDING(message); \
    Utils::ErrorLogger::getInstance().log(output);           \
  }
#else
#define TRACE(message) ;
#endif // LOG_LEVEL <= 1

#if LOG_LEVEL <= 2
/**
 * @brief Logs at log level 2 or below. Use for debugging
 *
 * @param message must be able to convert to std::string
 */
#define DEBUG(message)                                       \
  {                                                          \
    std::string output = "[DEBUG]" + COMMON_ENDING(message); \
    Utils::ErrorLogger::getInstance().log(output);           \
  }
#else
#define DEBUG(message) ;
#endif // LOG_LEVEL <= 2

#if LOG_LEVEL <= 3
/**
 * @brief Logs at log level 3 or below. Use when code execution can continue,
 * but will likely be impacted
 *
 * @param message must be able to convert to std::string
 */
#define WARN(message)                                        \
  {                                                          \
    std::string output = "[WARN] " + COMMON_ENDING(message); \
    Utils::ErrorLogger::getInstance().log(output);           \
  }
#else
#define WARN(message) ;
#endif // LOG_LEVEL <= 3

#if LOG_LEVEL <= 4
/**
 * @brief Logs at log level 4 or below. Use when code execution can likely
 * continue, but may be severely affected
 *
 * @param message must be able to convert to std::string
 */
#define ERROR(message)                                       \
  {                                                          \
    std::string output = "[ERROR]" + COMMON_ENDING(message); \
    Utils::ErrorLogger::getInstance().log(output);           \
  }
#else
#define ERROR(message) ;
#endif // LOG_LEVEL <= 4

/**
 * @brief Logs at any log level. Use when code execution cannot continue
 *
 * @param message must be able to convert to std::string
 */
#define FATAL(message)                                       \
  {                                                          \
    std::string output = "[FATAL]" + COMMON_ENDING(message); \
    Utils::ErrorLogger::getInstance().log(output);           \
  }

#endif // LOGGER_H
