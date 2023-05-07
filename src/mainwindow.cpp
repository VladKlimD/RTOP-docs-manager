#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "style.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setStyleSheet(STYLE_SPYBOT_THEME);
}

MainWindow::~MainWindow()
{
    delete ui;
}

