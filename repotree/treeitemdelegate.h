#ifndef QTREEITEMDELEGATE_H
#define QTREEITEMDELEGATE_H

#include <QItemDelegate>
#include <QModelIndex>
#include <QStyleOptionViewItem>
#include <QPainter>

class TreeItemDelegate : public QItemDelegate
{
    Q_OBJECT
public:
    TreeItemDelegate(QWidget *parent = 0) : QItemDelegate(parent) {}
    void paint(QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index) const;
};

#endif // QTREEITEMDELEGATE_H
