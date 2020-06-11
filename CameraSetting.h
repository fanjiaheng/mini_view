#pragma once

#include <QWidget>
#include <QListWidget>
#include <string>
#include <vector>


namespace Ui {
class CameraSetting;
}

class CCameraSetting : public QWidget
{
    Q_OBJECT

public:
    explicit CCameraSetting(QWidget *parent = nullptr);
    ~CCameraSetting();

    void init();
    void pre();

protected:
    virtual void keyPressEvent(QKeyEvent *ev);

private:
    Ui::CameraSetting *ui;
};
