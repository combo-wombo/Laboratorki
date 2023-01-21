#include "flyingfigures.h"

double FlyingFigures::x = 240;
double FlyingFigures::y = 500;

double a = 40.0;
double b = 30.0;

double FlyingFigures::calcY(double a, double b, double x) {
    return a * sin(pow(x, 2) + b);
}

FlyingFigures::FlyingFigures(QWidget *parent)
    : QWidget{parent}
{
    this->resize(1400, 500);
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(mover()));
    timer->start(120);
}


void FlyingFigures::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QPen pen = QPen(QColor("#ffffff"));
    pen.setWidth(3);
    painter.setPen(pen);

    painter.translate(0, 200);

    x += 30.0;
    y = calcY(a, b, x);
    painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
    painter.drawEllipse(QPointF(x, y), 20, 20);

    painter.translate(40, 0);
    painter.setBrush(QBrush(Qt::yellow, Qt::SolidPattern));
    painter.drawEllipse(QPointF(x, y), 20, 20);

    painter.translate(40, 0);
    painter.setBrush(QBrush(Qt::green, Qt::SolidPattern));
    painter.drawEllipse(QPointF(x, y), 20, 20);

    if (x >= this->width()) {
        x = 0;
        y = calcY(a, b, x);
    }
}

void FlyingFigures::mover() {
    update();
}
