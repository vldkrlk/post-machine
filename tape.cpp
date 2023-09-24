#include "tape.hpp"

Tape::Tape()
{
    m_vector.resize(1000);
}

void Tape::setValue(index_t index, bool value)
{
    m_vector[index + 500] = value;
}

bool Tape::getValue(index_t index) const
{
    return m_vector[index + 500];
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

void Tape::saveToFile(QString url) const {}

void Tape::loadFromFile(QString url) {}

void Tape::clear()
{
    m_head = 0;
    for (size_t i = 0; i < m_vector.size(); i++)
        m_vector[i] = 0;
}
