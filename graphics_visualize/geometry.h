#ifndef JIHE_H
#define JIHE_H
#include <QPolygon>
#include <QPoint>
#include "shape.h"
#include <QWidget>
//点类
class Point : public Shape
{
public:
    Point();
    Point(int x, int y);

    // 实现 Shape 类的纯虚函数
    QColor borderColor() const override;
    void setBorderColor(const QColor& color) override;
    Qt::PenStyle borderStyle() const override;
    void setBorderStyle(Qt::PenStyle style) override;
    QColor fillColor() const override;
    void setFillColor(const QColor& color) override;
    Qt::BrushStyle fillStyle() const override;
    void setFillStyle(Qt::BrushStyle style) override;
    void draw(QPainter& painter) override;

    // 其他属性和访问函数

private:
    int m_x;
    int m_y;

};
//折线类
class Polyline : public Shape
{
public:
    Polyline();
    Polyline(const QPolygon& points);

    // 实现 Shape 类的纯虚函数
    QColor borderColor() const override;
    void setBorderColor(const QColor& color) override;
    Qt::PenStyle borderStyle() const override;
    void setBorderStyle(Qt::PenStyle style) override;
    QColor fillColor() const override;
    void setFillColor(const QColor& color) override;
    Qt::BrushStyle fillStyle() const override;
    void setFillStyle(Qt::BrushStyle style) override;
    void draw(QPainter& painter) override;

    // 其他属性和访问函数

private:
    QPolygon m_points;

};
//多边形类
class Polygon : public Shape
{
public:
    Polygon();

    // 实现 Shape 类的纯虚函数
    QColor borderColor() const override;
    void setBorderColor(const QColor& color) override;
    Qt::PenStyle borderStyle() const override;
    void setBorderStyle(Qt::PenStyle style) override;
    QColor fillColor() const override;
    void setFillColor(const QColor& color) override;
    Qt::BrushStyle fillStyle() const override;
    void setFillStyle(Qt::BrushStyle style) override;
    void draw(QPainter& painter) override;

    void setPoints(const QPolygon& points);

private:
    QPolygon m_polygon;
};
//圆类
class Circle : public Shape
{
public:
    Circle();
    Circle(const QPoint& center, int radius);

    // 实现 Shape 类的纯虚函数
    QColor borderColor() const override;
    void setBorderColor(const QColor& color) override;
    Qt::PenStyle borderStyle() const override;
    void setBorderStyle(Qt::PenStyle style) override;
    QColor fillColor() const override;
    void setFillColor(const QColor& color) override;
    Qt::BrushStyle fillStyle() const override;
    void setFillStyle(Qt::BrushStyle style) override;
    void draw(QPainter& painter) override;

    // 其他属性和访问函数

private:
    QPoint m_center;
    int m_radius;

};
//扇形类
class Sector : public Shape
{
public:
    Sector();

    // 实现 Shape 类的纯虚函数
    QColor borderColor() const override;
    void setBorderColor(const QColor& color) override;
    Qt::PenStyle borderStyle() const override;
    void setBorderStyle(Qt::PenStyle style) override;
    QColor fillColor() const override;
    void setFillColor(const QColor& color) override;
    Qt::BrushStyle fillStyle() const override;
    void setFillStyle(Qt::BrushStyle style) override;
    void draw(QPainter& painter) override;

    void setCenter(const QPoint& center);
    void setRadius(int radius);
    void setStartAngle(int startAngle);
    void setSpanAngle(int spanAngle);

private:
    QPoint m_center;
    int m_radius;
    int m_startAngle;
    int m_spanAngle;
};
//矩形类
class Rectangle : public Shape
{
public:
    Rectangle();
    // 实现 Shape 类的纯虚函数
    QColor borderColor() const override;
    void setBorderColor(const QColor& color) override;
    Qt::PenStyle borderStyle() const override;
    void setBorderStyle(Qt::PenStyle style) override;
    QColor fillColor() const override;
    void setFillColor(const QColor& color) override;
    Qt::BrushStyle fillStyle() const override;
    void setFillStyle(Qt::BrushStyle style) override;
    void draw(QPainter& painter) override;
    void setRect(const QRect& rect);
private:
    QRect m_rectangle;
};
#endif // JIHE_H
