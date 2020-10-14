#include "lift.h"

Lift::Lift(QWidget *parent)
    : QWidget(parent)
{
    x = 298;
    y = -100;
}

Lift::~Lift()
{

}

void Lift::drawLift(QPainter *painter)
{
    painter->setPen(QPen(Qt::black, 5));
    painter->setBrush(QBrush(QColor(255, 255, 80), Qt::SolidPattern));
    painter->drawRect(x, y, 100, 100);
}

int Lift::liftMove(int floor)
{
    if (floor == 1)
      return -100;
    else if (floor == 2)
      return -200;
    else if (floor == 3)
      return -300;
    else if (floor == 4)
      return -400;
    else if (floor == 5)
      return -500;
    else if (floor == 6)
      return -600;
    else if (floor == 7)
      return -700;
    else
        return 0;
}

void Lift::drawDoor(QPainter *painter, QColor _wall)
{
    painter->setPen(QPen(_wall, 3));
    painter->setBrush(QBrush(_wall, Qt::SolidPattern));
    painter->drawRect(x - 9, y + 4, 10, 92);
}
