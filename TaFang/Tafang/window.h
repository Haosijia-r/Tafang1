#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include "Turret.h"
#include "button.h"
//#include "enemy.h"
#include <QList>
#include <QPainter>
#include"waypoint.h"

class Enemy;
class Window : public QMainWindow
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);

    void loadposition();//设置炮塔位置函数
    void load_Slowposition();
    void setwayPoints();//设置敌人航线节点函数

    void initGame();
    void showWin(QPainter *painter);
    void showLose(QPainter *painter);

    void removeEnemy(Enemy *enemy);
    bool loadwave();
    bool loadUpwave();

    static bool collision(QPoint point1,int radius1,QPoint point2,int radius2);//碰撞检测函数

    void Lose();
    void Win();



public slots:
    void set_Turret(QPoint po);
    void set_SlowTurret(QPoint po);

    void updateMap();
    void Attack();

private:
    QList<Turret*> turret_list;
    QList<Button*> turretPositionsList;
    QList<WayPoint*> wayPointlist;
    QList<Enemy*> enemylist;

    QList<Turret*> turret_list2;
    QList<Button*> turretPositionsList2;


    int wave;
    bool end;
    bool win;

signals:

};




#endif // WINDOW_H
