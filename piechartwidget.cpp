#include "piechartwidget.h"
#include <QPainter>
PieChartWidget::PieChartWidget(QWidget *parent) : QWidget(parent)
{
    magic_percentage=0;
    trap_percentage=0;
    monster_percentage=0;
}

void PieChartWidget::setpercentage(double magic, double trap,double monster)
{
    double sum=magic+trap+monster;
    magic/=sum;
    trap/=sum;
    magic_percentage=qRound(magic*360);
    trap_percentage=qRound(trap*360);
    monster_percentage=360-magic_percentage-trap_percentage;
}
void PieChartWidget::paintEvent(QPaintEvent *)
{

    QPainter painter(this);
    QRectF size = QRectF(0,0,this->width(),this->width());
    painter.setBrush(QColor(19, 147, 129));
    painter.drawPie(size,0,magic_percentage*16);
    painter.setBrush(QColor(171, 29, 134));
    painter.drawPie(size,magic_percentage*16,trap_percentage*16);
    painter.setBrush(QColor(197,152,75));
    painter.drawPie(size,0,-monster_percentage*16);
}
