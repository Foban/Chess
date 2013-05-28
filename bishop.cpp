#include "bishop.h"
#include <math.h>

Bishop::Bishop(bool cl):
    m_color(cl)
{
    if(!m_color)
        color = "\x1b[30m";
    else
        color = "\x1b[36m";
    type = BISHOP;
}

char* Bishop::give_color()
{
    return color;
}
bool Bishop::give_m_color()
{
    return m_color;
}
symbol Bishop::give_type()
{
    return type;
}

bool Bishop::go_to(int **mask,Position _old,Position _new)
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
    else
        return false;
}
