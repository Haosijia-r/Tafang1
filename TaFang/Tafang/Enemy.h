#ifndef ENEMY_H
#define ENEMY_H

#include <QObject>
#include"waypoint.h"
#include "window.h"
#include <mainwindow.h>
#include <QPainter>

class Window;
class Enemy : public QObject
{
    Q_OBJECT
public:
    Enemy(WayPoint *startWayPoint,Window *game, const QPixmap &sprite=QPixmap(":image/image/enemy1.png"));
    Enemy();
    virtual ~Enemy(){};//虚析构函数

    virtual void draw(QPainter *painter);
    virtual void move();

    virtual QPoint getpos();
    virtual int getrange();

    virtual bool e_hurt();
    virtual void e_slow();

    virtual bool up();

public slots:
    virtual void Active();

private:
    QPoint pos;
    int Hp;//生命值
    int attackRange;//攻击范围
    double speed;
    double rotation;//转向

    bool active;
    Window *_game;
    WayPoint *destinationWayPoint;
    QPixmap _sprite;

signals:

};

#endif // ENEMY_H
