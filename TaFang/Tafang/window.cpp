#include "window.h"
#include "button.h"
#include "Turret.h"
#include <QPainter>
#include <QMediaPlayer>
#include <QPoint>

Window::Window(QWidget *parent) : QMainWindow(parent)
{

    this->setFixedSize(1000,800);//设置主场景界面
    initGame();//游戏启动
    loadposition();
    setwayPoints();
    //Button *setTurret1 = new Button(":image/image/set_turret.png");//绘制炮塔按钮
    //setTurret1->setParent(this);
    //setTurret1->move(110,200);
    //connect(setTurret1,&Button::clicked,this,&Window::set_Turret);
}

void Window::loadposition()
{
    QPoint pos[] =
    {
        QPoint (110,200),
        QPoint (210,200),
        QPoint (310,200),
        QPoint (310,310),
        QPoint (310,410),
        QPoint (410,500),
        QPoint (410,600),
        QPoint (310,600),
        QPoint (210,600)

    };

    for(int i=0;i<9;i++)
    {
        turretPositionsList[i]->_po=pos[i];
    }

}

void Window::paintEvent(QPaintEvent *)//重载paintevent函数
{
    QPainter map(this);
    map.drawPixmap(0,0,this->width(),this->height(),QPixmap(":image/image/map1.png"));//主场景背景绘制
    QPainter painter(this);

    foreach(Button *button,turretPositionsList)  //遍历绘制炮塔按钮
    {
        button->setParent(this);
        button->draw(& painter, button->_po);
        connect(button,&Button::clicked,this,[=]
        {
            Window::set_Turret(button->_po);//设置炮塔按钮与炮塔之间的连接
        });
    }
    foreach(Turret * turret,turret_list)  //遍历
        turret->draw(& painter); //调用绘制炮塔函数
}

void Window::set_Turret(QPoint po)
{
    Turret *newTurret= new Turret(po,":image/image/turret1.png");//创建新炮塔
    turret_list.push_back(newTurret);//添加到炮塔Qlist中
    update();
}

void Window::initGame()
{
    QMediaPlayer * player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/sound/sound/sound.mp3"));//设置背景音效
    player->setVolume(30);
    player->play();

}

void Window::setwayPoints()
{

}
