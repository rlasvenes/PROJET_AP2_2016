#ifndef XOR_ENCRYPTDECRYPTION_H
#define XOR_ENCRYPTDECRYPTION_H

#include "View.h"

class XOR_EncryptDecryption
{
private:

    std::string _output;

public:

    XOR_EncryptDecryption();

    std::string encrypt(std::string toEncrypt);
    std::string decrypt(std::string toDecrypt);
};

#endif // XOR_ENCRYPTDECRYPTION_H
