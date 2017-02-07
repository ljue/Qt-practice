#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog( QColor framecolor,Qt::PenStyle mypen,uint framewidth) :
    QDialog(),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);


    map["Сплошная"]=Qt::SolidLine;
    map["Пунктир"]=Qt::DashLine;
    map["Точками"]=Qt::DotLine;
    map["Точка-тире"]=Qt::DashDotLine;
    map["Точка-точка-тире"]=Qt::DashDotDotLine;


    ui->comboBox->addItem("Сплошная");
    ui->comboBox->addItem("Пунктир");
    ui->comboBox->addItem("Точками");
    ui->comboBox->addItem("Точка-тире");
    ui->comboBox->addItem("Точка-точка-тире");

    ui->spinBox->setValue(framewidth);

    ui->comboBox->setCurrentText(map.key(mypen));



    framecolor.getRgb(&intred,&intgreen,&intblue);
    ui->SliderBlue->setValue(intblue);
    ui->SliderGreen->setValue(intgreen);
    ui->SliderRed->setValue(intred);



    QObject::connect(ui->comboBox, SIGNAL(currentTextChanged(QString)), this, SLOT(slotSomebodyChanged()));
    QObject::connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(slotSomebodyChanged()));

    QObject::connect(ui->SliderRed, SIGNAL(valueChanged(int)), this, SLOT(slotSomebodyChanged()));
    QObject::connect(ui->SliderGreen, SIGNAL(valueChanged(int)), this, SLOT(slotSomebodyChanged()));
    QObject::connect(ui->SliderBlue, SIGNAL(valueChanged(int)), this, SLOT(slotSomebodyChanged()));

    QObject::connect(this, SIGNAL(signalChangePattern(QPen)), ui->frame_4, SLOT(slotChangePen(QPen)));

    emit signalChangePattern( QPen(QBrush(framecolor),framewidth,mypen));


}

void Dialog::getData(QColor* framecolor,Qt::PenStyle* mypen,int* framewidth)
{
    *framecolor=QColor(ui->SliderRed->value(),ui->SliderGreen->value(),ui->SliderBlue->value());
    *mypen=map[ui->comboBox->currentText()];
    *framewidth=ui->spinBox->value();
}


void Dialog::slotSomebodyChanged()
{
    QColor fcolor;
    int fwidth;
    Qt::PenStyle mpen;
    this->getData(&fcolor,&mpen,&fwidth);
    QPen newpen = QPen(QBrush(fcolor),fwidth,mpen);
    emit signalChangePattern(newpen);

}

Dialog::~Dialog()
{

}

