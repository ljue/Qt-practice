#include "pattern.h"

Pattern::Pattern(QFrame * fr) : QFrame(fr)
{



}

void Pattern::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    painter.setPen(patternpen);
    QRect myrect= this->rect();
    painter.drawLine(myrect.topLeft(),myrect.bottomRight());

}


void Pattern::slotChangePen(QPen newPen)
{
    patternpen=newPen;
    repaint();

}
