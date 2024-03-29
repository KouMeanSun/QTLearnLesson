#ifndef MYLISTMODEL_H
#define MYLISTMODEL_H

#include <QAbstractListModel>

class Animal
{
public:
    Animal(const QString &type, const QString &size);
    QString type() const;
    QString size() const;
private:
    QString m_type;
    QString m_size;
};

class MyListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum AnimalRoles {
        TypeRole = Qt::UserRole + 1,
        SizeRole
    };
    explicit MyListModel(QObject *parent = nullptr);

    void addAnimal(const Animal &animal);
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;

protected:
    QHash<int, QByteArray> roleNames() const;

private:
    QList<Animal> m_animals;
};

#endif // MYLISTMODEL_H
