#include "command.hpp"

Command::Command(QString command, QString jumps)
{
    //parsing
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
/*
QString Command::GetCommand()
{
    //converting
}

QString Command::GetJumps()
{
    //converting
}
*/
