#include "build.h"

Build::Build(QWidget *parent) :
    QWidget(parent)
{
    myTimerId = 0;
    click = 0;
    noAsk = 1;
    wall = QColor(50, 120, 120, 255);
}

Build::~Build()
{

}

void Build::paintEvent(QPaintEvent  */* event */)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setViewport(0, 0, 690, 400);
    painter.setWindow(0, -690, 690, 400);

    drawBuild(&painter);
    lift.drawLift(&painter);
    if (noAsk)
        lift.drawDoor(&painter, wall);
    for (int i = -65, j = 1; i > -700; i -= 100, ++j)
        buttons.drawButton(&painter, j, 30, i);

    painter.drawText(0, -50, 30, 30, Qt::AlignCenter |Qt::AlignTop, QString::number(buttonActive * (-100) - lift.y));
    painter.drawText(0, -40, 30, 30, Qt::AlignCenter |Qt::AlignTop, QString::number(lift.y));
    painter.drawText(0, -30, 30, 30, Qt::AlignCenter |Qt::AlignTop, QString::number(click));
}

void Build::drawBuild(QPainter *painter)
{
    painter->setBrush(QBrush(wall, Qt::SolidPattern));
    painter->drawRect(0, 0, 400, -690);
    painter->setPen(QPen(Qt::black, 5));
    for (int i = 0; i <= 700; i += 100)
        painter->drawLine(0, -i, 290, -i);
    painter->setPen(QPen(Qt::black, 2));
    painter->setBrush(QBrush(Qt::black, Qt::SolidPattern));
    painter->drawRect(290, 0, 110, -700);
}

void Build::timerEvent(QTimerEvent */*event*/)
{
    while (lift.y != moveLiftFloor && !qApp->hasPendingEvents())
    {
        if ((buttonActive * (-100) < lift.y) && (buttonActive != 0))
        {
            lift.y -= 2;
            update();
            if ((buttonActive * (-100) == lift.y))
                noAsk = 1;
            else
                noAsk = 0;
        }
        else if ((buttonActive * (-100) > lift.y) && (buttonActive != 0))
        {
            lift.y += 2;
            update();
            if ((buttonActive * (-100) == lift.y))
                noAsk = 1;
            else
                noAsk = 0;
        }
    }
}

void Build::mousePressEvent(QMouseEvent *event)
{
    if (noAsk)
    {
        if (click == 0)
            myTimerId = startTimer(30);
        if ((buttonActive * (-100) - lift.y) < -10)
        {
            killTimer(myTimerId);
            myTimerId = startTimer(20);
        }
        QPoint point = event->pos();
        buttonActive = buttons.floor(point.x(), point.y());
        coordButtonY = point.y();
        moveLiftFloor = lift.liftMove(buttonActive);
    }
    ++click;
}


