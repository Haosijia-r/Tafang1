#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include "turret.h"
#include "button.h"
#include <QList>
#include <vector>
#include"waypoint.h"

class Window : public QMainWindow
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    void loadposition();//设置炮塔位置
    void set_Turret(QPoint po);
    void initGame();
    void setwayPoints();
private:
    QList<Turret*> turret_list;
    QList<Button*> turretPositionsList;
    QList<WayPoint*> wayPointlist;
signals:

};




#endif // WINDOW_H
