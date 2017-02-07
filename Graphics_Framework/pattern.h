#ifndef PATTERN_H
#define PATTERN_H

#include <QWidget>
#include <QFrame>
#include <QPen>
#include<QPainter>
#include<QSize>


class Pattern : public QFrame
{
    Q_OBJECT
public:
    explicit Pattern(QFrame * fr=0);
    void paintEvent(QPaintEvent* event);

signals:

public slots:
    void slotChangePen(QPen newPen);

private:
    QPen patternpen;
};

#endif // PATTERN_H
