#include "treeitemdelegate.h"
#include <QRadialGradient>

void TreeItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    if (option.state & QStyle::State_Selected) {
        painter->save();
        QRect rect = option.rect;
        rect.setLeft(0);
        painter->setPen(Qt::NoPen);
        QColor c(Qt::blue);
        c.setAlpha(30);
        painter->setBrush(QBrush(c));
        painter->drawRect(rect);
        painter->restore();
    }
    painter->save();
    QString name = index.data(Qt::DisplayRole).toString();
    QFont f = option.font;
    QFontMetrics fm(f);
    QRect tr;
    tr = fm.boundingRect(name);
    painter->setFont(f);
    QImage img = index.data(Qt::DecorationRole).value<QImage>();
    if(!img.isNull())
    {
        QRect imgRect = QRect(option.rect.topLeft(), option.decorationSize);
        imgRect.setHeight(option.rect.height());
        imgRect.setWidth(imgRect.width()+10);
        imgRect = QStyle::alignedRect(option.direction, option.decorationAlignment,
                                           img.size(), imgRect);
        painter->drawImage(imgRect,img);
        QRect textRect = option.rect;
        textRect.setLeft(textRect.left()+imgRect.width()+10);
        painter->drawText(textRect, Qt::AlignVCenter | Qt::AlignLeft, name);
    }
    painter->restore();
//    QItemDelegate::paint(painter, option, index);
}
