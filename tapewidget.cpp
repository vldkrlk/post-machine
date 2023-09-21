#include "tapewidget.hpp"
#include <QHBoxLayout>

TapeWidget::TapeWidget(QWidget *parent)
{
    QHBoxLayout *layout = new QHBoxLayout(this);
    m_tablewidget = new QTableWidget();
    layout->addWidget(m_tablewidget);

    auto cells = this->size().width() / 150;

    m_tablewidget->setRowCount(3);
    m_tablewidget->setColumnCount(cells);
    m_tablewidget->setProperty("verticalHeaderVisible", false);
}
