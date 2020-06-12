#pragma once

#include <QWidget>

namespace Ui {
class PlatformSetting;
}

class CPlatformSetting : public QWidget
{
    Q_OBJECT

public:
    explicit CPlatformSetting(QWidget *parent = nullptr);
    ~CPlatformSetting();

    void init();
    void pre();

protected:
    virtual void keyPressEvent(QKeyEvent *ev);

private:
    Ui::PlatformSetting *ui;
};
