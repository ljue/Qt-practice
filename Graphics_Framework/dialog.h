#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QComboBox>
#include <QVariant>
#include <QColor>
#include <QPen>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    //explicit
    Dialog( QColor framecolor=Qt::black,Qt::PenStyle mypen=Qt::SolidLine,uint framewidth=1);
    ~Dialog();
    void getData(QColor* framecolor,Qt::PenStyle* mypen,int* framewidth);

private:
    Ui::Dialog *ui;
    int intred;
    int intblue;
    int intgreen;
    QMap<QString, Qt::PenStyle> map;



public slots:
    void slotSomebodyChanged();

signals:
    void  signalChangePattern(QPen);

};

#endif // DIALOG_H
