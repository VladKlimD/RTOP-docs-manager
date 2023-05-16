#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QStyledItemDelegate>

#include "style.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_ui(new Ui::MainWindow)
{
    m_ui->setupUi(this);
    setStyleSheet(STYLE_COMBINEAR_THEME);

    m_ui->verticalLayout_3->setContentsMargins(0, 0, 0, 0);
    m_ui->verticalLayout_3->setAlignment(Qt::AlignTop);

    m_objectNames = m_objectsDataBase->getObjectNames();
    m_ui->comboBoxObjectList->addItems(m_objectNames.values());
    setComboBoxItemMargin(m_ui->comboBoxObjectList, 5);

    slot_setStackedWidgetOnCenter();

    m_ui->stackedWidget->addWidget(m_logBooks);
    m_ui->stackedWidget->addWidget(m_techInfo);
    m_ui->stackedWidget->addWidget(m_dataBaseEditor);
}

MainWindow::~MainWindow()
{
    delete m_ui;
}

void MainWindow::on_pushButtonToMainPage_clicked()
{
    slot_setStackedWidgetIndex(MainPage);
}

void MainWindow::on_pushButtonLogBooks_clicked()
{
    slot_setStackedWidgetIndex(LogBooksPage);
}

void MainWindow::on_pushButtonTechInfo_clicked()
{
    slot_setStackedWidgetIndex(TechInfoPage);
}

void MainWindow::on_pushButtonEditDataBase_clicked()
{
    slot_setStackedWidgetIndex(EditDataBasePage);
}

void MainWindow::on_comboBoxObjectList_activated(int index)
{
    m_techInfo->setObjectIndex(index + 1);
    m_ui->pushButtonLogBooks->setEnabled(true);
    m_ui->pushButtonTechInfo->setEnabled(true);
}

void MainWindow::on_comboBoxObjectList_currentIndexChanged(int index)
{
    m_techInfo->setObjectIndex(index);
}

void MainWindow::slot_setStackedWidgetOnTop()
{
    m_ui->verticalSpacerTop->changeSize(0, 20, QSizePolicy::Maximum, QSizePolicy::Maximum);
    m_ui->verticalSpacerBottom->changeSize(0, 20, QSizePolicy::Maximum, QSizePolicy::Maximum);
}

void MainWindow::slot_setStackedWidgetOnCenter()
{
    m_ui->verticalSpacerTop->changeSize(0, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
    m_ui->verticalSpacerBottom->changeSize(0, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
}

void MainWindow::slot_setStackedWidgetIndex(StackedWidgetPages currentIndex)
{
    switch (currentIndex)
    {
    case MainPage:
        slot_setStackedWidgetOnCenter();
        m_ui->stackedWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Maximum);
        break;
    default:
        slot_setStackedWidgetOnTop();
        m_ui->stackedWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        break;
    }
    m_ui->stackedWidget->setCurrentIndex(static_cast<int>(currentIndex));
}

void MainWindow::setComboBoxItemMargin(QComboBox *cb, int m)
{
    cb->setItemDelegate(new QStyledItemDelegate(cb));
    cb->setStyleSheet(QString("QListView::item { margin: %1px }").arg(m));
}

