
#include "slowturret.h"
#include <QPoint>
#include <QPixmap>
#include <QPainter>
#include <QList>

SlowTurret::SlowTurret(QPoint po,QString pixFilename)
    :Turret(po,pixFilename),
     pixmap(pixFilename)
{
    _po=po;
    t_Hp=80;
    attackRange=150;
}

void SlowTurret::draw(QPainter * painter)
{
    painter->drawPixmap(_po.x(),_po.y()-30,pixmap);//绘制炮塔

    painter->save();
    painter->setPen(Qt::blue);
    painter->drawEllipse(_po.x()-30,_po.y()-20,attackRange,attackRange);//绘制炮塔光圈
    painter->restore();
}

QPoint SlowTurret::getpo()
{
    return _po;
}

int SlowTurret::getrange()
{
    return attackRange;
}

bool SlowTurret::t_hurt()
{
    t_Hp-=4;
    if(t_Hp<=0)
    {
        return false;
    }
    return true;
}

bool SlowTurret::slow()
{
    return true;
}

void SlowTurret::shrink()
{
    attackRange-=1;
}
