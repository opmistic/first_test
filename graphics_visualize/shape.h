#include <QColor>
#include <QPainter>
class Shape
{
public:
     Shape();
    virtual ~Shape() {}

    // 边框颜色属性
    virtual QColor borderColor() const = 0;
    virtual void setBorderColor(const QColor& color) = 0;

    // 边框样式属性
    virtual Qt::PenStyle borderStyle() const = 0;
    virtual void setBorderStyle(Qt::PenStyle style) = 0;

    // 填充颜色属性
    virtual QColor fillColor() const = 0;
    virtual void setFillColor(const QColor& color) = 0;

    // 填充样式属性
    virtual Qt::BrushStyle fillStyle() const = 0;
    virtual void setFillStyle(Qt::BrushStyle style) = 0;

    // 绘制接口
    virtual void draw(QPainter& painter) = 0;


    QColor m_borderColor;
    Qt::PenStyle m_borderStyle;
    QColor m_fillColor;
    Qt::BrushStyle m_fillStyle;

};

