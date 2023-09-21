#include "command.hpp"

#include <QList>

Command::Command(QString command, QString jumps)
{
    auto character = command.simplified();
    if (character == "<")
        m_type = MoveLeft;
    else if (character == ">")
        m_type = MoveRight;
    else if (character == "0")
        m_type = WriteZero;
    else if (character == "1")
        m_type = WriteOne;
    else if (character == "?")
        m_type = MoveIF;
    else if (character == "!")
        m_type = End;
    else
        m_type = Invalid;

    if (jumps.contains(',')) {
        auto vectors = jumps.split(QString(","));
        m_jump1 = vectors[0].toInt();
        m_jump2 = vectors[1].toInt();
    } else {
        m_jump1 = jumps.toInt();
    }
}

Command::Type Command::getType() const
{
    return m_type;
}

size_t Command::getJump1() const
{
    return m_jump1;
}

size_t Command::getJump2() const
{
    return m_jump2;
}
QString Command::getCommand()
{
    switch (m_type) {
    case MoveLeft:
        return "<";
    case MoveRight:
        return ">";
    case WriteZero:
        return "0";
    case WriteOne:
        return "1";
    case MoveIF:
        return "?";
    case End:
        return "!";
    case Invalid:
        return "";
        break;
    }
}

QString Command::getJumps()
{
    QString string;
    if (m_jump1 != kinvalid_jump) {
        string += QString::number(m_jump1);
        if (m_jump2 != kinvalid_jump) {
            string += ',';
            string += QString::number(m_jump2);
        }
    }
    return string;
}
