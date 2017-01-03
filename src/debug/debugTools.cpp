//
// Created by and3212 on 1/2/17.
//

#include "debugTools.hpp"

int debugTools::charToCoords(char x){
    switch(x){
        case 'a':
            return 0;
        case 'b':
            return 1;
        case 'c':
            return 2;
        case 'd':
            return 3;
        case 'e':
            return 4;
        case 'f':
            return 5;
        case 'g':
            return 6;
        case 'h':
            return 7;
    }
}

int debugTools::intToCoords(int x){
    return (8 - x);
}

char debugTools::intToChar(int x){
    switch(x){
        case 0:
            return 'A';
        case 1:
            return 'B';
        case 2:
            return 'C';
        case 3:
            return 'D';
        case 4:
            return 'E';
        case 5:
            return 'F';
        case 6:
            return 'G';
        case 7:
            return 'H';
    }
}