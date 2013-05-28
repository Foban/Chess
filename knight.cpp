#include "knight.h"
#include <math.h>

Knight::Knight(bool cl):
    m_color(cl)
{
    if(!m_color)
        color = "\x1b[30m";
    else
        color = "\x1b[36m";
    type = KNIGHT;
}

char* Knight::give_color()
{
    return color;
}
bool Knight::give_m_color()
{
    return m_color;
}
symbol Knight::give_type()
{
    return type;
}

bool Knight::go_to(int **mask, Position _old, Position _new)
{
    int x = _old.x-_new.x, y = _old.y-_new.y;
    if(((abs(x)==2 && abs(y) == 1)||(abs(y)==2 && abs(x) ==1)) && mask[_new.y][_new.x])
    {
        return true;
    }
    else
        return false;
}
