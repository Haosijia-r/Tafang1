#include "turret.h"
#include <QPoint>
#include <QPixmap>
#include <QPainter>

Turret::Turret(QPoint po,QString pixFilename) : QObject(0),pixmap(pixFilename)
{
    _po=po;
}

void Turret::draw(QPainter * painter)
{
    painter->drawPixmap(_po,pixmap);
}
