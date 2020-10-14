#ifndef BUILD_H
#define BUILD_H

#include <QWidget>
#include <QPainter>
#include "lift.h"
#include "button.h"
#include <QMouseEvent>
#include <QApplication>

class Build : public QWidget
{
    Q_OBJECT

public:
    Build(QWidget *parent = 0);
    ~Build();
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    void drawBuild(QPainter *painter);
    void mousePressEvent(QMouseEvent *event);

private:
    Lift lift;
    Button buttons;
    int myTimerId;
    int buttonActive;
    int moveLiftFloor;
    int click;
    int coordButtonY;
    bool noAsk;
    QColor wall, door;
};

#endif // BUILD_H
