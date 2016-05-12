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

    // optimiser : rajouter méthode ici pour écrire dans un fichier (pour y stocker nb pièces, score, etc...)
};

#endif // LOGFILE_H
