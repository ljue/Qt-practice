#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog() :
    QDialog(),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);


}

Dialog::~Dialog()
{
    delete ui;
}

QString Dialog::getName()
{
    QString name;
    if(ui->lineEditName->text()=="")
        name="Anonymous";
    else
        name=ui->lineEditName->text();

    return name;
}
