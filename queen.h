#ifndef QUEEN_H_INCLUDED
#define QUEEN_H_INCLUDED

#include "common.h"
#include "figura.h"

class Queen: public Figura
{
public:
    Queen(bool);
    ~Queen() {};
    char* give_color();
    bool give_m_color();
    symbol give_type();
    bool go_to(int**,Position, Position);
private:
    bool m_color;
    char* color;
    symbol type;
};

#endif // QUEEN_H_INCLUDED
