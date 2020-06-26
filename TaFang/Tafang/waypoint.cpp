#include "waypoint.h"

WayPoint::WayPoint(QPoint pos) : QObject(0)
{
    mpos=pos;
    m_nextWayPoint=NULL;
}

WayPoint::WayPoint(WayPoint *p)
{
    mpos=p->pos();
    m_nextWayPoint= p->nextWayPoint();
}
void WayPoint::setNextWayPoint(WayPoint *nextPoint)
{
    m_nextWayPoint=nextPoint;

}

WayPoint* WayPoint::nextWayPoint()const
{
    return m_nextWayPoint;
}

const QPoint WayPoint::pos()const
{
    return mpos;
}

void WayPoint::draw(QPainter*painter) const
{
    painter->save();
    painter->setPen(QColor(0,255,0));
    painter->drawEllipse(mpos,6,6);
    painter->drawEllipse(mpos,2,2);
    if(m_nextWayPoint)
    {
        painter->drawLine(mpos,m_nextWayPoint->mpos);
    }
    painter->restore();
}
