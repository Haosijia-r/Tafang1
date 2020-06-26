#include "enemy.h"
#include "waypoint.h"
#include "window.h"

#include <QPainter>
#include <QVector2D>
#include <QPainter>

Enemy::Enemy(WayPoint *startWayPoint,Window *game,const QPixmap &sprite)
            :QObject(0),
             pos(startWayPoint->pos()),
             _game(game),
             destinationWayPoint(startWayPoint->nextWayPoint()),
             _sprite(sprite)
{
    Hp=50;
    speed=3.5;
    attackRange=180;

    rotation=0.0;
    active=false;

}

void Enemy::draw(QPainter *painter)
{
    if(!active) return;

    painter->save();
    static const QPoint offsetPoint(-45,-70);
    painter->translate(pos);
    painter->rotate(rotation);
    painter->drawPixmap(offsetPoint,_sprite);//绘制敌人
    painter->restore();

    painter->save();
    painter->setPen(Qt::red);
    painter->drawEllipse(pos.x()-80,pos.y()-90,attackRange,attackRange);//绘制敌人光圈
    painter->restore();

}



void Enemy::move()
{
    if(!active) return;

    if(Window::collision(pos,1,destinationWayPoint->pos(),1))
    {
        if (destinationWayPoint->nextWayPoint())
        {
            pos = destinationWayPoint->pos();
            destinationWayPoint = destinationWayPoint->nextWayPoint();
        }

        else
        {
            _game->removeEnemy(this);
            _game->Lose() ;
            return;
        }

    }

    QPoint targetPoint = destinationWayPoint->pos();
    double movementSpeed = speed ;

    //向量标准化
    QVector2D normalized(targetPoint - pos);
    normalized.normalize( );
    pos = pos + normalized.toPoint() * movementSpeed;

}

void Enemy::Active()
{
    active=true;
}

QPoint Enemy::getpos()
{
    return pos;
}

int Enemy::getrange()
{
    return attackRange;
}

bool Enemy::e_hurt()
{
    Hp-=10;
    if(Hp<=0)
    {
        _game->removeEnemy(this);
        return false;
    }
    return true;
}

void Enemy::e_slow()
{
    speed-=0.2;
}

bool Enemy::up()
{
    return false;
}
