#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

#include "style.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , m_ui(new Ui::MainWindow)
{
    m_ui->setupUi(this);
    setStyleSheet(STYLE_COMBINEAR_THEME);

    setStatusBar(m_statusBar);
    m_ui->verticalLayout_3->setContentsMargins(0, 0, 0, 0);
    m_ui->verticalLayout_3->setAlignment(Qt::AlignTop);

    m_objectNames = m_objectsDataBase->getObjectNames();
    m_ui->comboBoxObjectList->addItems(m_objectNames.values());

    m_ui->verticalSpacerTop->changeSize(0, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
    m_ui->verticalSpacerBottom->changeSize(0, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

    m_ui->stackedWidget->addWidget(m_logBooks);
    m_ui->stackedWidget->addWidget(m_techInfo);



    connect(m_objectsDataBase, &ObjectsDataBase::signal_messageToStatusBar,
            this, &MainWindow::slot_putMessageToStatusBar);
}

MainWindow::~MainWindow()
{
    delete m_ui;
}

void MainWindow::on_pushButtonToMainPage_clicked()
{
    m_ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButtonLogBooks_clicked()
{
    m_ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButtonTechInfo_clicked()
{
    m_ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_comboBoxObjectList_activated(int index)
{
    qDebug() << index + 1;
    m_techInfo->setObjectIndex(index + 1);
    m_ui->pushButtonLogBooks->setEnabled(true);
    m_ui->pushButtonTechInfo->setEnabled(true);
}

void MainWindow::slot_putMessageToStatusBar(QString message)
{
    m_statusBar->showMessage(message);
}


void MainWindow::on_comboBoxObjectList_currentIndexChanged(int index)
{
    m_techInfo->setObjectIndex(index);
}
