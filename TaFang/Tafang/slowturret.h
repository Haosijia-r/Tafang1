#ifndef SLOWTURRET_H
#define SLOWTURRET_H

#include <QObject>
#include "Turret.h"

class SlowTurret:public Turret
{
public:
    SlowTurret(QPoint po,QString pixFilename);
    ~SlowTurret(){};

    void draw(QPainter * painter);

    QPoint getpo();
    int getrange();

    bool t_hurt();
    void shrink();
    bool slow();

private:
    int t_Hp;
    QPoint _po;
    QPixmap pixmap;

    int attackRange;
};

#endif // SLOWTURRET_H
