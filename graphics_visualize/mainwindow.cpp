#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsItem>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), m_interactionState(nullptr)
{
    ui->setupUi(this);
    m_scene = new QGraphicsScene(ui->graphicsView);
    ui->graphicsView->setScene(m_scene);

    // 设置初始交互状态为创建矩形状态
    m_interactionState = new CreateRectangleState(m_scene, ui->graphicsView);
    connect(ui->actioncreate_rectangle, &QAction::triggered, this, &MainWindow::on_actionCreate_Rectangle_triggered);
//    QGraphicsRectItem *rectItem = new QGraphicsRectItem(0, 0, 100, 50);
//    QGraphicsEllipseItem *ellipseItem = new QGraphicsEllipseItem(50, 50, 100, 50);
//    QGraphicsTextItem *textItem = new QGraphicsTextItem("Hello World");

//    scene->addItem(rectItem);
//    scene->addItem(ellipseItem);
//    scene->addItem(textItem);

//    QPen pen(Qt::red, 2); // 设置红色画笔，宽度2个像素
//    QBrush brush(Qt::green); // 设置绿色填充

//    rectItem->setPen(pen); // 将该笔刷应用于矩形
//    ellipseItem->setBrush(brush); // 将该刷子应用于椭圆

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (m_interactionState) {
        m_interactionState->mousePressEvent(event);
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (m_interactionState) {
        m_interactionState->mouseMoveEvent(event);
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (m_interactionState) {
        m_interactionState->mouseReleaseEvent(event);
    }
}

void MainWindow::on_actionCreate_Rectangle_triggered()
{
    delete m_interactionState;
    m_interactionState = new CreateRectangleState(m_scene, ui->graphicsView);
}
