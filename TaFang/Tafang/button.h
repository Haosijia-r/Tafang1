#ifndef BUTTON_H
#define BUTTON_H

#include <QWidget>
#include <QPushButton>

class Button : public QPushButton
{
    Q_OBJECT
public:
    Button();
    Button(QString pix);//构造函数重载
    void draw(QPainter * painter, QPoint po);

    QPoint _po;

signals:

};

#endif // BUTTON_H
