#include "MyListModel.h"
Animal::Animal(const QString &type, const QString &size)
    : m_type(type), m_size(size)
{
}

QString Animal::type() const
{
    return m_type;
}

QString Animal::size() const
{
    return m_size;
}

MyListModel::MyListModel(QObject *parent)
    : QAbstractListModel(parent)
{

}
void MyListModel::addAnimal(const Animal &animal)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_animals << animal;
    endInsertRows();
}

int MyListModel::rowCount(const QModelIndex & parent) const {
    Q_UNUSED(parent);
    return m_animals.count();
}

QVariant MyListModel::data(const QModelIndex & index, int role) const {
    if (index.row() < 0 || index.row() >= m_animals.count())
        return QVariant();

    const Animal &animal = m_animals[index.row()];
    if (role == TypeRole)
        return animal.type();
    else if (role == SizeRole)
        return animal.size();
    return QVariant();
}

QHash<int, QByteArray> MyListModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[TypeRole] = "type";
    roles[SizeRole] = "size";
    return roles;
}
