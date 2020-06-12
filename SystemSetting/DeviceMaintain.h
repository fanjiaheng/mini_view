#pragma once

#include <QWidget>

namespace Ui {
class DeviceMaintain;
}

class CDeviceMaintain : public QWidget
{
    Q_OBJECT

public:
    explicit CDeviceMaintain(QWidget *parent = nullptr);
    ~CDeviceMaintain();

    void init();
    void pre();

protected:
    virtual void keyPressEvent(QKeyEvent *ev);

private:
    Ui::DeviceMaintain *ui;
};
