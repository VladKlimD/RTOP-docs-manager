#ifndef LOGBOOKS_H
#define LOGBOOKS_H

#include <QWidget>

namespace Ui {
class LogBooks;
}

class LogBooks : public QWidget
{
    Q_OBJECT

public:
    explicit LogBooks(QWidget *parent = nullptr);
    ~LogBooks();

private:
    Ui::LogBooks *ui;
};

#endif // LOGBOOKS_H
