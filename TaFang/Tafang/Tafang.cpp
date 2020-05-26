#include <QPainter>
#include <QTime>
#include <QDebug>
#include <QtCore/qmath.h>
#include <QMediaPlayer>
#include "mainwindow.h"
#include "Tafang.h"

Object::Object(QWidget *parent):QWidget(parent)
{
    initGame();

}
void Object::paintEvent(QPaintEvent *)
{
    QPainter map(this);
    map.drawPixmap(0,0,this->width(),this->height(),QPixmap(":image/image/map.png"));
}
void Object::initGame()
{
    QMediaPlayer * player = new QMediaPlayer;
    player->setMedia(QUrl("qrc:/sound/sound/sound.mp3"));
    player->setVolume(30);
    player->play();

}
//Turret::Turret(QWidget *parent = 0)

