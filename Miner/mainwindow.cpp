#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionProfessional,SIGNAL(triggered()),this,SLOT(slotResizeProfessional()), Qt::QueuedConnection);
    connect(ui->actionLover,SIGNAL(triggered()),this,SLOT(slotResizeLover()), Qt::QueuedConnection);
    connect(ui->actionNoob,SIGNAL(triggered()),this,SLOT(slotResizeNoob()), Qt::QueuedConnection);
}

void MainWindow::closeEvent(QCloseEvent *e)
{
    emit signalCloseW();
    e->accept();
}


void MainWindow::slotResizeNoob()
{
    this->resize(204,285);
    this->setFixedSize(204,285);

    ui->labelTime->move(137,0);
    ui->pushButtonPause->move(99,0);
    ui->pushButtonPlay->move(75,0);
}

void MainWindow::slotResizeLover()
{
    this->resize(340,435);
    this->setFixedSize(340,435);

    ui->labelTime->move(273,0);
    ui->pushButtonPause->move(162,0);
    ui->pushButtonPlay->move(138,0);
}

void MainWindow::slotResizeProfessional()
{
    this->resize(460,555);
    this->setFixedSize(460,555);

    ui->labelTime->move(393,0);
    ui->pushButtonPause->move(222,0);
    ui->pushButtonPlay->move(198,0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slotUpdateTime(int tmr)
{
    QString min = (tmr/60<10)? ("0"+QString::number(tmr/60)) : (QString::number(tmr/60));

    QString sec = (tmr%60<10) ? ("0"+QString::number(tmr%60)) : (QString::number(tmr%60));

    ui->labelTime->setText(min+":"+sec);
}
