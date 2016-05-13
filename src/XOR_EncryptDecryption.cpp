#include "XOR_EncryptDecryption.h"

XOR_EncryptDecryption::XOR_EncryptDecryption()
{

}

std::string XOR_EncryptDecryption::encrypt(std::string toEncrypt)
{

    char key[3] = {'K', 'C', 'Q'};
    std::string _output = toEncrypt;

    for (unsigned int i = 0; i < toEncrypt.size(); i++)
        _output[i] = toEncrypt[i] ^ key[i % (sizeof(key) / sizeof(char))];

    return _output;

}

std::string XOR_EncryptDecryption::decrypt(std::string toDecrypt)
{

    char key[3] = {'K', 'C', 'Q'};
    std::string _output = toDecrypt;

    for (unsigned int i = 0; i < toDecrypt.size(); i++)
        _output[i] = toDecrypt[i] ^ key[i % (sizeof(key) / sizeof(char))];

    return _output;

}
