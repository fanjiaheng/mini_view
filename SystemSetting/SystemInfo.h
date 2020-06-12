#pragma once

#include <QWidget>

namespace Ui {
class SystemInfo;
}

class CSystemInfo : public QWidget
{
    Q_OBJECT

public:
    explicit CSystemInfo(QWidget *parent = nullptr);
    ~CSystemInfo();

    void init();
    void pre();

protected:
    virtual void keyPressEvent(QKeyEvent *ev);

private:
    Ui::SystemInfo *ui;
};
