#include "LogFile.h"

LogFile::LogFile()
{
}

void LogFile::log(std::string text)
{
    time_t t = time(NULL);
    struct tm *temps = localtime( & t);

    std::cout << "[" << temps->tm_hour << ":"
              << temps->tm_min << ":"
              << temps->tm_sec << "]" << "\t : " << text << std::endl;
}
