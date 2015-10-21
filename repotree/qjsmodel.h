#ifndef QJSMODEL_H
#define QJSMODEL_H

#include <QAbstractItemModel>
#include <QModelIndex>
#include <QVariant>
#include <QJS>
#include <QIcon>
#include <QHash>

class TreeItem;

class QJSModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit QJSModel(const QJS &data, QObject *parent = 0);
    ~QJSModel();

    QVariant data(const QModelIndex &index, int role) const Q_DECL_OVERRIDE;
    Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    QModelIndex parent(const QModelIndex &index) const Q_DECL_OVERRIDE;
    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    void setIcon(QString type, QString url);

private:
    QJS *rootItem;
    QHash<QString, QImage> m_itemIcons;

};

#endif // QJSMODEL_H
