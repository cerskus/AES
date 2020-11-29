#ifndef AES_AES_H
#define AES_AES_H


#include <string>
#include <bitset>
#include <iostream>

class AES {

public:
    // CONVERTERS
    static unsigned char *Encrypt(unsigned char *message, unsigned char *key);

    static void SubBytes(unsigned char *state);
    static void ShiftRows(unsigned char *state);
    static void AddRoundKey(unsigned char *state, const unsigned char *roundKey);
    static void MixColumns(unsigned char *state);
    static void KeyExpantionCore(unsigned char *in, unsigned char i);


    // CONST
    static const unsigned char sBox[256];
    static const unsigned char multiplyBy2[256];
    static const unsigned char multiplyBy3[256];
    static const unsigned char rcon[256];


    static void PrintHex(unsigned char x);


    static void KeyExpansion(unsigned char *inputKey, unsigned char *expandedKeys);
};


#endif //AES_AES_H
