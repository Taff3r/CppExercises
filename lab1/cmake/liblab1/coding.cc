#include "coding.h"

unsigned char encode(unsigned char c)
{
    // ROT13 
    return c + 13;
}
unsigned char decode(unsigned char c)
{
    return c - 13;
}
