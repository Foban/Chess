#ifndef KING_H_INCLUDED
#define KING_H_INCLUDED

#include "common.h"
#include "figura.h"

class King: public Figura
{
public:
    King(bool);
    King(bool,bool);
    ~King() {};
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

#endif // KING_H_INCLUDED
