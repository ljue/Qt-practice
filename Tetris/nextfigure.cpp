#include "nextfigure.h"

NextFigure::NextFigure(QWidget *parent) : QWidget(parent)
{
    figure=new Figure();
}

void NextFigure::paintEvent(QPaintEvent*event)
{
    QPainter painter(this);

    QSize qws=this->size();   
   painter.translate(qws.width()/2-10,5);
    //painter.translate(25,5);
    figure->paintFigure(painter);


    //for(uint i=0;i<3;i++)
     //       painter.fillRect(figure->m_i*figure->m_W,(figure->m_j+i)*figure->m_W,figure->m_W-1,figure->m_W-1,figure->figureArray[i]);
}

void NextFigure::drawNextFigure(Figure *next)
{
    figure=next;
    repaint();
}
