#include "tape.hpp"

#include <QFile>
#include <QTextStream>

Tape::Tape()
{
}

void Tape::setValue(index_t index, bool value)
{
    if (index >= 0) {
        if (index < m_positive.size())
            m_positive[index] = value;
        else {
            m_positive.resize(index + 1);
            m_positive[index] = value;
        }
    } else {
        if (-index - 1 < m_negative.size())
            m_negative[-index - 1] = value;
        else {
            m_negative.resize(-index);
            m_negative[-index - 1] = value;
        }
    }
}

bool Tape::getValue(index_t index) const
{
    if (index >= 0) {
        if (index < m_positive.size())
            return m_positive[index];
        else
            return false;
    } else {
        if (-index - 1 < m_negative.size())
            return m_negative[-index - 1];
        else
            return false;
    }
}

void Tape::setHead(index_t head)
{
    m_head = head;
}

Tape::index_t Tape::getHead() const
{
    return m_head;
}

void Tape::writeOnHead(bool value)
{
    setValue(getHead(), value);
}

bool Tape::readOnHead() const
{
    return getValue(getHead());
}

void Tape::saveToFile(QString url) const
{
    QFile file(url);
    file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate);
    if (!file.isOpen()) {
        file.close();
        return;
    }
    QTextStream io(&file);

    io << m_positive.size() << " ";
    io << m_negative.size() << " ";

    for (auto value : m_positive) {
        io << value << " ";
    }
    for (auto value : m_negative) {
        io << value << " ";
    }

    file.close();
}

void Tape::loadFromFile(QString url)
{
    QFile file(url);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    if (!file.isOpen()) {
        file.close();
        return;
    }
    QTextStream io(&file);

    size_t p_size, n_size;

    io >> p_size >> n_size;

    m_positive.clear();
    m_negative.clear();

    for (size_t i = 0; i < p_size; i++) {
        int value;
        io >> value;
        m_positive.push_back(value);
    }

    for (size_t i = 0; i < n_size; i++) {
        int value;
        io >> value;
        m_negative.push_back(value);
    }

    file.close();
}

void Tape::clear()
{
    m_head = 0;
    m_positive.clear();
    m_negative.clear();
}
