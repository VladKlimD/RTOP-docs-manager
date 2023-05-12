#ifndef OBJECTSDATABASE_H
#define OBJECTSDATABASE_H

#include <QObject>
#include <QMap>
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>

class ObjectsDataBase : public QObject
{
    Q_OBJECT
public:
    explicit ObjectsDataBase(QObject *parent = nullptr);

    QMap<int, QString> getObjectNames();

signals:
    void signal_messageToStatusBar(QString);
};

#endif // OBJECTSDATABASE_H
