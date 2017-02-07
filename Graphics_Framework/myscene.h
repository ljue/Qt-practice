#ifndef MYSCENE_H
#define MYSCENE_H

#include <QObject>
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QEvent>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QColorDialog>
#include <QIcon>

#include "dialog.h"

enum FigureType{rectangle};

class MyScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit MyScene(QObject *parent = 0);
    virtual void mousePressEvent (QGraphicsSceneMouseEvent *mouseEvent);
    virtual void mouseReleaseEvent (QGraphicsSceneMouseEvent *mouseEvent);
    virtual void mouseMoveEvent (QGraphicsSceneMouseEvent *mouseEvent);


signals:
    void signalNewShape(QRectF,QColor,uint,Qt::PenStyle );

public slots:
    void rectangledraw();
    void changecolor();
    void slotUserDialog();
    void slotActivated (QRectF rect);
    void slotShapeChanged(QRectF r,QColor c,uint w,Qt::PenStyle s);
    void slotAddShape(QRectF rect, QColor color, uint width, Qt::PenStyle style);



private:
    QAbstractGraphicsShapeItem* current;
    bool   m_drawingInProcess;
    QPointF   m_startPoint;
    FigureType figureType;
    QColor framecolor;
    int framewidth;
    Qt::PenStyle mypen;
    QRectF rectf;



};

#endif // MYSCENE_H
