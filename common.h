#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <iostream>


struct Position
{
    int x,y;
    Position():
        x(0),y(0)
    {};
    Position(int& nx, int& ny):
        x(nx),y(ny)
    {};
};

enum comand {BACKSPACE, ENTER, TAB, SPACE};
enum arrow {UP, LEFT, RIGHT, DOWN, ELSE};
enum symbol {DOUBLE_HORIZONTAL, TOP_LEFT_CORNER, TOP_RIGHT_CORNER, DOWN_RIGHT_CORNER, DOWN_LEFT_CORNER,
             VERTICAL, HORIZONTAL, VERTICAL_AND_HORIZONTAL, DOWN_AND_HORIZONTAL, LEFT_AND_VERTICAL,
             UP_AND_HORIZONTAL, RIGHT_AND_VERTICAL, LIGHT_SHADE, MEDIUM_SHADE, DARK_SHADE, RIGHT_POINTER,
             SMILING_FACE, CURRENCY_SIGN, ASTERISK, HEART, UP_POINTER, FULL_BLOCK, UP_DOWN_ARROW,
             KING,QUEEN,ROOK,BISHOP,KNIGHT,PAWN
            };

int GetKey();
void SetCurrentPos(int, int);
void OutS(symbol sm);
int Arrows();
char *StrTok(char* str, char* stis);

#endif // COMMON_H_INCLUDED
