#include "pawn.h"
#include <math.h>

Pawn::Pawn(bool cl):
    m_color(cl),hodil(false)
{
    if(!m_color)
        color = "\x1b[30m";
    else
        color = "\x1b[36m";
    type = PAWN;
}

Pawn::Pawn(bool cl, bool hod):
    m_color(cl),hodil(hod)
{
    if(!m_color)
        color = "\x1b[30m";
    else
        color = "\x1b[36m";
    type = PAWN;
}

char* Pawn::give_color()
{
    return color;
}
bool Pawn::give_m_color()
{
    return m_color;
}

symbol Pawn::give_type()
{
    return type;
}

bool Pawn::go_to(int **mask, Position _old, Position _new)
{
    int x = _old.x-_new.x, y = _old.y-_new.y;
    if(!x)
    {
        if(abs(y)==2 && !hodil && mask[_new.y][_new.x]==1 && mask[_old.y-y/2][_old.x]==1)
        {
            hodil = true;
            return true;
        }
        if(abs(y)==1 && mask[_new.y][_new.x] == 1)
        {
            hodil = true;
            return true;
        }
    }
    else if(abs(x)==1 && abs(y)==1 && mask[_new.y][_new.x]==2)
    {
        hodil = true;
        return true;
    }
    return false;
}
