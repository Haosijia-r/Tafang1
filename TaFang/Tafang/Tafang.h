#ifndef TAFANG_H
#define TAFANG_H

#include <QWidget>
#include <QKeyEvent>
#include <QMouseEvent>

class Object: public QWidget
{
public:
    Object(QWidget *parent = 0);
    void initGame();

protected:
    //void paintEvent(QPaintEvent *);
    //void timerEvent(QTimerEvent *);
    //void mousePressEvent(QMouseEvent *event);
    //void mouseMoveEvent(QMouseEvent *event);
    //void mouseReleaseEvent(QMouseEvent *event);

private:

    void doDrawing();
    void move();
    void attack();
    void gameOver(QPainter &);

    static const int DELAY = 140;

    bool inGame;
};










#endif // TAFANG_H
