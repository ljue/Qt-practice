#ifndef NEXTFIGURE_H
#define NEXTFIGURE_H

#include <QWidget>
#include "figure.h"

class NextFigure : public QWidget
{
    Q_OBJECT
public:
    explicit NextFigure(QWidget *parent = 0);
    void paintEvent(QPaintEvent*event);

signals:

public slots:
    void drawNextFigure(Figure *next);

private:
    Figure* figure;

};

#endif // NEXTFIGURE_H
