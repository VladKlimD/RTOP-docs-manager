#include "TechInfo.h"
#include "ui_TechInfo.h"

TechInfo::TechInfo(ObjectsDataBase *objectsDataBase, QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::TechInfo)
{
    m_ui->setupUi(this);
    m_objectsDataBase = objectsDataBase;

    connect(this, &TechInfo::signal_objectIndexChanged,
            this, &TechInfo::slot_showObjectInfo);
}

TechInfo::~TechInfo()
{
    delete m_ui;
}

void TechInfo::setObjectIndex(int objectIndex)
{
    m_objectIndex = objectIndex;
    emit signal_objectIndexChanged();
}

void TechInfo::slot_showObjectInfo()
{
    m_ui->textEditObjectInfo->setHtml(m_objectsDataBase->getObjectInfo(m_objectIndex, "objectsInfo"));
}
