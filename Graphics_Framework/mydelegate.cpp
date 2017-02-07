#include "mydelegate.h"

MyDelegate::MyDelegate(QObject *parent) : QStyledItemDelegate(parent)
{
    map["Сплошная"]=Qt::SolidLine;
    map["Пунктир"]=Qt::DashLine;
    map["Точками"]=Qt::DotLine;
    map["Точка-тире"]=Qt::DashDotLine;
    map["Точка-точка-тире"]=Qt::DashDotDotLine;

}

QWidget*MyDelegate::createEditor(QWidget*parent,const QStyleOptionViewItem & option,
                                 const QModelIndex & index)const
{
     if((index.column()==1)) //колонка со стилем
     {
       QComboBox*editor=new QComboBox(parent);//уничтожать позже не нужно, объект будет
                                                 //уничтожен автоматически
//          //строки, которые будут выводиться пользователю
//        QString strType[]={"NoPen", "SolidLine", "DashLine", "DotLine", "DashDotLine"};
//        //ассоциированные данные
//        int s[]={Qt::NoPen,Qt::SolidLine,Qt::DotLine,Qt::DashLine,Qt::DashDotLine};
//        //
//        for(int i=0;i<sizeof(strType)/sizeof(QString);i++)
//        {
//            editor->addItem(strType[i],s[i]);
//        }
       foreach (QString str, map.keys())
       {
           editor->addItem(str);
       }
//ЗАМЕЧАНИЕ:  А можно как и в диалоге настройки пера использовать map
        return editor;
}
else
   return QStyledItemDelegate::createEditor(parent,option,index);
}

void MyDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    if(index.column()==1)  //колонка со стилем
    {
        //выделить текущую позицию
        QComboBox * styleEditor= qobject_cast<QComboBox*>(editor);
        if(styleEditor)
        {
       //получаем из модели данное, соответствующее стилю пера и делаем текущим
           //соответствующее значение comboBox
        }
    }else
    QStyledItemDelegate::setEditorData(editor,index);
}

//Вызывается, когда пользователь переходит в другую ячейку или нажимает Enter
void MyDelegate::setModelData(QWidget*editor, QAbstractItemModel * model,
                                          const QModelIndex & index)const
{
   if(index.column()==1) //колонка со стилем
   {
     QComboBox * styleEditor= qobject_cast<QComboBox*>(editor);
     if(styleEditor)
     {
      //получаем из comboBox значение стиля
      int style=static_cast<int>(map[styleEditor->currentText()]);
       //. . .
     //и устанавливаем его в модели модели
     model->setData(index,style);//
 //delete styleEditor;//необязательно
   }
 }else
     QStyledItemDelegate::setModelData(editor,model,index);
}

bool MyDelegate::editorEvent(QEvent*event,QAbstractItemModel*model,
           const QStyleOptionViewItem&option,const QModelIndex&index)
{
    if(event->type()==QEvent::MouseButtonDblClick)
    {
        QMouseEvent * me=static_cast<QMouseEvent*>(event);
        if(me->button()==Qt::LeftButton)
        {
        //вызываем QColorDialog
        int col=index.column();
        int row=index.row();
        if(col==0)//колонка выбора цвета
        {
          QColor tempColor=QColorDialog::getColor();
          if(tempColor.isValid())//OK
          {
          //заносим цвет
           return model->setData(model->index(row,0),tempColor);
                  //Qt::EditRole-по умолчанию
           }
           return true;
        }
          }
   }
  return QStyledItemDelegate::editorEvent(event,model,option,index);
}





