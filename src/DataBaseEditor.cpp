#include "DataBaseEditor.h"
#include "ui_DataBaseEditor.h"

DataBaseEditor::DataBaseEditor(ObjectsDataBase *objectsDataBase, QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::DataBaseEditor)
{
    m_ui->setupUi(this);
    m_objectsDataBase = objectsDataBase;
    slot_setTableNamesFromDataBase();
    slot_initTables();
}

DataBaseEditor::~DataBaseEditor()
{
    delete m_ui;
}

void DataBaseEditor::slot_setTableNamesFromDataBase()
{
    m_tablesNames = m_objectsDataBase->getTableNames();
    for (auto& tableName : m_tablesNames)
    {
        if (tableName == "objectsInfo")
        {
            tableName = "СВЕДЕНИЯ ОБ ОБЪЕКТЕ";
        }
        else if (tableName == "techService")
        {
            tableName = "ТЕХНИЧЕСКОЕ ОБСЛУЖИВАНИЕ";
        }
        else if (tableName == "faultsAndFixes")
        {
            tableName = "НЕИСПРАВНОСТИ ПО СИСТЕМАМ И СПОСОБЫ ИХ УСТРАНЕНИЯ";
        }
    }
}

void DataBaseEditor::slot_initTables()
{
    for (auto& tableName : m_tablesNames)
    {
        m_ui->tabWidgetTables->addTab(new QWidget(this), tableName);
    }
}
