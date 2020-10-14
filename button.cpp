#include "button.h"

Button::Button(QWidget *parent) :
    QWidget(parent)
{
    x = 0;
    y = 0;
}

void Button::drawButton(QPainter *painter, int n, int _x, int _y)
{
    x = _x;
    y = _y;
    painter->setPen(QPen(Qt::black, 2));
    painter->setBrush(QBrush(QColor(255, 0, 0), Qt::SolidPattern));
    painter->drawRect(x, y, 30, 30);
    painter->drawText(x, y, 30, 30, Qt::AlignCenter |Qt::AlignTop, QString::number(n));
}

int Button::floor(int xButton, int yButton)
{
  if ((xButton >= 30) && (xButton <= 60) && (yButton >= 25) && (yButton <= 55))
      return 7;
    else if ((xButton >= 30) && (xButton <= 60) && (yButton >= 125) && (yButton <= 155))
      return 6;
    else if ((xButton >= 30) && (xButton <= 60) && (yButton >= 225) && (yButton <= 255))
      return 5;
    else if ((xButton >= 30) && (xButton <= 60) && (yButton >= 325) && (yButton <= 355))
      return 4;
    else if ((xButton >= 30) && (xButton <= 60) && (yButton >= 425) && (yButton <= 455))
      return 3;
    else if ((xButton >= 30) && (xButton <= 60) && (yButton >= 525) && (yButton <= 555))
      return 2;
    else if ((xButton >= 30) && (xButton <= 60) && (yButton >= 625) && (yButton <= 655))
      return 1;
    else
        return 0;
}
