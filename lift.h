#ifndef LIFT_H
#define LIFT_H

#include <QWidget>
#include <QPainter>

class Lift : public QWidget
{
    Q_OBJECT

public:
    Lift(QWidget *parent = 0);
    ~Lift();
    void drawLift(QPainter *painter);
    int liftMove(int floor);
    void drawDoor(QPainter *painter, QColor _wall);

//private:
    int x, y;
};

#endif // LIFT_H
