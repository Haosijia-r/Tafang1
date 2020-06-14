#include "button.h"
#include<QPixmap>
#include<QPainter>

Button::Button(QString pix):QPushButton(0)
{
    QPixmap pixmap(pix);
    this->setFixedSize(pixmap.width(),pixmap.height());
    this->setStyleSheet("QPushButton{border:Opx;}");//使塔与按钮的形状完全相契合
    this->setIcon(pixmap);
    this->setIconSize(QSize(pixmap.width(),pixmap.height()));
}

/*Button::Button(QPoint po)
{
    _po=po;
}*/
void Button::draw(QPainter * painter, QPoint po)
{
    painter->drawPixmap(po,QPixmap(":image/image/set_turret.png"));
}
