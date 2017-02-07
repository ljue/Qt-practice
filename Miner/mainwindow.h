#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    virtual void closeEvent(QCloseEvent *e);

private:
    Ui::MainWindow *ui;

signals:
    void signalCloseW();

public slots:
    void slotUpdateTime(int);
    void slotResizeNoob();
    void slotResizeLover();
    void slotResizeProfessional();

};

#endif // MAINWINDOW_H
