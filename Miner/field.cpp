#include "field.h"

Field::Field(QWidget *parent) : QWidget(parent)
{
    pixFlag.load(":/MyImages/Images/flag3.png");
    pixMine.load(":/MyImages/Images/clanbomber.png");
    pixNone.load(":/MyImages/Images/BoxBlue.png");
    pixBoom.load(":/MyImages/Images/boom.jpg");

    pixZero.load(":/MyImages/Images/BoxGrey.png");
    pixOne.load(":/MyImages/Images/1-8.png");
    pixTwo.load(":/MyImages/Images/2-8.png");
    pixThree.load(":/MyImages/Images/3-5.png");
    pixFour.load(":/MyImages/Images/4-4.png");
    pixFive.load(":/MyImages/Images/five19.png");
    pixSix.load(":/MyImages/Images/6-4.png");//:/MyImages/Images/six25.jpg");
    pixSeven.load(":/MyImages/Images/7-29.gif");
    pixEight.load(":/MyImages/Images/number8-10.jpg");

    QSize PicSize(20, 20);
    pixFlag = pixFlag.scaled(PicSize,Qt::KeepAspectRatio);
    pixMine = pixMine.scaled(PicSize,Qt::KeepAspectRatio);
    pixBoom = pixBoom.scaled(PicSize,Qt::KeepAspectRatio);
    pixNone = pixNone.scaled(PicSize,Qt::KeepAspectRatio);

    pixZero = pixZero.scaled(PicSize,Qt::KeepAspectRatio);
    pixOne = pixOne.scaled(PicSize,Qt::KeepAspectRatio);
    pixTwo = pixTwo.scaled(PicSize,Qt::KeepAspectRatio);
    pixThree = pixThree.scaled(PicSize,Qt::KeepAspectRatio);
    pixFour = pixFour.scaled(PicSize,Qt::KeepAspectRatio);
    pixFive = pixFive.scaled(PicSize,Qt::KeepAspectRatio);
    pixSix = pixSix.scaled(PicSize,Qt::KeepAspectRatio);
    pixSeven = pixSeven.scaled(PicSize,Qt::KeepAspectRatio);
    pixEight = pixEight.scaled(PicSize,Qt::KeepAspectRatio);

    gameOn=false;
    pause=false;

    connect(this,SIGNAL(signalFieldInit()),this, SLOT(slotFieldInit()), Qt::QueuedConnection);
    connect(this,SIGNAL(signalNewGame()),this,SLOT(slotNewGame()), Qt::QueuedConnection);
    connect(this,SIGNAL(signalNoob()),this,SLOT(slotNoob()), Qt::QueuedConnection);
    connect(this,SIGNAL(signalLover()),this,SLOT(slotLover()));
    connect(this,SIGNAL(signalProfessional()),this,SLOT(slotProfessional()));
    connect(this,SIGNAL(signalOpen()),this,SLOT(slotOpenWindow()), Qt::QueuedConnection);
    connect(this,SIGNAL(signalSave()),this,SLOT(slotCloseWindow()));

    tmr=new QTimer(this);
    tmr->setInterval(1000);
    connect(tmr, SIGNAL(timeout()), this, SLOT(slotTimer()));

    emit signalOpen();
}


void Field::slotNewGame()
{
    if(pause)
    {
        pause=false;
        tmr->start();
    }
    else
    {
        gameOn=true;
        pause=false;

        clearField();

        // Расставляем бомбы
        qsrand(QDateTime::currentDateTime().toTime_t());
        for (uint k=0;k<numberMine;k++)
        {
            int tmp = qrand()%(m_rows*m_columns);
            if (CellArray[tmp/m_rows][tmp%m_rows]==9)
                k--;
            else
                CellArray[tmp/m_rows][tmp%m_rows]=9;
        }

        // Расставляем цифры в соседних с бомбами клетках
        for (uint i=0;i<m_rows;i++)
        {
            for (uint j=0;j<m_columns;j++)
            {
                if(CellArray[i][j]==9)
                {
                    if ((i<m_rows-1)&&(CellArray[i+1][j]!=9))
                        CellArray[i+1][j]++;
                    if ((i>0)&&(CellArray[i-1][j]!=9))
                        CellArray[i-1][j]++;

                    if ((i<m_rows-1)&&(j<m_columns-1)&&(CellArray[i+1][j+1]!=9))
                        CellArray[i+1][j+1]++;
                    if ((j>0)&&(i<m_rows-1)&&(CellArray[i+1][j-1]!=9))
                        CellArray[i+1][j-1]++;

                    if ((j<m_columns-1)&&(i>0)&&(CellArray[i-1][j+1]!=9))
                        CellArray[i-1][j+1]++;
                    if ((j>0)&&(i>0)&&(CellArray[i-1][j-1]!=9))
                        CellArray[i-1][j-1]++;

                    if ((j<m_columns-1)&&(CellArray[i][j+1]!=9))
                        CellArray[i][j+1]++;
                    if ((j>0)&&(CellArray[i][j-1]!=9))
                        CellArray[i][j-1]++;
                }
            }
        }

        currentTime=0;
        emit signalUpdateTime(currentTime);

        this->setFocus();
    }
}


void Field::slotFieldInit()
{
    QSize s(m_rows*W,m_columns*W);
    this->setFixedSize(s);

    CellArray.resize(m_rows);
    OpenStatusArray.resize(m_rows);

    for (uint i=0;i<m_rows;i++)
    {
        CellArray[i].resize(m_columns);
        OpenStatusArray[i].resize(m_columns);
    }

    clearField();

}

void Field::clearField()
{
    for (uint i=0;i<m_rows;i++)
    {
        for (uint j=0;j<m_columns;j++)
        {
            OpenStatusArray[i][j]=0;
            CellArray[i][j]=0;
        }
    }

    numberFlag=numberMine;
    noMine=m_rows*m_columns-numberMine;

    emit signalSetFlags(numberFlag);

    this->repaint();
}

void Field::paintEvent(QPaintEvent*event)
{
    QPainter painter(this);
    for(uint i=0;i<m_rows;i++)
    {
        for(uint j=0;j<m_columns;j++)
        {
            if(OpenStatusArray[i][j]==0)
                painter.drawImage(QPoint(i*W,j*W),pixNone.toImage());
            else if (OpenStatusArray[i][j]==1)
                painter.drawImage(QPoint(i*W,j*W),pixFlag.toImage());
            else
            {
                if (CellArray[i][j]==0)                
                    painter.drawImage(QPoint(i*W,j*W),pixZero.toImage());                
                else if (CellArray[i][j]==1)
                    painter.drawImage(QPoint(i*W,j*W),pixOne.toImage());
                else if (CellArray[i][j]==2)
                    painter.drawImage(QPoint(i*W,j*W),pixTwo.toImage());
                else if (CellArray[i][j]==3)
                    painter.drawImage(QPoint(i*W,j*W),pixThree.toImage());
                else if (CellArray[i][j]==4)
                    painter.drawImage(QPoint(i*W,j*W),pixFour.toImage());
                else if (CellArray[i][j]==5)
                    painter.drawImage(QPoint(i*W,j*W),pixFive.toImage());
                else if (CellArray[i][j]==6)
                    painter.drawImage(QPoint(i*W,j*W),pixSix.toImage());
                else if (CellArray[i][j]==7)
                    painter.drawImage(QPoint(i*W,j*W),pixSeven.toImage());
                else if (CellArray[i][j]==8)
                    painter.drawImage(QPoint(i*W,j*W),pixEight.toImage());
                else if (CellArray[i][j]==9)
                {
                    if(noMine==0)
                        painter.drawImage(QPoint(i*W,j*W),pixMine.toImage());
                    else
                        painter.drawImage(QPoint(i*W,j*W),pixBoom.toImage());
                }
            }
        }
    }
}

void Field::mousePressEvent( QMouseEvent * event )
{
    if(gameOn)
    {
        uint tmpi=event->x()/20;
        uint tmpj=event->y()/20;

        if ((event->button() ==Qt::RightButton))
        {
            if(OpenStatusArray[tmpi][tmpj]==0)
            {
                if(numberFlag>0)
                {
                    OpenStatusArray[tmpi][tmpj]=1;
                    numberFlag--;
                    emit signalSetFlags(numberFlag);
                }
            }
            else if(OpenStatusArray[tmpi][tmpj]==1)
            {
                OpenStatusArray[tmpi][tmpj]=0;
                numberFlag++;
                emit signalSetFlags(numberFlag);
            }
        }

        else if (event->button() ==Qt::LeftButton)
        {
            if ((!tmr->isActive())&&(pause==false))
            {
                tmr->start();
            }


            if(OpenStatusArray[tmpi][tmpj]!=1)// Если  клетка не помечена флагом
            {
                OpenStatusArray[tmpi][tmpj]=2;
                if(noMine>0)
                    noMine--;

                if(CellArray[tmpi][tmpj]==9) // Если наткнулись на бомбу, взрываем все бомбы
                {
                    for (uint i=0;i<m_rows;i++)
                    {
                        for (uint j=0;j<m_columns;j++)
                        {
                            if(CellArray[i][j]==9)
                            {
                                OpenStatusArray[i][j]=2;
                            }
                        }
                    }
                    gameOn=false;
                    currentTime=0;
                    tmr->stop();
                    GameOverMessage();

                    if(numberMine==10)
                        NumberGamesAndWinsArray[0]=QString::number(NumberGamesAndWinsArray[0].toInt()+1);
                    else if(numberMine==40)
                        NumberGamesAndWinsArray[2]=QString::number(NumberGamesAndWinsArray[2].toInt()+1);
                    else if(numberMine==99)
                        NumberGamesAndWinsArray[4]=QString::number(NumberGamesAndWinsArray[4].toInt()+1);
                }               
                else if (CellArray[tmpi][tmpj]==0) // Если наткнулись на пустоту, вскрываем все пустоты
                {
                    OpenZeroField(tmpi,tmpj);
                }


                if(noMine==0) // Если вскрыли все клетки без бомб - победа
                {
                    gameOn=false;
                    tmr->stop();

                    if(numberMine==10) // сохраняем рекорд, статистику
                    {
                        if(currentTime<RecordsArray[0].toInt())
                        {
                            RecordsArray[0]=QString::number(currentTime);
                            Dialog* myDialog=new Dialog();
                            if (myDialog->exec() == QDialog::Accepted)
                            {
                                RecordsArray[1] = myDialog->getName();
                            }
                        }
                        else
                            CongratulationsMessage();

                        NumberGamesAndWinsArray[0]=QString::number(NumberGamesAndWinsArray[0].toInt()+1);
                        NumberGamesAndWinsArray[1]=QString::number(NumberGamesAndWinsArray[1].toInt()+1);
                    }
                    else if(numberMine==40)
                    {
                        if(currentTime<RecordsArray[2].toInt())
                        {
                            RecordsArray[2]=QString::number(currentTime);
                            Dialog* myDialog=new Dialog();
                            if (myDialog->exec() == QDialog::Accepted)
                            {
                                RecordsArray[3] = myDialog->getName();
                            }
                        }
                        else
                            CongratulationsMessage();

                        NumberGamesAndWinsArray[2]=QString::number(NumberGamesAndWinsArray[2].toInt()+1);
                        NumberGamesAndWinsArray[3]=QString::number(NumberGamesAndWinsArray[3].toInt()+1);
                    }
                    else if(numberMine==99)
                    {
                        if(currentTime<RecordsArray[4].toInt())
                        {
                            RecordsArray[4]=QString::number(currentTime);
                            Dialog* myDialog=new Dialog();
                            if (myDialog->exec() == QDialog::Accepted)
                            {
                                RecordsArray[5] = myDialog->getName();
                            }
                        }
                        else
                            CongratulationsMessage();

                        NumberGamesAndWinsArray[4]=QString::number(NumberGamesAndWinsArray[4].toInt()+1);
                        NumberGamesAndWinsArray[5]=QString::number(NumberGamesAndWinsArray[5].toInt()+1);
                    }

                    currentTime=0;

                    for (uint i=0;i<m_rows;i++)
                    {
                        for (uint j=0;j<m_columns;j++)
                        {
                            if(CellArray[i][j]==9)
                            {
                                OpenStatusArray[i][j]=2;
                            }
                        }
                    }
                 }
            }
        }
        repaint();
    }
}

void Field::slotTimer()
{
    currentTime++;
    emit signalUpdateTime(currentTime);
}

void Field::slotPlayPause()
{
    if(!pause)
    {
        pause=true;
        tmr->stop();
    }
    else
    {
       pause=false;
       tmr->start();
    }
}

void Field::slotCloseWindow()
{
    tmr->stop();    

    QFile file("Save.txt");
    if(file.open(QFile::WriteOnly|QFile::Text))
    {
        // Формат данных: m_rows; m_columns; numberMine; gameOn [; currentTime; noMine; numberFlag; CellArray; OpenStatusArray]
        QStringList pieces;

        pieces.append(QString::number(static_cast<int>(m_rows)));
        pieces.append(QString::number(static_cast<int>(m_columns)));
        pieces.append(QString::number(static_cast<int>(numberMine)));

        for(uint k=0;k<6;k++)
        {
            pieces.append(RecordsArray[k]);
        }

        if ((gameOn)&&(noMine!=m_rows*m_columns-numberMine)) // если хоть одна клетка вскрыта
        {
            if(SaveBox()==1) // если сохраняем игру
            {
                for(uint ik=0;ik<6;ik++)
                {
                    pieces.append(NumberGamesAndWinsArray[ik]);
                }
                pieces.append(QString::number(static_cast<int>(gameOn)));
                pieces.append(QString::number(static_cast<int>(currentTime)));
                pieces.append(QString::number(static_cast<int>(noMine)));
                pieces.append(QString::number(static_cast<int>(numberFlag)));

                for (uint i=0;i<m_rows;i++)
                {
                    for (uint j=0;j<m_columns;j++)
                    {
                        pieces.append(QString::number(static_cast<int>(OpenStatusArray[i][j])));
                        pieces.append(QString::number(static_cast<int>(CellArray[i][j])));
                    }
                }
            }
            else // если не сохраняем игру
            {
                if(numberMine==10)
                    NumberGamesAndWinsArray[0]=QString::number(NumberGamesAndWinsArray[0].toInt()+1);
                else if(numberMine==40)
                    NumberGamesAndWinsArray[2]=QString::number(NumberGamesAndWinsArray[2].toInt()+1);
                else if(numberMine==99)
                    NumberGamesAndWinsArray[4]=QString::number(NumberGamesAndWinsArray[4].toInt()+1);
                for(uint ik=0;ik<6;ik++)
                {
                    pieces.append(NumberGamesAndWinsArray[ik]);
                }
                gameOn=false;
                pieces.append(QString::number(static_cast<int>(gameOn)));
            }
        }
        else // если ни одна клетка не вскрыта
        {
            for(uint ik=0;ik<6;ik++)
            {
                pieces.append(NumberGamesAndWinsArray[ik]);
            }
            gameOn=false;
            pieces.append(QString::number(static_cast<int>(gameOn)));
        }

        QTextStream stream(&file);
        stream<<pieces.join(",")<<"\n";
    }
    file.close();
}

void Field::slotOpenWindow()
{
    QFile file("Save.txt");
    if(file.open(QFile::ReadOnly|QFile::Text))
    {
        QTextStream stream(&file);
        QString line;
        do
        {
            line=stream.readLine();
            if(!line.isEmpty())
            {
                QStringList pieces=line.split(",",QString::SkipEmptyParts);
                // Формат данных:  m_rows; m_columns; numberMine; gameOn [; currentTime; noMine; numberFlag; (CellArray; OpenStatusArray)]

                QString temp =pieces.value(0);
                m_rows=temp.toInt();
                temp =pieces.value(1);
                m_columns = temp.toInt();
                temp =pieces.value(2);
                numberMine = temp.toInt();

                if(numberMine==10)
                    emit signalNoob();
                else if (numberMine==40)
                    emit signalLover();
                else
                    emit signalProfessional();

                RecordsArray.resize(6);
                temp =pieces.value(3);
                RecordsArray[0] = temp;
                temp =pieces.value(4);
                RecordsArray[1] = temp;
                temp =pieces.value(5);
                RecordsArray[2] = temp;
                temp =pieces.value(6);
                RecordsArray[3] = temp;
                temp =pieces.value(7);
                RecordsArray[4] = temp;
                temp =pieces.value(8);
                RecordsArray[5] = temp;

                NumberGamesAndWinsArray.resize(6);
                temp =pieces.value(9);
                NumberGamesAndWinsArray[0] = temp;
                temp =pieces.value(10);
                NumberGamesAndWinsArray[1] = temp;
                temp =pieces.value(11);
                NumberGamesAndWinsArray[2] = temp;
                temp =pieces.value(12);
                NumberGamesAndWinsArray[3] = temp;
                temp =pieces.value(13);
                NumberGamesAndWinsArray[4] = temp;
                temp =pieces.value(14);
                NumberGamesAndWinsArray[5] = temp;

                temp =pieces.value(15);
                gameOn = temp.toInt();

                QSize s(m_rows*W,m_columns*W);
                this->setFixedSize(s);
                CellArray.resize(m_rows);
                OpenStatusArray.resize(m_rows);
                for (uint i=0;i<m_rows;i++)
                {
                    CellArray[i].resize(m_columns);
                    OpenStatusArray[i].resize(m_columns);
                }

                if(gameOn==1) // Если последняя игра была сохранена
                {
                    if (OpenBox()==1) // Если продолжаем сохраненную игру
                    {
                        temp =pieces.value(16);
                        currentTime = temp.toInt();
                        temp =pieces.value(17);
                        noMine = temp.toInt();
                        temp =pieces.value(18);
                        numberFlag = temp.toInt();

                        for (uint i=0;i<m_rows*m_columns*2;i+=2)
                        {
                            temp =pieces.value(i+19);
                            OpenStatusArray[i/(m_rows*2)][i/2%m_rows] = temp.toInt();
                            temp =pieces.value(i+20);
                            CellArray[i/(m_rows*2)][i/2%m_rows] = temp.toInt();
                        }

                        tmr->start();
                        emit signalSetFlags(numberFlag);
                        emit signalUpdateTime(currentTime);
                        this->repaint();
                    }
                    else // Если не продолжаем сохраненную игру
                    {
                        if(numberMine==10)
                            NumberGamesAndWinsArray[0]=QString::number(NumberGamesAndWinsArray[0].toInt()+1);
                        else if(numberMine==40)
                            NumberGamesAndWinsArray[2]=QString::number(NumberGamesAndWinsArray[2].toInt()+1);
                        else if(numberMine==99)
                            NumberGamesAndWinsArray[4]=QString::number(NumberGamesAndWinsArray[4].toInt()+1);
                        emit signalNewGame();
                    }
                }
                else // Если не было сохраненки
                {
                    emit signalNewGame();
                }
            }

        }while(!line.isEmpty());
        file.close();
    }
    else // Если это первое открытие игры
    {
        emit signalNoob();

        RecordsArray.resize(6);
        RecordsArray[0]="999";
        RecordsArray[1]="Anonymous";
        RecordsArray[2]="999";
        RecordsArray[3]="Anonymous";
        RecordsArray[4]="999";
        RecordsArray[5]="Anonymous";

        NumberGamesAndWinsArray.resize(6);
        for(uint ik=0;ik<6;ik++)
            NumberGamesAndWinsArray[ik]="0";

    }
}

void Field::ChangeLvl()
{
        gameOn=false;
        if(tmr)
            tmr->stop();
        currentTime=0;
        emit signalUpdateTime(currentTime);
}

void Field::slotNoob()
{
    ChangeLvl();

    m_rows=9;
    m_columns=9;
    numberMine=10;

    emit signalFieldInit();
    emit signalNewGame();
}

void Field::slotLover()
{
    ChangeLvl();

    m_rows=16;
    m_columns=16;
    numberMine=40;

    emit signalFieldInit();
    emit signalNewGame();
}

void Field::slotProfessional()
{
    ChangeLvl();

    m_rows=22;
    m_columns=22;
    numberMine=99;

    emit signalFieldInit();
    emit signalNewGame();
}

void Field::slotStatistic()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Статистика");
    msgBox.setWindowIcon(QIcon(":/MyImages/Images/Minesweeper_Icon.png"));

    QString percNoob=(NumberGamesAndWinsArray[0].toInt()==0)?"0":QString::number(NumberGamesAndWinsArray[1].toDouble()/NumberGamesAndWinsArray[0].toDouble()*100,'d',2);
    QString percLover=(NumberGamesAndWinsArray[2].toInt()==0)?"0":QString::number(NumberGamesAndWinsArray[3].toDouble()/NumberGamesAndWinsArray[2].toDouble()*100,'d',2);
    QString percProfessional=(NumberGamesAndWinsArray[4].toInt()==0)?"0":QString::number(NumberGamesAndWinsArray[5].toDouble()/NumberGamesAndWinsArray[4].toDouble()*100,'d',2);

    msgBox.setText(QString("%1 \t %2 \t %3 \t %4\n%5 \t %6 \t %7 \t %8\n%9 \t %10 \t %11 \t %12\n%13 \t %14 \t %15 \t %16")
                   .arg(" ",-15).arg("Всего игр:",-12).arg("Побед:",-10).arg("Процент выигрышей",-18)
                   .arg("Новичок:",-18).arg(NumberGamesAndWinsArray[0],-11).arg(NumberGamesAndWinsArray[1],-12)
            .arg(percNoob+"%",-18)
            .arg("Любитель:",-15).arg(NumberGamesAndWinsArray[2],-11).arg(NumberGamesAndWinsArray[3],-12)
            .arg(percLover+"%",-18)
            .arg("Профессионал:",-15).arg(NumberGamesAndWinsArray[4],-11).arg(NumberGamesAndWinsArray[5],-12)
            .arg(percProfessional+"%",-18));

    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::Yes);
    msgBox.setButtonText(QMessageBox::Yes, "ОК");
    msgBox.setButtonText(QMessageBox::No, "Сбросить статистику");

    if (msgBox.exec()==QMessageBox::Yes)
    {
        //ret=1;
    }
    else
    {
        for(uint ik=0;ik<6;ik++)
            NumberGamesAndWinsArray[ik]="0";
        //ret=0;
    }


}

void Field::slotRecords()
{
    if(RecordsMessage()==0)
    {
        RecordsArray[0]="999";
        RecordsArray[1]="Anonymous";
        RecordsArray[2]="999";
        RecordsArray[3]="Anonymous";
        RecordsArray[4]="999";
        RecordsArray[5]="Anonymous";
    }
}

int Field::RecordsMessage()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Таблица рекордов");
    msgBox.setWindowIcon(QIcon(":/MyImages/Images/Minesweeper_Icon.png"));

    msgBox.setText(QString("%1 \t %2 \t %3\n%4 \t %5 \t %6\n%7 \t %8 \t %9")
                   .arg("Новичок:",-20).arg(RecordsArray[0],-4).arg(RecordsArray[1],-20)
            .arg("Любитель:",-15).arg(RecordsArray[2],-4).arg(RecordsArray[3],-20)
            .arg("Профессионал:",-15).arg(RecordsArray[4],-4).arg(RecordsArray[5],-20));

    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::Yes);
    msgBox.setButtonText(QMessageBox::Yes, "ОК");
    msgBox.setButtonText(QMessageBox::No, "Сбросить рекорды");
    int ret = msgBox.exec();
    if (ret==QMessageBox::Yes)
        ret=1;
    else
        ret=0;
    return ret;
}

int Field::SaveBox()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Сохранение");
    msgBox.setWindowIcon(QIcon(":/MyImages/Images/Minesweeper_Icon.png"));
    msgBox.setText("Хотите сохранить прогресс?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    msgBox.setButtonText(QMessageBox::Save, "Да");
    msgBox.setButtonText(QMessageBox::No, "Нет");
    int ret = msgBox.exec();
    if (ret==QMessageBox::Save)
        ret=1;
    else
        ret=0;
    return ret;
}

int Field::OpenBox()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Сохранка");
    msgBox.setWindowIcon(QIcon(":/MyImages/Images/Minesweeper_Icon.png"));
    msgBox.setText("Хотите продолжить сохраненную игру?");
    msgBox.setStandardButtons(QMessageBox::Open | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    msgBox.setButtonText(QMessageBox::Open, "Да");
    msgBox.setButtonText(QMessageBox::No, "Нет");
    int ret = msgBox.exec();
    if (ret==QMessageBox::Open)
        ret=1;
    else
        ret=0;
    return ret;
}

void Field::CongratulationsMessage()
{
    QMessageBox msgBox;
    msgBox.setIconPixmap(QPixmap(":/MyImages/Images/Minesweeper_Icon.png"));
    msgBox.setWindowTitle("Congratulations!");
    msgBox.setWindowIcon(QIcon(":/MyImages/Images/Minesweeper_Icon.png"));
    msgBox.setText("You win!");
    msgBox.exec();
}

void Field::GameOverMessage()
{
    QMessageBox msgBox;
    msgBox.setIconPixmap(QPixmap(":/MyImages/Images/Minesweeper_Icon.png"));
    msgBox.setWindowTitle("Game Over");
    msgBox.setWindowIcon(QIcon(":/MyImages/Images/Minesweeper_Icon.png"));
    msgBox.setText("You lose!");
    msgBox.exec();
}

void Field::OpenZeroField(uint i,uint j) // Вскрытие пустот
{
    if ((i<m_rows-1)&&(OpenStatusArray[i+1][j]!=2))
    {        
        OpenStatusArray[i+1][j]=2;
        if(CellArray[i+1][j]==0)
        {
            OpenZeroField(i+1,j);            
        }
        noMine--;
    }

    if ((i>0)&&(OpenStatusArray[i-1][j]!=2))
    {        
        OpenStatusArray[i-1][j]=2;
        if(CellArray[i-1][j]==0)
        {
            OpenZeroField(i-1,j);
        }
        noMine--;
    }

    if ((i<m_rows-1)&&(j<m_columns-1)&&(OpenStatusArray[i+1][j+1]!=2))
    {
        OpenStatusArray[i+1][j+1]=2;
        if((CellArray[i+1][j+1]==0))
        {
            OpenZeroField(i+1,j+1);
        }
        noMine--;
    }

    if ((j>0)&&(i<m_rows-1)&&(OpenStatusArray[i+1][j-1]!=2))
    {
        OpenStatusArray[i+1][j-1]=2;
        if((CellArray[i+1][j-1]==0))
        {
            OpenZeroField(i+1,j-1);
        }
        noMine--;
    }

    if ((j<m_columns-1)&&(i>0)&&(OpenStatusArray[i-1][j+1]!=2))
    {
        OpenStatusArray[i-1][j+1]=2;
        if((CellArray[i-1][j+1]==0))
        {
            OpenZeroField(i-1,j+1);
        }
        noMine--;
    }

    if ((j>0)&&(i>0)&&(OpenStatusArray[i-1][j-1]!=2))
    {
        OpenStatusArray[i-1][j-1]=2;
        if((CellArray[i-1][j-1]==0))
        {
            OpenZeroField(i-1,j-1);
        }
        noMine--;
    }

    if ((j<m_columns-1)&&(OpenStatusArray[i][j+1]!=2))
    {
        OpenStatusArray[i][j+1]=2;
        if((CellArray[i][j+1]==0))
        {
            OpenZeroField(i,j+1);
        }
        noMine--;
    }

    if ((j>0)&&(OpenStatusArray[i][j-1]!=2))
    {
        OpenStatusArray[i][j-1]=2;
        if((CellArray[i][j-1]==0))
        {
            OpenZeroField(i,j-1);
        }
        noMine--;
    }
}

Field::~Field()
{
    delete tmr;
}

