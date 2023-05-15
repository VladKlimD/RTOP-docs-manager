#ifndef TECHINFO_H
#define TECHINFO_H

#include <QWidget>
#include <QDebug>

#include "ObjectsDataBase.h"

namespace Ui {
class TechInfo;
}

class TechInfo : public QWidget
{
    Q_OBJECT

public:
    explicit TechInfo(ObjectsDataBase *objectsDataBase, QWidget *parent = nullptr);
    ~TechInfo();

    void setObjectIndex(int);

signals:
    void signal_objectIndexChanged();

protected:
    void slot_showObjectInfo();

private:
    Ui::TechInfo *m_ui;
    ObjectsDataBase *m_objectsDataBase;
    int m_objectIndex = 0;
};

#endif // TECHINFO_H
