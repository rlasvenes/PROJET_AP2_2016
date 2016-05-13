#ifndef LOGFILE_H
#define LOGFILE_H

#include "View.h"
#include <iostream>

class LogFile
{

private:



public:

    LogFile();
    ~LogFile() = default;

    void log(std::string text);
};

#endif // LOGFILE_H
