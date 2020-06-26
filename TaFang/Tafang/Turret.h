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
    virtual ~Turret(){};
    virtual void draw(QPainter * painter);

    virtual QPoint getpo();
    virtual int getrange();

    virtual bool t_hurt();
    virtual void shrink();
    virtual bool slow();

private:
    int t_Hp;
    QPoint _po;
    QPixmap pixmap;

    int attackRange;


signals:

};

#endif // TURRET_H
