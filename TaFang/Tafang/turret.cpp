#include "turret.h"
#include "window.h"
#include "button.h"
#include <QPoint>
#include <QPixmap>
#include <QPainter>
#include <QList>

Turret::Turret(QPoint po,QString pixFilename) : QObject(0),pixmap(pixFilename)
{
    _po=po;

}

void Turret::draw(QPainter * painter)
{
    painter->drawPixmap(_po,pixmap);//绘制炮塔
    painter->drawPixmap(_po,QPixmap(":image/image/circle.png"));//绘制炮塔光圈
}

