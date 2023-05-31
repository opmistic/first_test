#ifndef INTERACTIONSTATE_H
#define INTERACTIONSTATE_H
#include <QMouseEvent>
#include <QGraphicsItem>
#include <QGraphicsView>
//状态模式
class InteractionState
{
public:
    InteractionState();
    virtual ~InteractionState() {}
    virtual void mousePressEvent(QMouseEvent *event) = 0;
    virtual void mouseMoveEvent(QMouseEvent *event) = 0;
    virtual void mouseReleaseEvent(QMouseEvent *event) = 0;
};

//创建矩形的具体交互类 CreateRectangleState：
//CreateRectangleState 继承自 InteractionState，并实现了处理鼠标事件的三个函数。在 mousePressEvent() 中，
//创建一个新的矩形图元，并将其添加到场景中。在 mouseMoveEvent() 中，计算鼠标移动到的位置，并更新矩形的大小和位置。
//在 mouseReleaseEvent() 中，清除指向矩形的指针。
class CreateRectangleState : public InteractionState {
public:
    CreateRectangleState(QGraphicsScene *scene, QGraphicsView *view)
        : m_scene(scene), m_view(view) {}

    void mousePressEvent(QMouseEvent *event) override {
        m_startPoint = event->pos();
        QPen pen(Qt::red, 2);
        m_rectItem->setPen(pen);
        m_rectItem = new QGraphicsRectItem(m_startPoint.x(), m_startPoint.y(), 0, 0);
        m_scene->addItem(m_rectItem);
    }

    void mouseMoveEvent(QMouseEvent *event) override {
        QPointF endPoint = m_view->mapToScene(event->pos());
        QRectF rect = QRectF(m_startPoint, endPoint).normalized();
        m_rectItem->setRect(rect);
    }

    void mouseReleaseEvent(QMouseEvent *event) override {
        m_rectItem = nullptr;
    }

private:
    QGraphicsScene *m_scene;
    QGraphicsView *m_view;
    QPointF m_startPoint;
    QGraphicsRectItem *m_rectItem;
};

#endif // INTERACTIONSTATE_H
