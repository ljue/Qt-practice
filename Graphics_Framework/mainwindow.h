#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QActionGroup>
#include <QGraphicsView>

#include <QGraphicsScene>
//#include <QRegisterMetaType>

#include "myscene.h"
#include "mymodel.h"
#include "mydelegate.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

private:
    Ui::MainWindow *ui;
    QActionGroup * pactionGroup;
    MyModel* mymodel;
    MyScene* scene;
};

#endif // MAINWINDOW_H
