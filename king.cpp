#include "king.h"

King::King(bool cl):
    m_color(cl),hodil(false)
{
    if(!m_color)
        color = "\x1b[30m";
    else
        color = "\x1b[36m";
    type = KING;
}

King::King(bool cl, bool hod):
    m_color(cl),hodil(hod)
{
    if(!m_color)
        color = "\x1b[30m";
    else
        color = "\x1b[36m";
    type = KING;
}

char* King::give_color()
{
    return color;
}
bool King::give_m_color()
{
    return m_color;
}
symbol King::give_type()
{
    return type;
}
bool King::go_to(int **mask,Position _old, Position _new)
{
    if(_new.x - _old.x == -1 )
    {
        if((_old.y-_new.y >= -1 && _old.y-_new.y <= 1) && mask[_new.y][_new.x]) return true;
    }
    else if(_new.x - _old.x == 0 )
    {
        if((_old.y-_new.y == -1 || _old.y-_new.y == 1) && mask[_new.y][_new.x]) return true;
    }
    else if(_new.x - _old.x == 1 )
    {
        if((_old.y-_new.y >= -1 && _old.y-_new.y <= 1) && mask[_new.y][_new.x]) return true;
    }
    return false;
}
