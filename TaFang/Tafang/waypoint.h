#ifndef WayPoint_H
#define WayPoint_H

#include <QObject>
#include <QPainter>

class WayPoint : public QObject
{
    Q_OBJECT

public:
    WayPoint(QPoint pos);
    WayPoint(WayPoint *p);

    void setNextWayPoint(WayPoint *nextPoint);
    WayPoint *nextWayPoint()const;
    const QPoint pos() const;
    void draw(QPainter*painter)const;

private:
    QPoint mpos;
    WayPoint *m_nextWayPoint;

signals:

};


#endif // ENEMY_H
