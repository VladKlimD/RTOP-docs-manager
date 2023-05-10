#ifndef TECHINFO_H
#define TECHINFO_H

#include <QWidget>

namespace Ui {
class TechInfo;
}

class TechInfo : public QWidget
{
    Q_OBJECT

public:
    explicit TechInfo(QWidget *parent = nullptr);
    ~TechInfo();

    void setObjectIndex(int);

private:
    Ui::TechInfo *ui;
    int m_objectIndex = 0;
};

#endif // TECHINFO_H
