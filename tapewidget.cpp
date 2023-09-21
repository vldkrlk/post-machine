#include "tapewidget.hpp"
#include <QApplication>
#include <QPainter>
#include <QPalette>

TapeWidget::TapeWidget(QWidget *parent) {}

void TapeWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setFont(QApplication::font());

    auto pallete = this->palette();

    painter.setBrush(pallete.base());
    painter.setPen(pallete.color(QPalette::WindowText));

    auto cell_width = 40;
    auto cell_height = size().height() / 2.1;
    auto cells = (size().width() - 1) / cell_width;
    if (cells % 2 == 0)
        cells--;
    auto vstep = (size().width() - cells * cell_width) / 2.0;
    auto middle = cells / 2;

    for (int i = 0; i < cells; ++i) {
        painter.drawRect(vstep + i * cell_width, cell_height, cell_width, cell_height);

        if (m_tape.getValue(i - middle + m_tape.getHead()))
            painter.drawEllipse(vstep + i * cell_width, cell_height, cell_width, cell_height);

        painter.drawText(vstep + i * cell_width + cell_width / 2.6f,
                         cell_width / 1.3,
                         QString::number(i - middle + m_tape.getHead()));
    }
}

void TapeWidget::loadFromTape(const Tape &tape)
{
    m_tape = tape;
}
