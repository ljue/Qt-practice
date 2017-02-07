#include "myscene.h"

MyScene::MyScene(QObject *parent) : QGraphicsScene(parent)
{
    this->setSceneRect(0,0,500,500);

    m_drawingInProcess=false;
    m_startPoint=QPointF(0,0);
    figureType=FigureType{rectangle};
    framecolor=QColor(Qt::black);
    framewidth=1;
    mypen=Qt::SolidLine;
    //current=new QGraphicsRectItem(m_startPoint.x(),m_startPoint.y(),0.,0.);

}

void MyScene::mousePressEvent (QGraphicsSceneMouseEvent * mouseEvent)
{
    if (mouseEvent->button() ==Qt::RightButton)
    {
        m_startPoint=mouseEvent->scenePos();
        QPen rectpen=QPen(QBrush(framecolor),framewidth,mypen);
        if (figureType==FigureType{rectangle})
        {
            current=new QGraphicsRectItem(m_startPoint.x(),m_startPoint.y(),0.,0.);
        }       
        current->setPen(rectpen);
        current->setFlags(QGraphicsItem::ItemIsSelectable);
        this->addItem(current);
        m_drawingInProcess=true;
    }
    else
    {
        QGraphicsScene::mousePressEvent(mouseEvent);
    }

}

void MyScene::mouseReleaseEvent (QGraphicsSceneMouseEvent *mouseEvent)
{
    if(mouseEvent->button() == Qt::RightButton)
    {
        m_drawingInProcess=false;

        emit signalNewShape(rectf,framecolor,framewidth,mypen );
        current=0;
    }
    else
        QGraphicsScene::mouseReleaseEvent (mouseEvent);

}

void MyScene::mouseMoveEvent (QGraphicsSceneMouseEvent *mouseEvent)
{
    if(m_drawingInProcess==true)
    {       
        if (figureType==FigureType{rectangle})
        {
            rectf=QRectF(m_startPoint,mouseEvent->scenePos());
            rectf.normalized();
            qgraphicsitem_cast<QGraphicsRectItem*>(current)->setRect(rectf);
        }

    }
    else
    {
        QGraphicsScene::mouseMoveEvent(mouseEvent);
    }

}

void MyScene::rectangledraw()
{
    figureType=FigureType{rectangle};
}


void MyScene::changecolor()
{
    QColor newcolor=QColorDialog::getColor();
    if(newcolor.isValid())
        framecolor=newcolor;

}

void MyScene::slotUserDialog()
{
    Dialog dlg(framecolor,mypen,framewidth);
        if(dlg.exec()==QDialog::Accepted)//еслиOK
        {
            dlg.getData(&framecolor,&mypen,&framewidth);
        }

}

void MyScene::slotActivated(QRectF rect)
{
    //если на момент вызова текущий примитив выделен,снимаем выделение
    //Мы задали единичное выделение SingleSelection, но метод сцены получения ВСЕХ выделенных примитивов написан в общем виде =>
        QList<QGraphicsItem*> sI = selectedItems();//получаем все выделенные (в нашем случае может быть только один)

        if(sI.size())//если есть выделенный
        {
            sI.front()->setSelected(false);
        }//то он первый и единственный
        //Получаем список всех примитивов, вписанных в прямоугольник “r”
    QList<QGraphicsItem*> allItems = items(rect);//,Qt::ContainsItemBoundingRect);

    if(allItems.size()==1)
    {
    current=static_cast<QGraphicsRectItem*>(allItems.front());
    current->setSelected(true);
    }
   else // В ЭТОЙ ВЕРСИИ НЕ РАССМАТРИВАЕМ
   {
    //если больше,то разбираемся–который?
    }
}

void MyScene::slotShapeChanged(QRectF r,QColor c,uint w,Qt::PenStyle s)
{
   if(current && current ->isSelected())
   {
    QPen pen;
    pen.setColor(c);
    pen.setStyle(s);
    pen.setWidth(w);
    if(pen!= current ->pen())
    {
        current ->setPen(pen);
    }
    current ->setSelected(false);
    current =0;
   }
}

void MyScene::slotAddShape(QRectF rect, QColor color, uint width, Qt::PenStyle style)
{
    current = new QGraphicsRectItem(rect.normalized());
    QPen pen;
    pen.setColor(color);
    pen.setWidth(width);
    pen.setStyle(style);
    current->setPen(pen);
    current->setFlags(QGraphicsItem::ItemIsSelectable);
    addItem(current);
}

