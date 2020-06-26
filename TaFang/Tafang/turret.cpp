#include "Turret.h"
#include "window.h"
#include "button.h"
#include <QPoint>
#include <QPixmap>
#include <QPainter>
#include <QList>

Turret::Turret(QPoint po,QString pixFilename) : QObject(0),pixmap(pixFilename)
{
    _po=po;
    t_Hp=80;
    attackRange=150;
}

void Turret::draw(QPainter * painter)
{
    painter->drawPixmap(_po.x(),_po.y()-30,pixmap);//绘制炮塔

    painter->save();
    painter->setPen(Qt::white);
    painter->drawEllipse(_po.x()-40,_po.y()-20,attackRange,attackRange);//绘制炮塔光圈
    painter->restore();
}

QPoint Turret::getpo()
{
    return _po;
}

int Turret::getrange()
{
    return attackRange;
}

bool Turret::t_hurt()
{
    t_Hp-=4;
    if(t_Hp<=0)
    {
        return false;
    }
    return true;
}

bool Turret::slow()
{
    return false;
}

void Turret::shrink()
{
    attackRange-=1;
}
