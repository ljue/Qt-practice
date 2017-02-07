#include "mainwindow.h"
#include "ui_mainwindow.h"

// lab 6

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pactionGroup = new QActionGroup(this);
    pactionGroup->addAction(ui->actionRectangle);


    scene=new MyScene();//создаем НАШУ сцену
    ui->graphicsView->setScene(scene); //и ассоциируем ее с QGraphicsView
    ui->actionRectangle->setChecked(true);

    QHeaderView* p = ui->tableView->horizontalHeader();
    p->setSectionResizeMode(QHeaderView::Stretch);

    mymodel=new MyModel(this);
    ui->tableView->setSelectionMode( QAbstractItemView::SingleSelection);
    ui->tableView->setModel(mymodel);

    MyDelegate * delegate= new MyDelegate(ui->tableView);
    ui->tableView->setItemDelegate(delegate);


    QObject::connect(ui->actionRectangle,SIGNAL(triggered()),scene, SLOT(rectangledraw()));
    QObject::connect(ui->actionColor,SIGNAL(triggered()),scene,SLOT(changecolor()));
    QObject::connect(ui->actionSettings,SIGNAL(triggered()),scene,SLOT(slotUserDialog()));

    QObject::connect(scene,SIGNAL(signalNewShape(QRectF,QColor,uint,Qt::PenStyle)),mymodel,SLOT(slotNewShape(QRectF,QColor,uint,Qt::PenStyle)));

    QObject::connect(ui->tableView,SIGNAL(doubleClicked(QModelIndex)),mymodel,SLOT(slotActivated(QModelIndex)));
    QObject::connect(mymodel,SIGNAL(signalActivated(QRectF)),scene,SLOT(slotActivated(QRectF)));
    qRegisterMetaType<Qt::PenStyle>("Qt::PenStyle");

    QObject::connect(mymodel, SIGNAL(signalShapeChanged(QRectF,QColor,uint,Qt::PenStyle)), scene, SLOT(slotShapeChanged(QRectF,QColor,uint,Qt::PenStyle)),Qt::QueuedConnection);

    QObject::connect(ui->actionClear, SIGNAL(triggered()), mymodel, SLOT(slotClear()));
    QObject::connect(mymodel, SIGNAL(signalClear()), scene, SLOT(clear()));

    QObject::connect(ui->actionSave, SIGNAL(triggered()), mymodel, SLOT(slotSave()));
    QObject::connect(mymodel, SIGNAL(signalAddShape(QRectF,QColor,uint,Qt::PenStyle)), scene, SLOT(slotAddShape(QRectF,QColor,uint,Qt::PenStyle)));

    QObject::connect(ui->actionOpen, SIGNAL(triggered()), mymodel, SLOT(slotClear()));
    QObject::connect(ui->actionOpen, SIGNAL(triggered()), mymodel, SLOT(slotOpen()));

    QObject::connect(ui->actionCreate_Connection, SIGNAL(triggered()), mymodel, SLOT(slotCreateConnection()));
    QObject::connect(ui->actionCreate_table_DB, SIGNAL(triggered()), mymodel, SLOT(slotCreateTable()));
    QObject::connect(ui->actionQuery_Model, SIGNAL(triggered()), mymodel, SLOT(slotQueryModel()));
    QObject::connect(ui->actionRead_from_DB, SIGNAL(triggered()), mymodel, SLOT(slotRead()));
    QObject::connect(ui->actionWrite_to_DB, SIGNAL(triggered()), mymodel, SLOT(slotWrite()));
    QObject::connect(ui->actionTable_Model, SIGNAL(triggered()), mymodel, SLOT(slotTableModel()));






}

MainWindow::~MainWindow()
{
    delete ui;
}


