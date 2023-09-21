#ifndef TAPEWIDGET_HPP
#define TAPEWIDGET_HPP

#include <QTableWidget>
#include <QWidget>

#include "tape.hpp"

class TapeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TapeWidget(QWidget *parent = nullptr);

    void loadFromTape(const Tape &tape);

private:
    QTableWidget *m_tablewidget;
};

#endif
