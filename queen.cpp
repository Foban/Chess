#include "queen.h"

Queen::Queen(bool cl):
    m_color(cl)
{
    if(!m_color)
        color = "\x1b[30m";
    else
        color = "\x1b[36m";
    type = QUEEN;
}


char* Queen::give_color()
{
    return color;
}
bool Queen::give_m_color()
{
    return m_color;
}
symbol Queen::give_type()
{
    return type;
}

bool Queen::go_to(int **mask, Position _old, Position _new)
{
    int x = _old.x-_new.x, y = _old.y-_new.y;
    if(x &&(x == y || x == -y))
    {
        for(int i = 0,p=0; abs(i)!=abs(x)-1;)
        {
            if(x>0) --i;
            else ++i;
            if(y>0) --p;
            else ++p;
            if(mask[_old.y+p][_old.x+i] != 1) return false;
        }
        if(mask[_new.y][_new.x]==0) return false;
        return true;
    }
    if(!x && y)
    {
        for(int i = 0; abs(i)!=abs(y)-1;)
        {
            if(y>0)--i;
            else ++i;
            if(mask[_old.y+i][_old.x] != 1) return false;
        }
        if(mask[_new.y][_new.x] == 0) return false;
        return true;
    }
    else if (!y && x)
    {
        for(int i = 0; abs(i)!=abs(x)-1;)
        {
            if(x>0)--i;
            else ++i;
            if(mask[_old.y][_old.x+i] != 1) return false;
        }
        if(mask[_new.y][_new.x] == 0) return false;
        return true;
    }
    else
        return false;
}
