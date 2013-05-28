#include "chessboard.h"
#include<iostream>
#include<cstdlib>

using namespace std;

ChessBoard::ChessBoard()
{
    for(int i = 0; i < 8; ++i)
        for(int p = 0; p < 8; ++p)
        {
            board[i][p] = 0;
            active_board[i][p] = 0;
        }
    for(int i = 0; i < 8; ++i)
    {
        board[1][i]=new Pawn(false);
        board[6][i]=new Pawn(true);
        active_board[1][i]=new Pawn(false);
        active_board[6][i]=new Pawn(true);
        if(i==0||i==7)
        {
            board[0][i]=new Rook(false);
            board[7][i]=new Rook(true);
            active_board[0][i]=new Rook(false);
            active_board[7][i]=new Rook(true);
        }
        if(i==1||i==6)
        {
            board[0][i]=new Knight(false);
            board[7][i]=new Knight(true);
            active_board[0][i]=new Knight(false);
            active_board[7][i]=new Knight(true);
        }
        if(i==2||i==5)
        {
            board[0][i]=new Bishop(false);
            board[7][i]=new Bishop(true);
            active_board[0][i]=new Bishop(false);
            active_board[7][i]=new Bishop(true);
        }
        if(i==4)
        {
            board[0][i]=new Queen(false);
            board[7][i]=new Queen(true);
            active_board[0][i]=new Queen(false);
            active_board[7][i]=new Queen(true);
        }
        if(i==3)
        {
            board[0][i]=new King(false);
            board[7][i]=new King(true);
            active_board[0][i]=new King(false);
            active_board[7][i]=new King(true);
        }
    }
}

ChessBoard::~ChessBoard()
{
    for(int i = 0; i < 8; ++i)
        for(int p = 0; p < 8; ++p)
        {
            delete board[i][p];
            delete active_board[i][p];
        }

}

void ChessBoard::Play()
{
    bool fl = false;
    while(!fl)
    {
        Drow();
        fl = Hod();
        system("clear");
    }
    Drow();
    fl = Hod();
}

void ChessBoard::Drow()
{

    for(int i = 0; i < 8; ++i)
        cout<<(char)('A'+i);
    for(int i = 0; i < 8; ++i)
    {
        cout<<'\n';
        for(int p = 0; p < 8; ++p)
        {
            if((p+i)%2 == 0)
            {
                cout<<"\x1b[1;44m";
                if(board[i][p])
                {
                    cout<<board[i][p]->give_color();
                    OutS(board[i][p]->give_type());
                    cout<<"\x1b[0m";
                }
                else cout<<" \x1b[0m";
            }
            else
            {
                cout<<"\x1b[1;47m";
                if(board[i][p])
                {
                    cout<<board[i][p]->give_color();
                    OutS(board[i][p]->give_type());
                    cout<<"\x1b[0m";
                }
                else cout<<" \x1b[0m";
            }
        }
        cout<<8-i;
    }
}

bool ChessBoard::Hod()
{
    static int num = 0;
    ++num;
    if(!Status(num%2))
    {
        char wi[2], to_wi[2];
        Position _old,_new;
        bool fl;
        cout << "\n";
        do
        {
            fl = true;
            cin >> wi >> to_wi;
            if( wi[0]<'a' || wi[0]>'h' || to_wi[0]<'a' || to_wi[0]>'h' || wi[1]<'1' || wi[1]>'8' || to_wi[1]<'1' || to_wi[1]>'8')
            {
                fl = false;
                cout << "eror: across the border\n";
            }
            else
            {
                _old.x = wi[0] - 'a';
                _old.y = '8' - wi[1];
                _new.x = to_wi[0] - 'a';
                _new.y = '8' - to_wi[1];
                if(!board[_old.y][_old.x] || board[_old.y][_old.x]->give_m_color()!=num%2)
                {
                    fl = false;
                    cout <<"eror: invalid first position\n";
                }
                else
                {
                    int **mask = make_mask(num%2);
                    if(!board[_old.y][_old.x]->go_to(mask,_old,_new))
                    {
                        fl = false;
                        cout  <<"eror: invalid second position\n";
                    }
                    delete_mask(mask);
                }
            }

        }
        while(!fl);
        delete board[_new.y][_new.x];
        board[_new.y][_new.x] = board[_old.y][_old.x];
        board[_old.y][_old.x] = 0;
        delete active_board[_new.y][_new.x];
        active_board[_new.y][_new.x] = active_board[_old.y][_old.x];
        active_board[_old.y][_old.x] = 0;
        return false;
    }
    return true;
}

bool ChessBoard::Status(bool color)
{
    cout<<"\n\n";
    switch(Checkmate(true))
    {
    case 1:
        if(color!=true)
        {
            return true;
            cout<<"white: checkmate\n";
        }
        else
            cout<<"white: check\n";
        break;
    case 2:
        cout<<"white: checkmate\n";
        return true;
        break;
    }

    switch(Checkmate(false))
    {
    case 1:
        if(color!=false)
        {
            cout<<"black: checkmate\n";
            return true;
        }
        cout<<"black: check\n";
        break;
    case 2:
        cout<<"black: checkmate\n";
        return true;
        break;
    }
    if(color) cout<<"white's move:\n";
    else cout<<"black's move:\n";
    return false;
}


int ChessBoard::Checkmate(bool color)
{
    int **mask = make_mask(!color);
    Figura *buff;
    Position _old, _new;
    if(!Check(color,mask))
    {
        delete_mask(mask);
        return 0;
    }
    else
    {
        delete_mask(mask);
        for(; _old.y < 8; ++_old.y)
        {
            for(; _old.x < 8; ++_old.x)
            {
                if(active_board[_old.y][_old.x] && active_board[_old.y][_old.x]->give_m_color()==color)
                {
                    for(; _new.y < 8; ++_new.y)
                    {
                        for(; _new.x < 8; ++_new.x)
                        {
                            if(active_board[_old.y][_old.x] && active_board[_old.y][_old.x]->go_to(mask,_old,_new))
                            {
                                buff = active_board[_new.y][_new.x];
                                active_board[_new.y][_new.x] = active_board[_old.y][_old.x];
                                active_board[_old.y][_old.x] = 0;
                                mask = make_mask(!color);
                                if(!Check(color,mask))
                                {
                                    active_board[_old.y][_old.x] = active_board[_new.y][_new.x];
                                    active_board[_new.y][_new.x] = buff;
                                    delete_mask(mask);
                                    return 1;
                                }
                                else
                                {
                                    active_board[_old.y][_old.x] = active_board[_new.y][_new.x];
                                    active_board[_new.y][_new.x] = buff;
                                    delete_mask(mask);
                                }
                            }
                        }
                        _new.x = 0;
                    }
                    _new.y = 0;
                }
            }
            _old.x = 0;
        }
        return 2;
    }
}

bool ChessBoard::Check(bool color,int **mask)
{
    Position king,work;
    bool fl = true;
    for(; king.y<8 && fl; ++king.y)
    {
        king.x = 0;
        for(; king.x<8 && fl; ++king.x)
        {
            if(active_board[king.y][king.x] && active_board[king.y][king.x]->give_m_color() == color && active_board[king.y][king.x]->give_type() == KING)
                fl = false;
        }
    }
    --king.x;
    --king.y;
    for(; work.y < 8 ; ++work.y)
    {
        work.x = 0;
        for(; work.x < 8 ; ++work.x)
        {
            if(active_board[work.y][work.x] &&active_board[work.y][work.x]->give_m_color() != color&& active_board[work.y][work.x]->go_to(mask,work,king)) return true;
        }
    }
    return false;
}

int** ChessBoard::make_mask(bool fl)
{
    int **mask;
    mask = new int*[8];
    for(int i = 0; i < 8; ++i)
    {
        mask[i]= new int[8];
        for(int p = 0; p < 8; ++p)
        {
            if(!active_board[i][p])
            {
                mask[i][p]=1;
            }
            else
            {
                if(active_board[i][p]->give_m_color()==fl)
                {
                    mask[i][p]=0;
                }
                else
                {
                    mask[i][p]=2;
                }
            }
        }
    }
    return mask;
}

void ChessBoard::delete_mask(int** mask)
{
    for(int i = 0; i< 8; ++i)
        delete [] mask[i];
    delete [] mask;
}



