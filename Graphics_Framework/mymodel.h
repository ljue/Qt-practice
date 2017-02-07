#ifndef MYMODEL_H
#define MYMODEL_H

#include <QObject>
#include <QAbstractTableModel>
#include <QPixmap>
#include <QIcon>
#include <QMap>
#include <QFileDialog>
#include <QtSql>
#include <QTableView>
#include <QSqlTableModel>


#include "myrect.h"

class MyModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit MyModel(QObject *parent = 0);
    QVariant data (const QModelIndex & index , int role)const;
    int rowCount (const QModelIndex & parent=QModelIndex())const;
    int columnCount(const QModelIndex & parent)const;
    virtual QVariant headerData(int section, Qt::Orientation orientation,int role=Qt::DisplayRole) const;
    virtual bool insertRows(int row, int count, const QModelIndex &parent);
    Qt::ItemFlags flags(const QModelIndex & index)const;
    bool setData(const QModelIndex & index,const QVariant & val, int role);
    bool removeRows(int row, int count, const QModelIndex &parent);

signals:
    void signalActivated (QRectF rect);
    void signalShapeChanged (QRectF,QColor,uint,Qt::PenStyle);
    void signalClear();
    void signalAddShape(QRectF,QColor,uint,Qt::PenStyle);

public slots:
    void slotNewShape(QRectF,QColor,uint,Qt::PenStyle);
    void slotActivated (QModelIndex);
    void slotClear();
    void slotSave();
    void slotOpen();


    void slotCreateConnection();
    void slotCreateTable();
    void slotWrite();
    void slotRead();
    void slotQueryModel();
    void slotTableModel();
    void slotBdTableChanged(const QModelIndex &index_tmodel);

private:
    QVector<MyRect> m_scetch;
    QStringList m_header_data;//список заголовков столбцов
    QMap<QString, Qt::PenStyle> map;
    QSqlDatabase db;
    QSqlTableModel * tmodel;
};

#endif // MYMODEL_H
