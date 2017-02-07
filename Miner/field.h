#ifndef FIELD_H
#define FIELD_H

#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include <QIcon>
#include <QDebug>
#include <QTime>
#include <QTimer>
#include <QMouseEvent>
#include <QMessageBox>

#include "dialog.h"


class Field : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(uint rows READ rows WRITE setRows)
    Q_PROPERTY(uint columns READ columns WRITE setColumns)

public:
    explicit Field(QWidget *parent = 0);
    void paintEvent(QPaintEvent*event);
    void mousePressEvent( QMouseEvent * event );

    ~Field();

    int RecordsMessage();
    void GameOverMessage();
    void CongratulationsMessage();
    int SaveBox();
    int OpenBox();

    void ChangeLvl();
    void OpenZeroField(uint i,uint j);


    uint rows() const
    {
        return m_rows;
    }

    uint columns() const
    {
        return m_columns;
    }

signals:
    void signalFieldInit();
    void signalNewGame();
    void signalPlayPause();
    void signalSetFlags(int);
    void signalUpdateTime(int);

    void signalNoob();
    void signalLover();
    void signalProfessional();

    void signalOpen();
    void signalSave();


public slots:
    void slotFieldInit();
    void slotNewGame();
    void clearField();
    void slotPlayPause();
    void slotTimer();

    void slotNoob();
    void slotLover();
    void slotProfessional();

    void slotCloseWindow();
    void slotOpenWindow();

    void slotRecords();
    void slotStatistic();


    void setRows(uint rows)
    {
        m_rows = rows;
    }

    void setColumns(uint columns)
    {
        m_columns = columns;
    }

private:
    static const uint W=20;
    uint m_rows;
    uint m_columns;

    bool  gameOn;
    bool pause;

    uint numberMine;
    uint noMine;
    uint numberFlag;

    QPixmap pixFlag;
    QPixmap pixMine;
    QPixmap pixBoom;
    QPixmap pixNone;

    QPixmap pixZero;
    QPixmap pixOne;
    QPixmap pixTwo;
    QPixmap pixThree;
    QPixmap pixFour;
    QPixmap pixFive;
    QPixmap pixSix;
    QPixmap pixSeven;
    QPixmap pixEight;

    QTimer *tmr;
    uint currentTime;

    QVector<QString> RecordsArray; // таблица рекордов
    QVector<QString> NumberGamesAndWinsArray;// статистика кол-во игр, кол-во побед

    QVector<QVector<int> > CellArray; // 0-8 кол-во бомб рядом. 9 - бомба
    QVector<QVector<int> > OpenStatusArray; // 0 - нетронутая ячейка. 1- ячейка с флагом. 2 - открытая ячейка
};

#endif // FIELD_H
