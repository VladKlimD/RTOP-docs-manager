#ifndef JSONPARSER_H
#define JSONPARSER_H

#include <QObject>
#include <QMap>
#include <QString>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

class JsonParser : public QObject
{
    Q_OBJECT
public:
    explicit JsonParser(QObject *parent = nullptr);

    QMap<int, QString> getObjectNames();

private:
    QJsonObject getJsonObject(QString);

signals:

};

#endif // JSONPARSER_H
