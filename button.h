#ifndef BUTTON_H
#define BUTTON_H

#include <QWidget>
#include <QPainter>

class Button : public QWidget
{
    Q_OBJECT
public:
    explicit Button(QWidget *parent = 0);
    void drawButton(QPainter *painter, int n, int _x, int _y);
    int floor(int xButton, int yButton);
    int X() { return x; }
    int Y() { return y; }

private:
    int x, y;

signals:

public slots:

};

#endif // BUTTON_H
