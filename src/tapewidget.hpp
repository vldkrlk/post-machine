#ifndef TAPEWIDGET_HPP
#define TAPEWIDGET_HPP

#include <QMouseEvent>
#include <QTableWidget>
#include <QWidget>

#include "tape.hpp"

class TapeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TapeWidget(QWidget *parent = nullptr);

    void loadFromTape(const Tape &tape);

    virtual void paintEvent(QPaintEvent *event);
    virtual void mouseDoubleClickEvent(QMouseEvent *event);
signals:
 void valueChanged(Tape::index_t index);

private:
    Tape m_tape;
};

#endif
