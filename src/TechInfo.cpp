#include "TechInfo.h"
#include "ui_TechInfo.h"

TechInfo::TechInfo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TechInfo)
{
    ui->setupUi(this);
}

TechInfo::~TechInfo()
{
    delete ui;
}

void TechInfo::setObjectIndex(int objectIndex)
{
    m_objectIndex = objectIndex;
}
