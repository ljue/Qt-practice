#ifndef MYDELEGATE_H
#define MYDELEGATE_H

#include <QObject>
#include <QWidget>
#include <QComboBox>
#include <QStyledItemDelegate>
#include <QModelIndex>
#include <QAbstractTableModel>
#include <QEvent>
#include <QMouseEvent>
#include <QColorDialog>

class MyDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit MyDelegate(QObject *parent = 0);

    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    void setEditorData(QWidget*editor,  const QModelIndex & index)const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,const QModelIndex & index) const;

protected:
    bool editorEvent (QEvent*event, QAbstractItemModel*model, const QStyleOptionViewItem &option, const QModelIndex&index);


signals:

public slots:

private:
    QMap<QString, Qt::PenStyle> map;
};

#endif // MYDELEGATE_H
