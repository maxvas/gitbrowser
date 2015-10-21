#include "qjsmodel.h"
#include <QtAlgorithms>
#include <QHash>

QJSModel::QJSModel(const QJS &data, QObject *parent)
    : QAbstractItemModel(parent)
{
    rootItem = new QJS(data);
}

QJSModel::~QJSModel()
{

}

QVariant QJSModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    QJS *item = static_cast<QJS*>(index.internalPointer());
    if (role == Qt::DisplayRole)
        return item->get("name").toString();
    if (role == Qt::DecorationRole)
    {
        QString type = item->get("type").toString();
        if (!m_itemIcons.contains(type))
            return QVariant();
        return m_itemIcons[type];
    }

    return QVariant();
}

Qt::ItemFlags QJSModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return 0;

    return QAbstractItemModel::flags(index);
}

QVariant QJSModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return rootItem->get("name").toString();

    return QVariant();
}

QModelIndex QJSModel::index(int row, int column, const QModelIndex &parent) const
{
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    QJS *parentItem;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<QJS*>(parent.internalPointer());

    QHash<QString, QJS* > children;
    QStringList childrenNames;
    foreach(QJS *item, parentItem->get("children").toArray())
    {
        QString name = item->get("name").toString();
        children[name] = item;
        childrenNames.append(name);
    }
    qSort(childrenNames);
    QString name = childrenNames[row];

    QJS *childItem = children[name];
    if (childItem)
        return createIndex(row, column, childItem);
    else
        return QModelIndex();
}

QModelIndex QJSModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    QJS *childItem = static_cast<QJS*>(index.internalPointer());
    QJS *parentItem = childItem->parent()->parent();

    if (parentItem == rootItem)
        return QModelIndex();
    QJS* grandparentItem = parentItem->parent()->parent();
    QStringList childrenNames;
    foreach(QJS *item, grandparentItem->get("children").toArray())
    {
        QString name = item->get("name").toString();
        childrenNames.append(name);
    }
    qSort(childrenNames);
    int row = childrenNames.indexOf(parentItem->get("name").toString());
    return createIndex(row, 0, parentItem);
}

int QJSModel::rowCount(const QModelIndex &parent) const
{
    QJS *parentItem;
    if (parent.column() > 0)
        return 0;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<QJS*>(parent.internalPointer());

    int size = parentItem->get("children").size();
    return size;
}

int QJSModel::columnCount(const QModelIndex &parent) const
{
    return 1;
}

void QJSModel::setIcon(QString type, QString url)
{
    QImage image(url);
    m_itemIcons[type] = image;
}
