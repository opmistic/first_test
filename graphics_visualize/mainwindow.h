#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QGraphicsScene>
#include "interactionstate.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;


private slots:
    void on_actionCreate_Rectangle_triggered();
    //void on_actionMove_Text_triggered();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *m_scene;
    InteractionState *m_interactionState; // 当前的交互状态


};
#endif // MAINWINDOW_H
