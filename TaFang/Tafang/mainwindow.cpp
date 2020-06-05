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
    this->setFixedSize(1000,800);
    ui->setupUi(this);
    Button *bin=new Button(":image/image/start.png");
    bin->setParent(this);
    bin->move(250,300);
    Window *scene = new Window();
    connect(bin,&QPushButton::clicked,this,[=]()
    {
        this->close();
        scene->show();
    });
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter map(this);
    map.drawPixmap(0,0,this->width(),this->height(),QPixmap(":image/image/map1.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}



