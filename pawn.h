#ifndef PAWN_H_INCLUDED
#define PAWN_H_INCLUDED

#include "common.h"
#include "figura.h"

class Pawn: public Figura
{
public:
    Pawn(bool);
    Pawn(bool,bool);
    ~Pawn() {};
    char* give_color();
    bool give_m_color();
    symbol give_type();
    bool go_to(int**, Position, Position);
private:
    bool m_color;
    char* color;
    symbol type;
    bool hodil;
};

#endif // PAWN_H_INCLUDED
