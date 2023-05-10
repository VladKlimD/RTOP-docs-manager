#include "JsonParser.h"

JsonParser::JsonParser(QObject *parent)
    : QObject{parent}
{

}

QMap<int, QString> JsonParser::getObjectNames()
{
    QJsonObject jsonObject = getJsonObject("./ObjectsDataBase/objectsNames.json");

    if (!jsonObject.contains("objects")) {
        return QMap<int, QString>();
    }

    QMap<int, QString> objectMap;

    QJsonArray objects = jsonObject.value("objects").toArray();
    foreach (const QJsonValue& value, objects) {
        QJsonObject obj = value.toObject();
        int id = obj.value("id").toInt();
        QString name = obj.value("name").toString();
        objectMap[id] = name;
    }

    return objectMap;
}

QJsonObject JsonParser::getJsonObject(QString filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return QJsonObject();
    }

    QString json = file.readAll();
    file.close();

    QJsonDocument jsonDocument = QJsonDocument::fromJson(json.toUtf8());

    QJsonObject jsonObject = jsonDocument.object();
    return jsonObject;
}
