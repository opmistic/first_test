#include "geometry.h"


//点类
Point::Point()
    : Shape(), m_x(0), m_y(0)
{
}

Point::Point(int x, int y) : Shape(),m_x(x), m_y(y)
{
}

QColor Point::borderColor() const
{
    return m_borderColor;
}

void Point::setBorderColor(const QColor& color)
{
    m_borderColor = color;
}

Qt::PenStyle Point::borderStyle() const
{
    return m_borderStyle;
}

void Point::setBorderStyle(Qt::PenStyle style)
{
    m_borderStyle = style;
}

QColor Point::fillColor() const
{
    return m_fillColor;
}

void Point::setFillColor(const QColor& color)
{
    m_fillColor = color;
}

Qt::BrushStyle Point::fillStyle() const
{
    return m_fillStyle;
}

void Point::setFillStyle(Qt::BrushStyle style)
{
    m_fillStyle = style;
}

void Point::draw(QPainter& painter)
{
    painter.save();

    // 设置边框属性
    QPen pen(m_borderColor);
    pen.setStyle(m_borderStyle);
    painter.setPen(pen);

    // 设置填充属性
    QBrush brush(m_fillColor);
    brush.setStyle(m_fillStyle);
    painter.setBrush(brush);

    // 绘制点
    painter.drawPoint(m_x, m_y);

    painter.restore();
}



//折线类

Polyline::Polyline()
{
}

Polyline::Polyline(const QPolygon& points)  : Shape(),m_points(points)
{
}

QColor Polyline::borderColor() const
{
    return m_borderColor;
}

void Polyline::setBorderColor(const QColor& color)
{
    m_borderColor = color;
}

Qt::PenStyle Polyline::borderStyle() const
{
    return m_borderStyle;
}

void Polyline::setBorderStyle(Qt::PenStyle style)
{
    m_borderStyle = style;
}

QColor Polyline::fillColor() const
{
    return m_fillColor;
}

void Polyline::setFillColor(const QColor& color)
{
    m_fillColor = color;
}

Qt::BrushStyle Polyline::fillStyle() const
{
    return m_fillStyle;
}

void Polyline::setFillStyle(Qt::BrushStyle style)
{
    m_fillStyle = style;
}

void Polyline::draw(QPainter& painter)
{
    painter.save();

    // 设置边框属性
    QPen pen(m_borderColor);
    pen.setStyle(m_borderStyle);
    painter.setPen(pen);

    // 设置填充属性
    QBrush brush(m_fillColor);
    brush.setStyle(m_fillStyle);
    painter.setBrush(brush);

    // 绘制折线
    painter.drawPolyline(m_points);

    painter.restore();
}
//多边形类
Polygon::Polygon()
    : Shape()
{
}

QColor Polygon::borderColor() const
{
    return m_borderColor;
}

void Polygon::setBorderColor(const QColor& color)
{
    m_borderColor = color;
}

Qt::PenStyle Polygon::borderStyle() const
{
    return m_borderStyle;
}

void Polygon::setBorderStyle(Qt::PenStyle style)
{
    m_borderStyle = style;
}

QColor Polygon::fillColor() const
{
    return m_fillColor;
}

void Polygon::setFillColor(const QColor& color)
{
    m_fillColor = color;
}

Qt::BrushStyle Polygon::fillStyle() const
{
    return m_fillStyle;
}

void Polygon::setFillStyle(Qt::BrushStyle style)
{
    m_fillStyle = style;
}

void Polygon::draw(QPainter& painter)
{
    painter.save();

    // 设置边框属性
    QPen pen(borderColor());
    pen.setStyle(borderStyle());
    painter.setPen(pen);

    // 设置填充属性
    QBrush brush(fillColor());
    brush.setStyle(fillStyle());
    painter.setBrush(brush);

    // 绘制多边形
    painter.drawPolygon(m_polygon);

    painter.restore();
}

void Polygon::setPoints(const QPolygon& points)
{
    m_polygon = points;
}
//圆类
Circle::Circle()  : Shape(),m_center(0, 0), m_radius(0)
{
}

Circle::Circle(const QPoint& center, int radius)  : Shape(),m_center(center), m_radius(radius)
{
}

QColor Circle::borderColor() const
{
    return m_borderColor;
}

void Circle::setBorderColor(const QColor& color)
{
    m_borderColor = color;
}

Qt::PenStyle Circle::borderStyle() const
{
    return m_borderStyle;
}

void Circle::setBorderStyle(Qt::PenStyle style)
{
    m_borderStyle = style;
}

QColor Circle::fillColor() const
{
    return m_fillColor;
}

void Circle::setFillColor(const QColor& color)
{
    m_fillColor = color;
}

Qt::BrushStyle Circle::fillStyle() const
{
    return m_fillStyle;
}

void Circle::setFillStyle(Qt::BrushStyle style)
{
    m_fillStyle = style;
}

void Circle::draw(QPainter& painter)
{
    painter.save();

    // 设置边框属性
    QPen pen(m_borderColor);
    pen.setStyle(m_borderStyle);
    painter.setPen(pen);
    // 设置填充属性
    QBrush brush(m_fillColor);
    brush.setStyle(m_fillStyle);
    painter.setBrush(brush);
    // 绘制圆
    painter.drawEllipse(m_center, m_radius, m_radius);
    painter.restore();
}
//扇形类
Sector::Sector()
    : Shape()
{
}

QColor Sector::borderColor() const
{
    return m_borderColor;
}

void Sector::setBorderColor(const QColor& color)
{
    m_borderColor = color;
}

Qt::PenStyle Sector::borderStyle() const
{
    return m_borderStyle;
}

void Sector::setBorderStyle(Qt::PenStyle style)
{
    m_borderStyle = style;
}

QColor Sector::fillColor() const
{
    return m_fillColor;
}

void Sector::setFillColor(const QColor& color)
{
    m_fillColor = color;
}

Qt::BrushStyle Sector::fillStyle() const
{
    return m_fillStyle;
}

void Sector::setFillStyle(Qt::BrushStyle style)
{
    m_fillStyle = style;
}

void Sector::draw(QPainter& painter)
{
    painter.save();

    // 设置边框属性
    QPen pen(borderColor());
    pen.setStyle(borderStyle());
    painter.setPen(pen);

    // 设置填充属性
    QBrush brush(fillColor());
    brush.setStyle(fillStyle());
    painter.setBrush(brush);

    // 绘制扇形
    painter.drawPie(QRect(m_center.x() - m_radius, m_center.y() - m_radius, m_radius * 2, m_radius * 2), m_startAngle, m_spanAngle);

    painter.restore();
}

void Sector::setCenter(const QPoint& center)
{
    m_center = center;
}

void Sector::setRadius(int radius)
{
    m_radius = radius;
}

void Sector::setStartAngle(int startAngle)
{
    m_startAngle = startAngle;
}

void Sector::setSpanAngle(int spanAngle)
{
    m_spanAngle = spanAngle;
}
//矩形类
Rectangle::Rectangle()  :Shape(),
      m_rectangle()
{
}

QColor Rectangle::borderColor() const
{
    return m_borderColor;
}

void Rectangle::setBorderColor(const QColor& color)
{
    m_borderColor = color;
}

Qt::PenStyle Rectangle::borderStyle() const
{
    return m_borderStyle;
}

void Rectangle::setBorderStyle(Qt::PenStyle style)
{
    m_borderStyle = style;
}

QColor Rectangle::fillColor() const
{
    return m_fillColor;
}

void Rectangle::setFillColor(const QColor& color)
{
    m_fillColor = color;
}

Qt::BrushStyle Rectangle::fillStyle() const
{
    return m_fillStyle;
}

void Rectangle::setFillStyle(Qt::BrushStyle style)
{
    m_fillStyle = style;
}

void Rectangle::draw(QPainter& painter)
{
    painter.setPen(QPen(m_borderColor, 2, m_borderStyle));
    painter.setBrush(QBrush(m_fillColor,m_fillStyle));
    painter.drawRect(m_rectangle);
}

void Rectangle::setRect(const QRect& rect)
{
    m_rectangle = rect;
}

