#pragma once

#include <QWidget>
#include <QListWidget>
#include <string>
#include <vector>


namespace Ui {
class NetSetting;
}

class CNetSetting : public QWidget
{
    Q_OBJECT

public:
    explicit CNetSetting(QWidget *parent = nullptr);
    ~CNetSetting();

    void init();
    void pre();

protected:
    virtual void keyPressEvent(QKeyEvent *ev);

private:
    Ui::NetSetting *ui;
};
