#include "tapewidget.hpp"
#include <QPainter>

TapeWidget::TapeWidget(QWidget *parent)
{
}

void TapeWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setFont(QFont("Arial", 10, QFont::Bold));

    auto cell_width = 40;
    auto cell_height = size().height() / 2.1;
    auto cells = size().width() / cell_width;
    auto vstep = (size().width() - cells * cell_width) / 2.0;
    auto middle = cells / 2;

    for (int i = 0; i < cells; ++i) {
        if (i - middle == 0)
            painter.drawRect(vstep + i * cell_width, 0, cell_width, cell_height);
        painter.drawRect(vstep + i * cell_width, cell_height, cell_width, cell_height);

        if (m_tape.getValue(i - middle + m_tape.getHead()))
            painter.drawEllipse(vstep + i * cell_width, cell_height, cell_width, cell_height);

        painter.drawText(vstep + i * cell_width + cell_width / 2.5f,
                         cell_width / 2,
                         QString::number(i - middle + m_tape.getHead()));
    }
}
