#ifndef MYRECT_H
#define MYRECT_H
#include <QObject>
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QEvent>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QColorDialog>

class MyRect
{
public:
    MyRect();
    MyRect(QRectF, QColor, int, Qt::PenStyle);

    const int & width() const;
    const QColor & color() const;
    const Qt::PenStyle & style() const;
    const QRectF&  rect() const;
    void setColor(QColor);
    void setWidth(int);
    void setStyle(Qt::PenStyle);
    void setRect(QRectF);


private:
    QColor mycolor;
    int mywidth;
    Qt::PenStyle mystyle;
    QPointF   m_startPoint;
    QRectF myrect;
};

#endif // MYRECT_H
