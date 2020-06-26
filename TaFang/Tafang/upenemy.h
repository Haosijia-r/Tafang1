#ifndef UPENEMY_H
#define UPENEMY_H
#include "enemy.h"
#include <QObject>


class upEnemy:public Enemy
{

public:
    upEnemy(WayPoint *startWayPoint,Window *game,const QPixmap &sprite=QPixmap(":image/image/enemy2.png"));
    ~upEnemy(){};

    void draw(QPainter *painter);
    void move();

    QPoint getpos();
    int getrange();

    bool e_hurt();
    void e_slow();

    bool up();

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

};

#endif // UPENEMY_H
