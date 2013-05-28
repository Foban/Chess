#ifndef ROOK_H_INCLUDED
#define ROOK_H_INCLUDED

#include "common.h"
#include "figura.h"

class Rook: public Figura
{
public:
    Rook(bool);
    ~Rook() {};
    char* give_color();
    bool give_m_color();
    symbol give_type();
    bool go_to(int**,Position,Position);
private:
    bool m_color;
    char* color;
    symbol type;
};

#endif // ROOK_H_INCLUDED
