#include "lightwords.h"

lightWords::lightWords(QWidget *parent)
    : QWidget{parent}
{

}

void lightWords::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    painter.setPen(QColor("#fffccc"));
    painter.setFont(QFont("Arial", 32, QFont::Bold));
    painter.translate(QPointF(300, 30));
    painter.rotate(90);
    painter.drawText(rect(), "Графические примитивы");

    painter.translate(QPointF(80, -80));
    painter.drawText(rect(), "в библиотеке QT");
}
