#include "LogBooks.h"
#include "ui_LogBooks.h"

LogBooks::LogBooks(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LogBooks)
{
    ui->setupUi(this);
}

LogBooks::~LogBooks()
{
    delete ui;
}
