#ifndef WINDOW_H
#define WINDOW_H

#include <QMainWindow>
#include "turret.h"
#include "button.h"
#include <QList>
#include <vector>

class Window : public QMainWindow
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
    void set_Turret();
    void initGame();
private:
    QList<Turret*> turret_list;


signals:

};

#endif // WINDOW_H
