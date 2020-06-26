#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <QMainWindow>
#include <QPainter>
#include <QDebug>
#include <QPushButton>
#include "Tafang.h"
#include "button.h"
#include "window.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setFixedSize(1000,800);//设置游戏开始界面
    ui->setupUi(this);
    Button *bin=new Button(":image/image/start.png");//设置开始按钮
    bin->setParent(this);
    bin->move(215,300);

    connect(bin,&QPushButton::clicked,this,[=]()
    {
        Window *scene = new Window();
        this->close();
        scene->show();
    });//点击按钮后游戏开始界面关闭同时主场景界面打开

}

void MainWindow::paintEvent(QPaintEvent *)//重载paintevent函数
{
    QPainter map(this);
    map.drawPixmap(0,0,this->width(),this->height(),QPixmap(":image/image/map1.png"));//设置开始界面地图
}

MainWindow::~MainWindow()
{
    delete ui;
}



