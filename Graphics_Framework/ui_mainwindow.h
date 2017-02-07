/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionRectangle;
    QAction *actionColor;
    QAction *actionSettings;
    QAction *actionClear;
    QAction *actionSave;
    QAction *actionOpen;
    QAction *actionExit;
    QAction *actionCreate_Connection;
    QAction *actionCreate_table_DB;
    QAction *actionWrite_to_DB;
    QAction *actionRead_from_DB;
    QAction *actionQuery_Model;
    QAction *actionTable_Model;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QSplitter *splitter;
    QTableView *tableView;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuDataBase;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(534, 483);
        actionRectangle = new QAction(MainWindow);
        actionRectangle->setObjectName(QStringLiteral("actionRectangle"));
        actionRectangle->setCheckable(true);
        QIcon icon;
        icon.addFile(QStringLiteral(":/MyImages/Images/Rect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRectangle->setIcon(icon);
        actionColor = new QAction(MainWindow);
        actionColor->setObjectName(QStringLiteral("actionColor"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/MyImages/Images/changecolor.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionColor->setIcon(icon1);
        actionSettings = new QAction(MainWindow);
        actionSettings->setObjectName(QStringLiteral("actionSettings"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/MyImages/Images/settings-256.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSettings->setIcon(icon2);
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName(QStringLiteral("actionClear"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/MyImages/Images/clearicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClear->setIcon(icon3);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/MyImages/Images/saveicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon4);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/MyImages/Images/openicon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon5);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/MyImages/Images/iconExit.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon6);
        actionCreate_Connection = new QAction(MainWindow);
        actionCreate_Connection->setObjectName(QStringLiteral("actionCreate_Connection"));
        actionCreate_table_DB = new QAction(MainWindow);
        actionCreate_table_DB->setObjectName(QStringLiteral("actionCreate_table_DB"));
        actionWrite_to_DB = new QAction(MainWindow);
        actionWrite_to_DB->setObjectName(QStringLiteral("actionWrite_to_DB"));
        actionRead_from_DB = new QAction(MainWindow);
        actionRead_from_DB->setObjectName(QStringLiteral("actionRead_from_DB"));
        actionQuery_Model = new QAction(MainWindow);
        actionQuery_Model->setObjectName(QStringLiteral("actionQuery_Model"));
        actionTable_Model = new QAction(MainWindow);
        actionTable_Model->setObjectName(QStringLiteral("actionTable_Model"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        tableView = new QTableView(splitter);
        tableView->setObjectName(QStringLiteral("tableView"));
        splitter->addWidget(tableView);
        graphicsView = new QGraphicsView(splitter);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        splitter->addWidget(graphicsView);

        verticalLayout->addWidget(splitter);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 534, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuDataBase = new QMenu(menuFile);
        menuDataBase->setObjectName(QStringLiteral("menuDataBase"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionRectangle);
        menuFile->addAction(actionColor);
        menuFile->addAction(actionSettings);
        menuFile->addAction(actionClear);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionOpen);
        menuFile->addAction(menuDataBase->menuAction());
        menuFile->addAction(actionExit);
        menuDataBase->addAction(actionCreate_Connection);
        menuDataBase->addAction(actionCreate_table_DB);
        menuDataBase->addAction(actionWrite_to_DB);
        menuDataBase->addAction(actionRead_from_DB);
        menuDataBase->addAction(actionQuery_Model);
        menuDataBase->addAction(actionTable_Model);
        mainToolBar->addAction(actionRectangle);
        mainToolBar->addAction(actionColor);
        mainToolBar->addAction(actionSettings);
        mainToolBar->addAction(actionClear);

        retranslateUi(MainWindow);
        QObject::connect(actionExit, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionRectangle->setText(QApplication::translate("MainWindow", "Rectangle", 0));
        actionColor->setText(QApplication::translate("MainWindow", "Color", 0));
        actionSettings->setText(QApplication::translate("MainWindow", "Settings", 0));
        actionClear->setText(QApplication::translate("MainWindow", "Clear", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionCreate_Connection->setText(QApplication::translate("MainWindow", "Create Connection", 0));
        actionCreate_table_DB->setText(QApplication::translate("MainWindow", "Create table DB", 0));
        actionWrite_to_DB->setText(QApplication::translate("MainWindow", "Write to DB", 0));
        actionRead_from_DB->setText(QApplication::translate("MainWindow", "Read from DB", 0));
        actionQuery_Model->setText(QApplication::translate("MainWindow", "Query Model", 0));
        actionTable_Model->setText(QApplication::translate("MainWindow", "Table Model", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuDataBase->setTitle(QApplication::translate("MainWindow", "DataBase", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
