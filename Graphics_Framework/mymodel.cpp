#include "mymodel.h"

MyModel::MyModel(QObject *parent) : QAbstractTableModel(parent)
{
    m_header_data<<"Color"<<"Style"<<"Width";

    map["Сплошная"]=Qt::SolidLine;
    map["Пунктир"]=Qt::DashLine;
    map["Точками"]=Qt::DotLine;
    map["Точка-тире"]=Qt::DashDotLine;
    map["Точка-точка-тире"]=Qt::DashDotDotLine;

    tmodel = new QSqlTableModel();
    connect (this->tmodel, SIGNAL(dataChanged(QModelIndex,QModelIndex)),this,SLOT(slotBdTableChanged(QModelIndex)) );

}


QVariant MyModel::data(const QModelIndex & index,int role)const
{
    //если индекс «недействительный», возвращаем пустой QVariant()
        if(!index. isValid())
            return QVariant();
        int row=index.row();
        if(row>=m_scetch.size())
               return QVariant();

    //индексу соответствует строка и столбец => разбираемся: для чего и в каком виде понадобилось значение
         switch(index.column())//выясняем–какой столбец
       {
           case 0://столбец с цветом
        switch(role)//выясняем–в каком виде хочет получить содержимое представление
            {
            case Qt::DecorationRole://если представление хочет получить иконку
            {
                QPixmap px(32,32);
                px.fill(m_scetch[row].color());
                return QIcon(px);
            }
        case Qt::EditRole://если представление хочет редактировать значение
                    //цвета
            case Qt::DisplayRole://если представление хочет получить значение цвета
                return m_scetch[row].color();
            }
        case 1://столбец со стилем
            switch(role)
            {
            case Qt::DisplayRole:
            {
                    //отображать хочется строку, поэтому можно воспользоваться, например
            //QString names[]={"Сплошная", "Пунктир", "Точками", "Точка-тире", "Точка-точка-тире"};
               //return names [m_scetch[row].style()];
                return map.key(m_scetch[row].style());
    //ЗАМЕЧАНИЕ:  А можно как и в диалоге настройки пера использовать map
            }
            case Qt::EditRole://а редактировать нужно значение
                return static_cast<uint>(m_scetch[row].style());
            }
        case 2://толщина
            switch(role)
            {
            case Qt::EditRole://представление для отображения и редактирования
                        //совпадают
            case Qt::DisplayRole:
                return m_scetch[row].width();
            }
       }

    return QVariant();//заглушка
}

int  MyModel ::rowCount (const QModelIndex & parent) const
{
    return m_scetch.size();//размер списка-это количество строк
}

int MyModel::columnCount(const QModelIndex & parent)const
{
 return m_header_data.count(); //пока можно задать константой (у нас 3 столбца–цвет, толщина, стиль. А в дальнейшем будем формировать это значение, исходя из числа заголовков
}

QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role)const
{
     if(role!=Qt::DisplayRole) //нас интересует ТОЛЬКО отображение заголовков
     return QVariant();//=>во всех остальных случаях ничего не делаем

     if(orientation==Qt::Horizontal)
     {//заголовки столбцов
        return m_header_data.at(section);
     }
     else
    {//заголовки строк
        return QString().setNum(section);//возвращаем номера строк
    }
}

bool MyModel::insertRows(int row, int count, const QModelIndex &parent)
{
    Q_UNUSED(parent);
    beginInsertRows(QModelIndex(),row,row+count-1);//диапазон вставляемых строк
    m_scetch.insert(row,count,MyRect()); //вставляем count «пустых» элементов
    endInsertRows();
    return true;
}

Qt::ItemFlags MyModel::flags(const QModelIndex & index)const
{
    Qt::ItemFlags f=QAbstractTableModel::flags(index); //текущие флаги
    return index.isValid()?(f|Qt::ItemIsEditable):f;//добавляем редактирование
}

bool MyModel::setData(const QModelIndex & index,const QVariant & val, int role)
{
    if(index.isValid()&&(role==Qt::EditRole))
    {
        int row=index.row();
        int column=index.column();
        //записываем данные в соответствующий столбец
        switch(column)
        {
            case 0:
               // значение, заданное QVariant преобразуем в QColor
           m_scetch[row].setColor(val.value<QColor>());//цвет
           break;
            case 1: //стиль
               // значение, заданное QVariant преобразуем  сначала в int,
           //  а потом в Qt::PenStyle
           m_scetch[row].setStyle(static_cast<Qt::PenStyle>(val.toInt()));
           break;
            case 2:
               // значение, заданное QVariant преобразуем  в uint,
             m_scetch[row].setWidth(val.toUInt());//толщина
            break;

        }
    emit(dataChanged(index,index));//После того, как данные установлены, модель должна дать знать представлениям, что некоторые данные  изменены. Модель делает это, эмитируя сигнал dataChanged().
//Важно! Так как у нас изменяется только один элемент данных, указанный в сигнале диапазон элементов данных ограничен одним модельным индексом.

    emit signalShapeChanged(m_scetch[row].rect(), m_scetch[row].color(), m_scetch[row].width(), m_scetch[row].style());
    //Здесь же нужно будет оповестить сцену об изменениях
    return true;
}
return false;
}

bool MyModel::removeRows(int row, int count, const QModelIndex &parent)
{
    Q_UNUSED(parent);

    beginRemoveRows(QModelIndex(),row,row+count-1);//диапазон удаляемых строк
    m_scetch.remove(row,count); //удаляем count «пустых» элементов
    endRemoveRows();
    return true;
}


void MyModel::slotNewShape(QRectF r,QColor c,uint w,Qt::PenStyle st)
{
    //Создаем новую «пустую» строку
        insertRows(rowCount(),1, QModelIndex());//вставляем в конец таблицы
        m_scetch[rowCount()-1]=MyRect(r,c,w,st);
}

void  MyModel::slotActivated (QModelIndex index)
{
    emit signalActivated(m_scetch[index.row()].rect());
}

void MyModel::slotClear()
{
    if(rowCount()>0)
    {
      bool b= removeRows(0,rowCount(QModelIndex()),QModelIndex());
      emit signalClear();
    }
}

void MyModel::slotSave()
{
    QString fileName = QFileDialog::getSaveFileName();
    if (!fileName.contains(".txt"))
        fileName += ".txt";
    QFile file(fileName);

    if(file.open(QFile::WriteOnly|QFile::Text))
    {
        for(int i=0;i<rowCount();++i)
        {
        // Формат данных: Цвет Стиль Толщина Прямоугольник (x,y,width, height)
        QStringList pieces;
        //добавляем Цвет
        pieces.append(m_scetch[i].color().name());//цвет в формате #RRGGBB
        // добавляем Стиль
        pieces.append(QString().setNum(static_cast<int>(m_scetch[i].style())));
        // добавляем Толщину пера
        pieces.append(QString().setNum(static_cast<int>(m_scetch[i].width())));
        //Прямоугольник (x, y, width, height)
        pieces.append(QString::number(static_cast<int>(m_scetch[i].rect().x())));
        pieces.append(QString::number(static_cast<int>(m_scetch[i].rect().y())));
        pieces.append(QString::number(static_cast<int>(m_scetch[i].rect().width())));
        pieces.append(QString::number(static_cast<int>(m_scetch[i].rect().height())));
        // объединяем все «кусочки»
        QTextStream stream(&file);
        stream<<pieces.join(",")<<"\n";
        }
    }
    file.close();
}

void MyModel::slotOpen()
{
    //bool b= removeRows(0,rowCount(QModelIndex()),QModelIndex());
    //emit signalClear();
    QString fileName = QFileDialog::getOpenFileName();
    QFile file(fileName);
    if(file.open(QFile::ReadOnly|QFile::Text))
    {
        QTextStream stream(&file);
        //Закачиваем данные в scetch
        int row=0;
        QString line;
        do
        {
            line=stream.readLine();
            if(!line.isEmpty())
            {
                //добавляем в таблицу одну строку
                insertRows(row,1,QModelIndex());
                //считываем очередную фигуру в scetch
                QStringList pieces=line.split(",",QString::SkipEmptyParts);
                // Формат данных: Цвет Стиль Толщина Прямоугольник (x,y,width, height), тип фигуры

                //считываем цвет
                QString temp =pieces.value(0);
                QColor color;
                color.setNamedColor(temp);
                m_scetch[row].setColor(color);

                // считываем стиль
                temp =pieces.value(1);
                Qt::PenStyle style = static_cast<Qt::PenStyle>(temp.toInt());
                m_scetch[row].setStyle(style);
                // считываем толщину
                temp =pieces.value(2);
                int width = temp.toInt();
                m_scetch[row].setWidth(width);
                // считываем  параметры прямоугольника x,y,width,height и
                 //формируем прямоугольник
                QRectF tmpr;
                int rx=pieces.value(3).toInt();
                int ry=pieces.value(4).toInt();
                int rw=pieces.value(5).toInt();
                int rh=pieces.value(6).toInt();
                tmpr=QRectF(rx,ry,rw,rh);
                m_scetch[row].setRect(tmpr);

                //эмитируем сигнал о том, что в модель добавлена фигура
                emit(signalAddShape(tmpr,color,width,style));
                row++;
            }
        }while(!line.isEmpty());
        file.close();
    }
}

void MyModel::slotCreateConnection()
{
    db = QSqlDatabase::addDatabase("QSQLITE"); // активизируем  драйвер
    db.setDatabaseName("mydb.sqlite"); //указываем имя БД  - настраиFsetваем соединение.
    db.open();			               // - открываем соединение


}

void MyModel::slotCreateTable()
{
    QString qstr = "CREATE TABLE rectangle("
        "id INTEGER  PRIMARY KEY, "
        "color VARCHAR,"
        "pen_style  UNSIGNED,"
        "pen_width UNSIGNED,"
        "left DOUBLE,"
        "top DOUBLE,"
        "width DOUBLE,"
        "height DOUBLE)";
    QSqlQuery q;  //соединение не указано, используем соединение по умолчанию
    bool b= q.exec(qstr);


}

void MyModel::slotWrite()
{
      //соединение с БД не указано=> используется  соединение по умолчанию.
    for(int i=0;i<rowCount();++i)
    {
        QSqlQuery  q;
    QString qstr1="INSERT INTO  rectangle(id, color, pen_style, pen_width, left, top, width, height)"
     "VALUES(?,?,?,?,?,?,?,?)";
    q.prepare(qstr1);
    q.addBindValue(i);
    q.addBindValue(m_scetch[i].color().name());
    q.addBindValue(QString().setNum(static_cast<int>(m_scetch[i].style())));
    q.addBindValue(m_scetch[i].width());
    q.addBindValue(m_scetch[i].rect().x());
    q.addBindValue(m_scetch[i].rect().y());
    q.addBindValue(m_scetch[i].rect().width());
    q.addBindValue(m_scetch[i].rect().height());
    q.exec();
    }

}

void MyModel::slotRead()
{
    slotClear();

    QSqlQuery q;
    q.exec("SELECT * FROM rectangle");
    while (q.next())
    {
    //int id=q.value(q.record().indexOf("id")).toInt();
    QString colorStr = q.value(q.record().indexOf("color")).toString();
    QColor color;
    color.setNamedColor(colorStr);
    //m_scetch[id].setColor(color);

    // считываем стиль
    QString temp =q.value(q.record().indexOf("pen_style")).toString();
    Qt::PenStyle style = static_cast<Qt::PenStyle>(temp.toInt());
    //m_scetch[id].setStyle(style);
    // считываем толщину
    temp =q.value(q.record().indexOf("pen_width")).toString();
    int width = temp.toInt();
    //m_scetch[id].setWidth(width);
    // считываем  параметры прямоугольника x,y,width,height и
     //формируем прямоугольник
    QRectF tmpr;
    int rx=q.value(q.record().indexOf("left")).toInt();
    int ry=q.value(q.record().indexOf("top")).toInt();
    int rw=q.value(q.record().indexOf("width")).toInt();
    int rh=q.value(q.record().indexOf("height")).toInt();
    tmpr=QRectF(rx,ry,rw,rh);
    //m_scetch[id].setRect(tmpr);

    //эмитируем сигнал о том, что в модель добавлена фигура

    slotNewShape(tmpr,color,width,style);
    emit signalAddShape(tmpr,color,width,style);
    }

}

void MyModel::slotQueryModel()
{
    slotClear();

    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery ("SELECT * FROM rectangle");
    if (model->lastError().isValid())
    {
        qDebug() << model->lastError();
        return ;
    }

    for (int i = 0; i < model->rowCount(); i++)
    {
    int id=model->data(model->index(i,0)).toUInt();
          QString colorStr=model->data(model->index(i,1)).toString();
          QColor color;
     color.setNamedColor(colorStr);
     //использование значений – копирование в модель MyModel
    //. . .
     // считываем стиль
     QString temp =model->data(model->index(i,2)).toString();
     Qt::PenStyle style = static_cast<Qt::PenStyle>(temp.toInt());
     //m_scetch[id].setStyle(style);
     // считываем толщину
     temp =model->data(model->index(i,3)).toString();
     int width = temp.toInt();
     //m_scetch[id].setWidth(width);
     // считываем  параметры прямоугольника x,y,width,height и
      //формируем прямоугольник
     QRectF tmpr;
     int rx=model->data(model->index(i,4)).toInt();
     int ry=model->data(model->index(i,5)).toInt();
     int rw=model->data(model->index(i,6)).toInt();
     int rh=model->data(model->index(i,7)).toInt();
     tmpr=QRectF(rx,ry,rw,rh);
     //m_scetch[id].setRect(tmpr);


     slotNewShape(tmpr,color,width,style);
     emit signalAddShape(tmpr,color,width,style);
    }

    QTableView *view = new QTableView();
     view->setModel(model);
     view->show();




}

void MyModel::slotTableModel()
{
    slotClear();

    QSqlTableModel *model= new QSqlTableModel();
    model->setTable("rectangle");
    model->select();

    for (int i = 0; i < model->rowCount(); i++)
    {
      int id=model->data(model->index(i,0)).toUInt();
      QString colorStr=model->data(model->index(i,1)).toString();
      QColor color;
     color.setNamedColor(colorStr);
     //использование значений – копирование в модель MyModel
     //. . .
     // считываем стиль
     QString temp =model->data(model->index(i,2)).toString();
     Qt::PenStyle style = static_cast<Qt::PenStyle>(temp.toInt());
     //m_scetch[id].setStyle(style);
     // считываем толщину
     temp =model->data(model->index(i,3)).toString();
     int width = temp.toInt();
     //m_scetch[id].setWidth(width);
     // считываем  параметры прямоугольника x,y,width,height и
      //формируем прямоугольник
     QRectF tmpr;
     int rx=model->data(model->index(i,4)).toInt();
     int ry=model->data(model->index(i,5)).toInt();
     int rw=model->data(model->index(i,6)).toInt();
     int rh=model->data(model->index(i,7)).toInt();
     tmpr=QRectF(rx,ry,rw,rh);
     //m_scetch[id].setRect(tmpr);



     slotNewShape(tmpr,color,width,style);
     emit signalAddShape(tmpr,color,width,style);
    }

    QTableView *view = new QTableView();
     view->setModel(model);
     view->show();

}


void MyModel::slotBdTableChanged(const QModelIndex &index_tmodel)
{
    slotActivated(index_tmodel);


    //tmodel->setData(index_tmodel, m_scetch[index_tmodel].color());
   // tmodel->setData(index_tmodel, m_scetch[index_tmodel].width());
    //tmodel->setData(index_tmodel, m_scetch[index_tmodel].style());




}




