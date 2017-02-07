#ifndef GLASS_H
#define GLASS_H
#define emptyCell QColor(150,150,150)//серыйцвет

#include <QWidget>
#include <QSize>
#include <QPainter>
#include <QKeyEvent>
#include <QTimer>
#include <QMessageBox>

#include "figure.h"

class GLASS : public QWidget
{
    Q_OBJECT



    Q_PROPERTY(uint rows READ rows WRITE setRows)
    Q_PROPERTY(uint columns READ columns WRITE setColumns)

    uint m_rows; // 10 по горизонтали
    uint m_columns; // 20 по вертикали

public:
    explicit GLASS(QWidget *parent = 0);
    void clearGlass();
    void CheckGlass();
    void AcceptColors();
    void repaintarrayj(int k, int i, int j);
    void repaintarrayi(int k, int i, int j);
    ~GLASS();



protected:
    void paintEvent(QPaintEvent*event);
    void keyPressEvent(QKeyEvent*event);
    void timerEvent(QTimerEvent*event);

public:
    uint rows() const
    {
        return m_rows;
    }

    uint columns() const
    {
        return m_columns;
    }

signals:
    void signalGlassInit();
    void drawPattern(Figure *next);
    void setScore(int);

public slots:
    void slotGlassInit();
    void slotNewGame();
    void helpMessage();

    void setRows(uint rows)
    {
        m_rows = rows;
    }
    void setColumns(uint columns)
    {
        m_columns = columns;
    }
private:

    static const uint timerInterval=300;
    QTimer* timer;
    int idTimer;

    bool gameOn;
    uint score;
    static const uint W=20;
    QVector<QVector<QColor> > glassArray;

    Figure *cur; //текущая (падающая) фигурка
    Figure *next; //образец следующей фигурки

};

#endif // GLASS_H
