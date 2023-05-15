#ifndef DATABASEEDITOR_H
#define DATABASEEDITOR_H

#include <QWidget>

#include "ObjectsDataBase.h"

namespace Ui {
class DataBaseEditor;
}

class DataBaseEditor : public QWidget
{
    Q_OBJECT

public:
    explicit DataBaseEditor(ObjectsDataBase *objectsDataBase, QWidget *parent = nullptr);
    ~DataBaseEditor();

private:
    Ui::DataBaseEditor *m_ui;

    ObjectsDataBase *m_objectsDataBase;
    QStringList m_tablesNames;

    void slot_setTableNamesFromDataBase();
    void slot_initTables();
};

#endif // DATABASEEDITOR_H
