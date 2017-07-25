#ifndef FULLSCREENTOPFRAME_H
#define FULLSCREENTOPFRAME_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}
class MainWindow;

class FullscreenTopFrame : public QMainWindow
{
public:
    explicit FullscreenTopFrame(MainWindow* mainWindow, Ui::MainWindow *ui, QWidget *parent = 0);
    ~FullscreenTopFrame();
    void changeEvent(QEvent *event) override;
    void moveEvent(QMoveEvent *event) override;
    bool nativeEvent(const QByteArray &, void *, long *) override;
    void closeEvent(QCloseEvent *event) override;

    void closeAndShowNormal();
    bool isValid() { return m_valid; }


private:
    MainWindow* m_mainWindow;
    Ui::MainWindow *ui;
    bool m_wasFullscreen;
    bool m_mouseleft;
    int initializeCount;
    bool m_toShowNormal;
    bool m_valid;
};

#endif // FULLSCREENTOPFRAME_H