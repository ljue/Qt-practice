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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "field.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNewGame;
    QAction *actionNoob;
    QAction *actionLover;
    QAction *actionProfessional;
    QAction *actionExit;
    QAction *actionRecords;
    QAction *actionStatistic;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QWidget *widgetBar;
    QLCDNumber *lcdNumberMines;
    QLabel *labelTime;
    QPushButton *pushButtonPlay;
    QPushButton *pushButtonPause;
    Field *widgetField;
    QMenuBar *menuBar;
    QMenu *menu;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(223, 301);
        MainWindow->setMinimumSize(QSize(204, 265));
        QIcon icon;
        icon.addFile(QStringLiteral(":/MyImages/Images/Minesweeper_Icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionNewGame = new QAction(MainWindow);
        actionNewGame->setObjectName(QStringLiteral("actionNewGame"));
        actionNoob = new QAction(MainWindow);
        actionNoob->setObjectName(QStringLiteral("actionNoob"));
        actionLover = new QAction(MainWindow);
        actionLover->setObjectName(QStringLiteral("actionLover"));
        actionProfessional = new QAction(MainWindow);
        actionProfessional->setObjectName(QStringLiteral("actionProfessional"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionRecords = new QAction(MainWindow);
        actionRecords->setObjectName(QStringLiteral("actionRecords"));
        actionStatistic = new QAction(MainWindow);
        actionStatistic->setObjectName(QStringLiteral("actionStatistic"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widgetBar = new QWidget(centralWidget);
        widgetBar->setObjectName(QStringLiteral("widgetBar"));
        QFont font;
        font.setPointSize(8);
        widgetBar->setFont(font);
        lcdNumberMines = new QLCDNumber(widgetBar);
        lcdNumberMines->setObjectName(QStringLiteral("lcdNumberMines"));
        lcdNumberMines->setGeometry(QRect(0, 0, 64, 23));
        labelTime = new QLabel(widgetBar);
        labelTime->setObjectName(QStringLiteral("labelTime"));
        labelTime->setGeometry(QRect(130, 0, 51, 21));
        QFont font1;
        font1.setPointSize(11);
        labelTime->setFont(font1);
        pushButtonPlay = new QPushButton(widgetBar);
        pushButtonPlay->setObjectName(QStringLiteral("pushButtonPlay"));
        pushButtonPlay->setGeometry(QRect(70, 0, 21, 21));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/MyImages/Images/Play-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonPlay->setIcon(icon1);
        pushButtonPause = new QPushButton(widgetBar);
        pushButtonPause->setObjectName(QStringLiteral("pushButtonPause"));
        pushButtonPause->setGeometry(QRect(100, 0, 21, 21));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/MyImages/Images/Pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonPause->setIcon(icon2);

        verticalLayout->addWidget(widgetBar);

        widgetField = new Field(centralWidget);
        widgetField->setObjectName(QStringLiteral("widgetField"));
        widgetField->setMinimumSize(QSize(200, 200));

        verticalLayout->addWidget(widgetField);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 223, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(actionNewGame);
        menu->addAction(actionNoob);
        menu->addAction(actionLover);
        menu->addAction(actionProfessional);
        menu->addAction(actionRecords);
        menu->addAction(actionStatistic);
        menu->addAction(actionExit);

        retranslateUi(MainWindow);
        QObject::connect(pushButtonPlay, SIGNAL(clicked()), widgetField, SLOT(slotNewGame()));
        QObject::connect(widgetField, SIGNAL(signalSetFlags(int)), lcdNumberMines, SLOT(display(int)));
        QObject::connect(widgetField, SIGNAL(signalUpdateTime(int)), MainWindow, SLOT(slotUpdateTime(int)));
        QObject::connect(pushButtonPause, SIGNAL(clicked()), widgetField, SLOT(slotPlayPause()));
        QObject::connect(actionNewGame, SIGNAL(triggered()), widgetField, SLOT(slotNewGame()));
        QObject::connect(actionLover, SIGNAL(triggered()), widgetField, SLOT(slotLover()));
        QObject::connect(actionNoob, SIGNAL(triggered()), widgetField, SLOT(slotNoob()));
        QObject::connect(actionProfessional, SIGNAL(triggered()), widgetField, SLOT(slotProfessional()));
        QObject::connect(widgetField, SIGNAL(signalNoob()), MainWindow, SLOT(slotResizeNoob()));
        QObject::connect(MainWindow, SIGNAL(signalCloseW()), widgetField, SLOT(slotCloseWindow()));
        QObject::connect(widgetField, SIGNAL(signalLover()), MainWindow, SLOT(slotResizeLover()));
        QObject::connect(widgetField, SIGNAL(signalProfessional()), MainWindow, SLOT(slotResizeProfessional()));
        QObject::connect(actionExit, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(actionRecords, SIGNAL(triggered()), widgetField, SLOT(slotRecords()));
        QObject::connect(actionStatistic, SIGNAL(triggered()), widgetField, SLOT(slotStatistic()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\241\320\260\320\277\321\221\321\200", 0));
        actionNewGame->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\320\260\321\217 \320\270\320\263\321\200\320\260", 0));
        actionNoob->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\262\320\270\321\207\320\276\320\272", 0));
        actionLover->setText(QApplication::translate("MainWindow", "\320\233\321\216\320\261\320\270\321\202\320\265\320\273\321\214", 0));
        actionProfessional->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\321\204\320\265\321\201\321\201\320\270\320\276\320\275\320\260\320\273", 0));
        actionExit->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", 0));
        actionRecords->setText(QApplication::translate("MainWindow", "\320\242\320\260\320\261\320\273\320\270\321\206\320\260 \321\200\320\265\320\272\320\276\321\200\320\264\320\276\320\262", 0));
        actionStatistic->setText(QApplication::translate("MainWindow", "\320\241\321\202\320\260\321\202\320\270\321\201\321\202\320\270\320\272\320\260", 0));
        labelTime->setText(QApplication::translate("MainWindow", "00:00", 0));
        pushButtonPlay->setText(QString());
        pushButtonPause->setText(QString());
        menu->setTitle(QApplication::translate("MainWindow", "\320\234\320\265\320\275\321\216", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
