#include "window.h"
#include "button.h"
#include "Turret.h"
#include "slowturret.h"
#include "waypoint.h"
#include "enemy.h"
#include "upenemy.h"
#include <QPainter>
#include <QMediaPlayer>
#include <QPoint>
#include <QDebug>
#include <QTimer>
#include <QtMath>

Window::Window(QWidget *parent) : QMainWindow(parent)
{

    this->setFixedSize(1000,800);//设置主场景界面

    loadposition();
    load_Slowposition();
    setwayPoints();
    wave=0;
    end=false;
    win=false;

    loadwave();

    initGame();//游戏启动

    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()), this, SLOT(updateMap()));
    connect(timer,SIGNAL(timeout()), this, SLOT(Attack()));
    timer->start (30) ;

}

void Window::loadposition()
{
    QPoint pos[] =
    {
        QPoint (110,200),
        QPoint (110,300),
        QPoint (280,230),
        QPoint (400,230),
        QPoint (400,360),
        QPoint (400,470),
        QPoint (400,580),
        QPoint (580,500),
        QPoint (680,500),
        QPoint (680,390),
        QPoint (680,280),
        QPoint (870,410)

    };

    for(int i=0;i<12;i++)
    {
        Button *button=new Button(":image/image/set_turret.png");
        button->setParent(this);
        button->move(pos[i]);
        button->_po=pos[i];
        turretPositionsList.append(button);

        connect(button,&Button::clicked,this,[this,button]()
        {
            Window::set_Turret(button->_po);//设置炮塔按钮与炮塔之间的连接
            turretPositionsList.removeOne(button);
            button->deleteLater();
        });
    }

}

void Window::load_Slowposition()
{
    QPoint pos[] =
    {
        QPoint (110,500),
        QPoint (270,360),
        QPoint (550,390),
        QPoint (840,580),

    };

    for(int i=0;i<4;i++)
    {
        Button *button=new Button(":image/image/set_turret2.png");
        button->setParent(this);
        button->move(pos[i]);
        button->_po=pos[i];
        turretPositionsList2.append(button);

        connect(button,&Button::clicked,this,[this,button]()
        {
            Window::set_SlowTurret(button->_po);//设置炮塔按钮与炮塔之间的连接
            turretPositionsList2.removeOne(button);
            button->deleteLater();
        });
    }
}

void Window::paintEvent(QPaintEvent *)//重载paintevent函数
{
    QPainter map(this);
    map.drawPixmap(0,0,this->width(),this->height(),QPixmap(":image/image/map1.png"));//主场景背景绘制
    QPainter painter(this);

    foreach(Turret * turret,turret_list)  //遍历
        turret->draw(& painter); //调用绘制炮塔函数

    /*foreach(WayPoint * waypoint,wayPointlist)
            waypoint->draw(& painter);//绘制敌人航线*/

    foreach(Enemy *enemy,enemylist)
        enemy->draw(& painter);//绘制敌人

    if(end)//判断游戏是否结束
    {
        if(win) showWin(& painter);//绘制胜利界面
        else showLose(& painter);//绘制失败界面*/
    }

}

void Window::set_Turret(QPoint po)
{
    Turret *newTurret= new Turret(po,":image/image/turret1.png");//创建新炮塔

    turret_list.push_back(newTurret);//添加到炮塔Qlist中
    update();
}

void Window::set_SlowTurret(QPoint po)
{
    SlowTurret *newTurret= new SlowTurret(po,":image/image/turret2.png");//创建新炮塔

    turret_list.push_back(newTurret);//添加到炮塔Qlist中
    update();
}

void Window::initGame()
{
    QMediaPlayer * player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/sound/sound/bgm.mp3"));//设置背景音效
    player->setVolume(50);
    player->play();

    QImage img;
    img.load("enemy1.png");
    img.save("enemy1.png");
    img.load("enemy2.png");
    img.save("enemy2.png");
    img.load("turret1.png");
    img.save("turret1.png");
    img.load("turret2.png");
    img.save("turret2.png");
}

void Window::setwayPoints()
{
    WayPoint *wayPoint1=new WayPoint(QPoint(880,190));
    wayPointlist.push_back(wayPoint1);

    WayPoint *wayPoint2=new WayPoint(QPoint(880,340));
    wayPointlist.push_back(wayPoint2);
    wayPoint2->setNextWayPoint(wayPoint1);

    WayPoint *wayPoint3=new WayPoint(QPoint(790,340));
    wayPointlist.push_back(wayPoint3);
    wayPoint3->setNextWayPoint(wayPoint2);

    WayPoint *wayPoint4=new WayPoint(QPoint(790,600));
    wayPointlist.push_back(wayPoint4);
    wayPoint4->setNextWayPoint(wayPoint3);

    WayPoint *wayPoint5=new WayPoint(QPoint(500,600));
    wayPointlist.push_back(wayPoint5);
    wayPoint5->setNextWayPoint(wayPoint4);

    WayPoint *wayPoint6=new WayPoint(QPoint(500,170));
    wayPointlist.push_back(wayPoint6);
    wayPoint6->setNextWayPoint(wayPoint5);

    WayPoint *wayPoint7=new WayPoint(QPoint(220,170));
    wayPointlist.push_back(wayPoint7);
    wayPoint7->setNextWayPoint(wayPoint6);

    WayPoint *wayPoint8=new WayPoint(QPoint(220,450));
    wayPointlist.push_back(wayPoint8);
    wayPoint8->setNextWayPoint(wayPoint7);

    WayPoint *wayPoint9=new WayPoint(QPoint(0,450));
    wayPointlist.push_back(wayPoint9);
    wayPoint9->setNextWayPoint(wayPoint8);

}

void Window::removeEnemy(Enemy *enemy)
{
    enemylist.removeOne(enemy);
    delete enemy;

    QMediaPlayer * player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/sound/sound/death.wav"));//设置敌人死亡音效
    player->setVolume(30);
    player->play();

    if(enemylist.empty())
    {
        wave++;

        if(!loadwave()) Win();
    }

}

bool Window::loadwave()
{
    if(wave>=3) return false;

    WayPoint *startWayPoint = wayPointlist.back();
    int enemyStartInterva1[]={150,1500,2500,3300,4000};

    if(wave<2)//两波低难度敌人
    {
        for(int i=0;i<5;++i)
        {
            Enemy *enemy=new Enemy(startWayPoint, this);
            enemylist.push_back(enemy);


            QTimer::singleShot(enemyStartInterva1[i],enemy,SLOT(Active()));
            update();
        }
    }

    if(wave==2)//一波高难度敌人
    {
        for(int i=0;i<5;++i)
        {
            upEnemy *upenemy=new upEnemy(startWayPoint, this);
            enemylist.push_back(upenemy);


            QTimer::singleShot(enemyStartInterva1[i],upenemy,SLOT(Active()));
            update();
        }
    }

    return true;

}


void Window::updateMap()
{
    foreach(Enemy *enemy,enemylist)
        enemy->move();
    update();
}

bool Window::collision(QPoint point1,int radius1,QPoint point2,int radius2)
{
    const int xdif=point1.x()-point2.x();
    const int ydif=point1.y()-point2.y();
    const int distance=qSqrt(xdif*xdif+ydif*ydif);
    if(distance<=radius1+radius2)
        return true;
    return false;
}

void Window::Attack()
{
    foreach(Enemy *enemy,enemylist)
    {
        foreach(Turret * turret,turret_list)
        {
            if(collision(enemy->getpos(),enemy->getrange()/2,turret->getpo(),enemy->getrange()/2))
            {
                if(!turret->t_hurt())
                {
                    turret_list.removeOne(turret);
                    delete turret;
                    return;
                }
                if(enemy->up()) turret->shrink();

            }
            if(collision(turret->getpo(),turret->getrange()/2,enemy->getpos(),turret->getrange()/2))
            {
                 if(!enemy->e_hurt()) return;
                 if(turret->slow()) enemy->e_slow();
            }
        }
    }
}

void Window::showWin(QPainter *painter)
{

    painter->setPen(Qt::red);
    painter->drawText(QRect(500,400,100,50),QString("WIN"));
}

void Window::showLose(QPainter *painter)
{
    painter->setPen(Qt::red);
    painter->drawText(QRect(480,400,100,50),QString("GAME OVER"));
}

void Window::Lose()
{
    end=true;
    win=false;
}

void Window::Win()
{
    end=true;
    win=true;
}

