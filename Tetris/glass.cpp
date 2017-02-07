#include "glass.h"
#include <QDebug>

GLASS::GLASS(QWidget *parent) : QWidget(parent)
{
    gameOn=false;

    connect(this,SIGNAL(signalGlassInit()),this, SLOT(slotGlassInit()), Qt::QueuedConnection);
    emit signalGlassInit();

    cur=new Figure();
    next=new Figure();

    emit drawPattern(next);
}

void GLASS::slotNewGame()
{
    if (gameOn==true)
    {
        killTimer(idTimer);
    }

    gameOn=true;

    clearGlass();

    cur->MakeRandomColors();    
    cur->SetIndexes(m_rows/2,0);

    next->MakeRandomColors();
    next->SetIndexes(m_rows/2,0);

    emit drawPattern(next);

    idTimer=startTimer(timerInterval);

    this->setFocus();

}

void GLASS::slotGlassInit()
{
    QSize s(m_rows*W,m_columns*W);
    this->setFixedSize(s);

    glassArray.resize(m_rows);

    for (uint i=0;i<m_rows;i++)
        glassArray[i].resize(m_columns);

    clearGlass();

}

void GLASS::clearGlass()
{
    //glassArray.fill(QVector<QColor>(m_rows,emptyCell));
    for (uint i=0;i<m_rows;i++)
        glassArray[i].fill(emptyCell,m_columns);

    score=0;
    this->repaint();
}

void GLASS::paintEvent(QPaintEvent*event)
{
    QPainter painter(this);//стаканрисуемвсегда!
    for(uint i=0;i<m_rows;i++){
        for(uint j=0;j<m_columns;j++)
        {
            QBrush brush(glassArray[i][j]);
            painter.fillRect(i*W,j*W,W-1,W-1,brush);
        }
    }
//qDebug() << m_columns << m_rows << "paint";
    if(gameOn) //а фигурку будем рисовать только, если «идет игра»
    {
        cur->paintFigure(painter);//здесь будем рисовать падающую фигурку
    }
}


void GLASS::keyPressEvent(QKeyEvent*event)
{
    if(gameOn)//Если«идет игра»
    {
        switch(event->key())//коднажатойклавиши
        {
            case Qt::Key_Left://если есть «куда», перемещаем фигурку влево
                if(cur->GetIndexI()>0)
                    cur->SetIndexes(cur->GetIndexI()-1,cur->GetIndexJ());
                break;
            case Qt::Key_Right:
                if(cur->GetIndexI()<m_rows-1)
                    cur->SetIndexes(cur->GetIndexI()+1,cur->GetIndexJ());
                break;
            case Qt::Key_Down://циклически ”переливаем” цвета в фигурке сверху вниз
                cur->rotateColorsDown();
                break;
            case Qt::Key_Up://циклически ”переливаем” цвета в фигурке снизу вверх
                cur->rotateColorsUp();
                break;
            case Qt::Key_Space://«роняем» фигурку
                killTimer(idTimer);
                idTimer=startTimer(30);
                AcceptColors();
                break;
            default:
                QWidget::keyPressEvent(event); //принажатиилюбыхдругихклавишвызываембазовуюобработкусобытия
        }
        repaint();
    }
    else
    {
    QWidget::keyPressEvent(event);//предоставляемвозможностьбазовому
    //классуобработатьсобытие
    }
}

void GLASS::timerEvent(QTimerEvent*event)
{
    AcceptColors();
}

void GLASS::AcceptColors()
{
    //qDebug() << cur->GetIndexI() << cur->GetIndexJ() << "";
        if (glassArray[cur->GetIndexI()][2]!=emptyCell)
        {
            gameOn=false;
            killTimer(idTimer);

            QMessageBox msgBox;
            msgBox.setText("Game Over");
            msgBox.exec();

        }
        else if((cur->GetIndexJ()<m_columns-3)&&(glassArray[cur->GetIndexI()][cur->GetIndexJ()+3]==emptyCell))
        {
            cur->SetIndexes(cur->GetIndexI(),cur->GetIndexJ()+1);

            repaint();
        }
        else
        {
            killTimer(idTimer);
            for (uint i=0;i<3;i++)
            {
                glassArray[cur->GetIndexI()][cur->GetIndexJ()+i]=cur->GetColor(i);
            }

            CheckGlass();
            CheckGlass();

//            Figure *tmp=cur; cur=next; next=tmp;
//            next->MakeRandomColors();
//            cur->SetIndexes(m_rows/2,0);
//            next->SetIndexes(0,0);

            cur=next;
            //cur->SetIndexes(m_rows/2,0);
            next=new Figure(m_rows/2,0);
            next->MakeRandomColors();

            idTimer=startTimer(timerInterval);

            emit drawPattern(next);
            emit setScore(score);
            repaint();
        }

}



void GLASS::CheckGlass()
{
    uint k=0;
    for(uint i=m_columns-1;i>0;i--) // по горизонтали
    {
        for(uint j=0;j<m_rows;j++)
        {
            if ((j+1==m_rows)||((j+1<m_rows)&&(glassArray[j][i]!=glassArray[j+1][i])))
            {
                if (k>0)
                {
                    repaintarrayi(k,i,j);
                    j=0;
                    k=0;
                }               
            }
            if((j+2<m_rows)&&(glassArray[j][i]!=emptyCell)&&(glassArray[j][i]==glassArray[j+1][i])&&(glassArray[j][i]==glassArray[j+2][i]))
            {
                k++;
            }
        }
    }

    k=0;
    for(uint j=0;j<m_rows;j++) // по вертикали
        {
            for(uint i=m_columns-1;i>2;i--)
                {
                if ((glassArray[j][i-1]==emptyCell)||(glassArray[j][i-1]!=glassArray[j][i]))
                {
                    if (k>0)
                    {
                        repaintarrayj(k,i,j);
                        i=m_columns-1;
                    }
                    k=0;
                }
                if((glassArray[j][i]==glassArray[j][i-1])&&(glassArray[j][i]==glassArray[j][i-2])&&(glassArray[j][i]!=emptyCell))
                {
                    k++;
                }
            }
        }
}

void GLASS::repaintarrayj(int k, int jj, int ii)  // по вертикали
{
    for(int j=jj+k+1;j>2+k;j--)
    {
        glassArray[ii][j]=glassArray[ii][j-2-k];
    }
    for (int j=0;j<k+2;j++)
        glassArray[ii][j]=emptyCell;
    score+=2+k;
}

void GLASS::repaintarrayi(int k, int jj, int ii) // по горизонтали
{
    for(int i=ii;i>ii-k-2;i--)
    {
        for(int j=jj;j>1;j--)
        {
            glassArray[i][j]=glassArray[i][j-1];
        }
        glassArray[i][0]=emptyCell;
    }
    score+=2+k;
}


GLASS::~GLASS()
{
    delete cur;
    delete next;
}



void GLASS::helpMessage()
{
    //QPixmap pxm= QPixmap(":\Images\Tetris.png");

    QMessageBox msgBox;
    msgBox.setIconPixmap(QPixmap(":\Images\Tetris.png"));
    msgBox.setText("-> Движение фигурки вправо\n<- Движение фигурки влево\n"
                   "вверх/вниз - Перемещение цветов фигуркии вверх/вниз\n"
                   "space - Сбросить фигурку вниз");


    msgBox.exec();
}
