#ifndef LIGHTWORDS_H
#define LIGHTWORDS_H

#include <QObject>
#include <QWidget>
#include <QPainter>

class lightWords : public QWidget
{
    Q_OBJECT
public:
    explicit lightWords(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *);

signals:

};

#endif // LIGHTWORDS_H
