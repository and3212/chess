//
// Created by and3212 on 1/2/17.
//

#ifndef CHESS_DEBUGTOOLS_HPP
#define CHESS_DEBUGTOOLS_HPP

#include "string"   //TODO remove this after debug
class debugTools {
public:
    static int charToCoords(char x);
    static int intToCoords(int x);
    static char intToChar(int x);
    static int charGrabber(std::string x);
    static int intGrabber(std::string x);
};


#endif //CHESS_DEBUGTOOLS_HPP
