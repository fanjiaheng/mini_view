#pragma once

#include <QWidget>

namespace Ui {
class DeviceManage;
}

class CDeviceManage : public QWidget
{
    Q_OBJECT

public:
    explicit CDeviceManage(QWidget *parent = nullptr);
    ~CDeviceManage();

    void init();
    void pre();

protected:
    virtual void keyPressEvent(QKeyEvent *ev);

private:
    Ui::DeviceManage *ui;
};
