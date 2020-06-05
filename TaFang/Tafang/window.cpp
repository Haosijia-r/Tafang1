#include "window.h"
#include "button.h"
#include <QPainter>
#include <QMediaPlayer>

Window::Window(QWidget *parent) : QMainWindow(parent)
{

    this->setFixedSize(1000,800);
    initGame();
    Button *setTurret1 = new Button(":image/image/set.png");
    setTurret1->setParent(this);
    setTurret1->move(100,200);
    connect(setTurret1,&Button::clicked,this,&Window::set_Turret);
}

void Window::paintEvent(QPaintEvent *)
{
    QPainter map(this);
    map.drawPixmap(0,0,this->width(),this->height(),QPixmap(":image/image/map1.png"));
    QPainter painter(this);
    foreach(Turret * turret,turret_list)  //遍历
            turret->draw(& painter);

}

void Window::set_Turret()
{
    Turret *newTurret= new Turret(QPoint(100,200),":image/image/turret1.png");
    turret_list.push_back(newTurret);
    update();
}

void Window::initGame()
{
    QMediaPlayer * player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/sound/sound/sound.mp3"));
    player->setVolume(30);
    player->play();

}
