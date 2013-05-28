#ifndef BISHOP_H_INCLUDED
#define BISHOP_H_INCLUDED

#include "common.h"
#include "figura.h"

class Bishop: public Figura
{
public:
    Bishop(bool);
    ~Bishop() {};
    char* give_color();
    bool give_m_color();
    symbol give_type();
    bool go_to(int**, Position,Position);
private:
    bool m_color;
    char* color;
    symbol type;
};

#endif // BISHOP_H_INCLUDED
