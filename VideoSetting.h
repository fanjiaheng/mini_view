#pragma once

#include <QWidget>
#include <QListWidget>
#include <string>
#include <vector>


namespace Ui {
class VideoSetting;
}

class CVideoSetting : public QWidget
{
    Q_OBJECT

public:
    explicit CVideoSetting(QWidget *parent = nullptr);
    ~CVideoSetting();

    void init();
    void pre();

    void clearListWidgetItem();

signals:
    void signalShowResolutionList(void);
    void signalShowVideoCodeList(void);
    void signalSetResolution(QString val);
    void signalSetVideoCode(QString val);

private slots:
    void slotShowResolutionList(void);
    void slotShowVideoCodeList(void);
    void slotSetResolution(QString val);
    void slotSetVideoCode(QString val);

protected:
    virtual void keyPressEvent(QKeyEvent *ev);

private:
    Ui::VideoSetting *ui;
    std::string m_resolution = "1920*1080 30P";
    std::string m_videoCode = "H.264";
    QListWidget *m_listWidget;
    bool m_showSetVal = false;
};
