#include "Logger.h"

namespace Utils
{
ErrorLogger& ErrorLogger::getInstance()
{
  static ErrorLogger _instance;

  return _instance;
}

void ErrorLogger::setConsoleOnly()
{
  getInstance().m_canWriteToFile = false;
}

void ErrorLogger::log(const std::string& logString)
{
  auto        currentTime = std::chrono::system_clock::now();
  std::time_t now         = std::chrono::system_clock::to_time_t(currentTime);

  std::string output;
  output = output + strtok(ctime(&now), "\n") + logString + "\n";

  if (!m_canWriteToFile)
  {
    std::cout << output;
    return;
  }

  m_file.open(m_filename, std::ios::app);

  if (!m_file)
  {
    std::cout << output;
    setConsoleOnly();
    return;
  }
  m_file << output;
  m_file.close();
}

ErrorLogger::ErrorLogger() : m_filename("output.log"), m_file(), m_canWriteToFile(false)
{
  m_file.open(m_filename, std::ios::out);
  if (!m_file)
  {
    std::cout << "Failed to open " << m_filename << "\n";
  }

  m_canWriteToFile = true;
  m_file.close();
}

ErrorLogger::~ErrorLogger()
{
  if (m_file.is_open())
  {
    m_file.close();
  }
}
} // namespace Utils
