#ifndef FIGURE_H
#define FIGURE_H

#include <QWidget>
#include <QSize>
#include <QPainter>

class Figure
{



public:
    Figure();
    Figure(int i, int j);
    void paintFigure(QPainter&painter);
    void rotateColorsUp();
    void rotateColorsDown();
    void MakeRandomColors();
    void SetIndexes(int i,int j);
    int GetIndexI();
    int GetIndexJ();
    QColor GetColor(int i);

private:
    uint m_i,m_j;
    static const uint m_W=20;
    QColor figureArray[3];
    Qt::GlobalColor figureColors[4]={Qt::red, Qt::green, Qt::yellow, Qt::blue};

};

#endif // FIGURE_H
