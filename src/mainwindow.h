#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStatusBar>
#include <QComboBox>

#include "ObjectsDataBase.h"
#include "TechInfo.h"
#include "LogBooks.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonTechInfo_clicked();
    void on_comboBoxObjectList_activated(int index);
    void on_pushButtonLogBooks_clicked();
    void on_pushButtonToMainPage_clicked();
    void on_comboBoxObjectList_currentIndexChanged(int index);

private:
    Ui::MainWindow *m_ui;

    ObjectsDataBase *m_objectsDataBase = new ObjectsDataBase(this);
    TechInfo *m_techInfo = new TechInfo(m_objectsDataBase, this);
    LogBooks *m_logBooks = new LogBooks(this);
    QMap<int, QString> m_objectNames;

    void setComboBoxItemMargin(QComboBox* cb, int m);
};
#endif // MAINWINDOW_H
