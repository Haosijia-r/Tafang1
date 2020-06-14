#ifndef TURRET_H
#define TURRET_H

#include <QObject>
#include <QPoint>
#include <QPixmap>
#include "button.h"

class Turret : public QObject
{
    Q_OBJECT
public:
    Turret(QPoint po,QString pixFilename);
    void draw(QPainter * painter);

private:
    QPoint _po;
    QPixmap pixmap;


signals:

};

#endif // TURRET_H
