#ifndef FLYINGFIGURES_H
#define FLYINGFIGURES_H

#include <QObject>
#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QtMath>

class FlyingFigures : public QWidget
{
    Q_OBJECT
public:
    explicit FlyingFigures(QWidget *parent = nullptr);
    static double x, y;

protected:
    void paintEvent(QPaintEvent *);

private:
    QTimer *timer;
    double calcY(double a, double b, double x);

private slots:
    void mover();
};

#endif // FLYINGFIGURES_H
