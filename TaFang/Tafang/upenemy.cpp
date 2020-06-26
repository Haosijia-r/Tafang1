#include "upenemy.h"
#include "enemy.h"
#include "waypoint.h"
#include <QObject>
#include <QVector2D>

upEnemy::upEnemy(WayPoint *startWayPoint,Window *game,const QPixmap &sprite)
    :Enemy(startWayPoint,game),
     pos(startWayPoint->pos()),
     _game(game),
     destinationWayPoint(startWayPoint->nextWayPoint()),
     _sprite(sprite)
{
    Hp=60;
    speed=4.5;
    attackRange=200;

    rotation=0.0;
    active=false;
}

void upEnemy::draw(QPainter *painter)
{
    if(!active) return;

    painter->save();
    static const QPoint offsetPoint(-45,-70);
    painter->translate(pos);
    painter->rotate(rotation);
    painter->drawPixmap(offsetPoint.x()-50,offsetPoint.y(),_sprite);//绘制敌人
    painter->restore();

    painter->save();
    painter->setPen(Qt::red);
    painter->drawEllipse(pos.x()-100,pos.y()-100,attackRange,attackRange);//绘制敌人光圈
    painter->restore();

}



void upEnemy::move()
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



QPoint upEnemy::getpos()
{
    return pos;
}

int upEnemy::getrange()
{
    return attackRange;
}

void upEnemy::Active()
{
    active=true;
}

bool upEnemy::e_hurt()
{
    Hp-=10;
    if(Hp<=0)
    {
        _game->removeEnemy(this);
        return false;
    }
    return true;
}

void upEnemy::e_slow()
{
    speed-=0.2;
}

bool upEnemy::up()
{
    return true;
}
