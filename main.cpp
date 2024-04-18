#include "Logger.h"
#include <iostream>
#include <string>

int main()
{
  Utils::ErrorLogger::setConsoleOnly();
  TRACE("This is a trace message");
  DEBUG("This is a debug message");
  WARN("This is a warn message");
  ERROR("This is an error message");
  FATAL("This is a fatal message");

  return 0;
}