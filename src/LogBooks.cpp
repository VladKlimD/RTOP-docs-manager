#include "LogBooks.h"
#include "ui_LogBooks.h"

LogBooks::LogBooks(ObjectsDataBase *objectsDataBase, QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::LogBooks)
{
    m_ui->setupUi(this);
    m_objectsDataBase = objectsDataBase;
}

LogBooks::~LogBooks()
{
    delete m_ui;
}
