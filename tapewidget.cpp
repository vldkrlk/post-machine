#include "tapewidget.hpp"
#include <QApplication>
#include <QPainter>
#include <QPalette>

TapeWidget::TapeWidget(QWidget *parent) {}

void TapeWidget::paintEvent(QPaintEvent *event)
{
    auto pallete = this->palette();

    QColor background_color = pallete.base().color();
    QColor main_color = pallete.color(QPalette::WindowText);
    QColor highlight_color = pallete.highlight().color();

    QPainter painter(this);
    painter.setFont(QApplication::font());

    auto cell_width = 40;
    auto cell_height = size().height() / 2.1;
    auto cells = (size().width() - 1) / cell_width;
    if (cells % 2 == 0)
        cells--;
    auto vstep = (size().width() - cells * cell_width) / 2.0;
    auto middle = cells / 2;

    for (int i = 0; i < cells; ++i) {
        painter.setBrush(background_color);
        painter.setPen(QPen(main_color, 1));

        painter.drawRect(vstep + i * cell_width, cell_height, cell_width, cell_height);

        painter.drawText(vstep + i * cell_width + cell_width / 2.6f,
                         cell_width / 1.3,
                         QString::number(i - middle + m_tape.getHead()));

        if (m_tape.getValue(i - middle + m_tape.getHead())) {
            painter.setBrush(highlight_color);
            painter.setPen(QPen());
            painter.drawEllipse(vstep + i * cell_width + cell_width / 4,
                                cell_height + cell_height / 4,
                                cell_width / 2,
                                cell_height / 2);
        }
    }
    painter.setPen(QPen(highlight_color, 4));
    painter.setBrush(Qt::transparent);
    painter.drawRect(vstep + middle * cell_width, cell_height, cell_width, cell_height);
}

void TapeWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    auto cell_width = 40;
    auto cells = (size().width() - 1) / cell_width;
    if (cells % 2 == 0)
        cells--;
    auto vstep = (size().width() - cells * cell_width) / 2.0;
    auto middle = cells / 2;

    int index = (event->pos().x() - vstep) / cell_width;
    Tape::index_t real_index = index - middle + m_tape.getHead();
    emit ValueChanged(real_index);
}

void TapeWidget::loadFromTape(const Tape &tape)
{
    m_tape = tape;
    repaint();
}
