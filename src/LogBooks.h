#ifndef LOGBOOKS_H
#define LOGBOOKS_H

#include <QWidget>

#include "ObjectsDataBase.h"

namespace Ui {
class LogBooks;
}

class LogBooks : public QWidget
{
    Q_OBJECT

public:
    explicit LogBooks(ObjectsDataBase *objectsDataBase, QWidget *parent = nullptr);
    ~LogBooks();

private:
    Ui::LogBooks *m_ui;

    ObjectsDataBase *m_objectsDataBase;
};

#endif // LOGBOOKS_H
