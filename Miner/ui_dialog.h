/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *labelPassName;
    QLineEdit *lineEditName;
    QLabel *labelCongratulations;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(371, 204);
        QIcon icon;
        icon.addFile(QStringLiteral(":/MyImages/Images/clanbomber.png"), QSize(), QIcon::Normal, QIcon::Off);
        Dialog->setWindowIcon(icon);
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(0, 140, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        labelPassName = new QLabel(Dialog);
        labelPassName->setObjectName(QStringLiteral("labelPassName"));
        labelPassName->setGeometry(QRect(20, 90, 101, 21));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(11);
        labelPassName->setFont(font);
        lineEditName = new QLineEdit(Dialog);
        lineEditName->setObjectName(QStringLiteral("lineEditName"));
        lineEditName->setGeometry(QRect(130, 90, 141, 20));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial Narrow"));
        font1.setPointSize(10);
        lineEditName->setFont(font1);
        lineEditName->setMaxLength(20);
        labelCongratulations = new QLabel(Dialog);
        labelCongratulations->setObjectName(QStringLiteral("labelCongratulations"));
        labelCongratulations->setGeometry(QRect(20, 40, 311, 16));
        QFont font2;
        font2.setFamily(QStringLiteral("Times New Roman"));
        font2.setPointSize(12);
        labelCongratulations->setFont(font2);

        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "\320\236\320\277\320\276\320\267\320\275\320\260\320\275\320\270\320\265", 0));
        labelPassName->setText(QApplication::translate("Dialog", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\270\320\274\321\217:", 0));
        labelCongratulations->setText(QApplication::translate("Dialog", "\320\237\320\276\320\267\320\264\321\200\320\260\320\262\320\273\321\217\321\216! \320\222\321\213 \320\277\320\276\321\201\321\202\320\260\320\262\320\270\320\273\320\270 \320\275\320\276\320\262\321\213\320\271 \321\200\320\265\320\272\320\276\321\200\320\264!", 0));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
