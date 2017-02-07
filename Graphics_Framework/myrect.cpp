#include "myrect.h"

MyRect::MyRect()
{

}

MyRect::MyRect(QRectF r, QColor c, int w , Qt::PenStyle st)
{
    this->myrect=r;
    this->mycolor=c;
    this->mywidth=w;
    this->mystyle=st;
}

const int& MyRect::width() const
{
    return this->mywidth;
}
const QColor& MyRect::color() const
{
    return this->mycolor;
}
const Qt::PenStyle& MyRect::style() const
{
    return this->mystyle;
}

const QRectF&  MyRect::rect() const
{
    return this->myrect;
}

void MyRect::setColor(QColor c)
{
    this->mycolor = c;
}

void MyRect::setWidth(int w)
{
    this->mywidth=w;
}

void MyRect::setStyle(Qt::PenStyle ps)
{
    this->mystyle=ps;
}

void MyRect::setRect(QRectF r)
{
    this->myrect=r;
}
