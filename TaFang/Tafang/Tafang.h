#ifndef TAFANG_H
#define TAFANG_H

#include <QWidget>
#include <QKeyEvent>
#include <QMouseEvent>

class Object: public QWidget
{
public:
    Object(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);
    void timerEvent(QTimerEvent *);
    void keyPressEvent(QKeyEvent *);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    void initGame();
    void doDrawing();
    void move();
    void attack();
    void gameOver(QPainter &);

    static const int DELAY = 140;

    bool inGame;
};




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


class Turret: public Object
{
public:
    Turret();
    QImage Tu;

private:
    int x,y;
    void doDrawing();
    void move();
    void attack();
};




#endif // TAFANG_H
