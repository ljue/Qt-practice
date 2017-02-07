#include "figure.h"

    //    1.	Конструктор
Figure::Figure()
{
   m_i=0;
   m_j=0;
}
Figure::Figure(int i, int j)
{
   m_i=i;
   m_j=j;
}

//    2.	Методы изменения индексов верхней клетки фигуры
void Figure::SetIndexes(int i,int j)
{
    m_i=i;
    m_j=j;
}

//    3.	Методы получения индексов верхней/нижней клеток
int Figure::GetIndexI()
{
   return m_i;
}
int Figure::GetIndexJ()
{
   return m_j;
}
QColor Figure::GetColor(int i)
{
    return figureArray[i];
}

//    4.	Циклическое перемещение цветов –вниз/вверх, например:
void Figure::rotateColorsDown()
{
    QColor tmp=figureArray[2];
    figureArray[2]=figureArray[1];
    figureArray[1]=figureArray[0];
    figureArray[0]=tmp;

}
void Figure::rotateColorsUp()
{
    QColor tmp=figureArray[0];
    figureArray[0]=figureArray[1];
    figureArray[1]=figureArray[2];
    figureArray[2]=tmp;
}


//    5.	Формирование случайным образом цветов, например
void Figure::MakeRandomColors()
{
    for(uint i=0;i<3;i++)
        figureArray[i]=figureColors[qrand()%4];
}


//    6.	Отрисовкафигуры, например:
void Figure::paintFigure(QPainter&painter)
{
    for(uint i=0;i<3;i++)
            painter.fillRect(m_i*m_W,(m_j+i)*m_W,m_W-1,m_W-1,figureArray[i]);
}
