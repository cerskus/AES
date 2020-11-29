#include <iostream>
#include <cstring>
#include "AES.h"

int main() {

    std::string plainTextString;
    std::string key;

    std::cout << "Enter Plain Text: ";
    std::getline(std::cin, plainTextString);

    std::cout << "Enter Key (16): ";
    std::getline(std::cin, key);

    auto* plainText = new unsigned char [plainTextString.length()];
    for(int i = 0; i < plainTextString.length(); i++)
    {
        plainText[i] = plainTextString[i];
    }

    unsigned char keyChar[16];

    for (int i = 0; i < 16; i++){
        keyChar[i] = key[i];
    }


    unsigned char keyExpanded[176];
    AES::KeyExpansion(keyChar, keyExpanded);


    int originalLen = std::strlen((const char*)plainText);
    int lenOfPaddedMessage = originalLen;
    if(lenOfPaddedMessage % 16 != 0)
        lenOfPaddedMessage = (lenOfPaddedMessage / 16 + 1) * 16;

    auto* paddedMessage = new unsigned char [lenOfPaddedMessage];
    for(int i = 0; i < lenOfPaddedMessage; i++)
    {
        if(i >= originalLen) paddedMessage[i] = 0;
        else paddedMessage[i] = plainText[i];
    }


    for(int i = 0; i< lenOfPaddedMessage; i+=16)
    {
        AES::Encrypt(paddedMessage+i, keyExpanded);
    }

    std::cout << "Cipher Text: " << std::endl;
    for(int i = 0; i < lenOfPaddedMessage; i++)
    {
        AES::PrintHex(paddedMessage[i]);
        std::cout<< " ";
    }


    delete[] paddedMessage;
    delete[] plainText;

    return 0;
}
