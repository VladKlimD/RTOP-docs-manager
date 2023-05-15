#include "ObjectsDataBase.h"
#include "qvariant.h"

ObjectsDataBase::ObjectsDataBase(QObject *parent)
    : QObject{parent}
{

}

QMap<int, QString> ObjectsDataBase::getObjectNames()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./ObjectsDataBase/objectsDataBase.db");

    if (!db.open()) {
        return QMap<int, QString>();
    }

    QSqlQuery query("SELECT id, name FROM objectsNames", db);
    QMap<int, QString> objectMap;

    while (query.next())
    {
        int id = query.value(0).toInt();
        QString name = query.value(1).toString();
        objectMap[id] = name;
    }

    db.close();
    return objectMap;
}

QString ObjectsDataBase::getObjectInfo(int index, QString tableName)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./ObjectsDataBase/objectsDataBase.db");

    if (!db.open()) {
        return QString();
    }

    QSqlQuery query;
    query.prepare(QString("SELECT description FROM %1 WHERE id = :id").arg(tableName));
    query.bindValue(":id", index);

    QString description;

    if (query.exec())
    {
        if (query.next())
        {
            description = query.value(0).toString();
        }
    }

    return description;
}

QStringList ObjectsDataBase::getTableNames()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./ObjectsDataBase/objectsDataBase.db");

    if (!db.open()) {
        return QStringList();
    }

    QSqlQuery query(db);
    query.exec("SELECT name FROM sqlite_master WHERE type='table'");

    QStringList tableNames;
    while (query.next())
    {
        QString tableName = query.value(0).toString();
        if (tableName != "objectsNames")
            tableNames.append(tableName);
    }

    return tableNames;
}
