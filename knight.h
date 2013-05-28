#ifndef KNIGHT_H_INCLUDED
#define KNIGHT_H_INCLUDED

#include "common.h"
#include "figura.h"

class Knight: public Figura
{
public:
    Knight(bool);
    ~Knight() {};
    char* give_color();
    bool give_m_color();
    symbol give_type();
    bool go_to(int**,Position, Position);
private:
    bool m_color;
    char* color;
    symbol type;
};
#endif // KNIGHT_H_INCLUDED
