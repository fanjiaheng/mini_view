#pragma once

#include <QWidget>
#include <QListWidget>
#include <string>
#include <vector>


namespace Ui {
class SystemSetting;
}

class CSystemSetting : public QWidget
{
    Q_OBJECT

public:
    explicit CSystemSetting(QWidget *parent = nullptr);
    ~CSystemSetting();

    void init();
    void pre();

protected:
    virtual void keyPressEvent(QKeyEvent *ev);

private:
    Ui::SystemSetting *ui;
};
