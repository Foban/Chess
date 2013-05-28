#ifndef FIGURA_H_INCLUDED
#define FIGURA_H_INCLUDED

#include "common.h"

class Figura
{
public:
    Figura() {};
    virtual ~Figura() {};
    virtual char* give_color()=0;
    virtual bool give_m_color()=0;
    virtual symbol give_type()=0;
    virtual bool go_to(int**, Position, Position)=0;
};

#endif // FIGURA_H_INCLUDED
