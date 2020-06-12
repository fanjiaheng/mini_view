#pragma once

#include <QWidget>

namespace Ui {
class EventManage;
}

class CEventManage : public QWidget
{
    Q_OBJECT

public:
    explicit CEventManage(QWidget *parent = nullptr);
    ~CEventManage();

    void init();
    void pre();

protected:
    virtual void keyPressEvent(QKeyEvent *ev);

private:
    Ui::EventManage *ui;
};
