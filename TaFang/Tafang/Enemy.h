#ifndef ENEMY_H
#define ENEMY_H

#include "Tafang.h"



class Enemy: public Object
{
public:
    Enemy(int _x=0,int _y=0);
    QImage En;

private:
    int x,y;
    void doDrawing();
    void move();
    void attack();
};

#endif // ENEMY_H
