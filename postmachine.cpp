#include "postmachine.hpp"

void PostMachine::nextStep()
{
    if (m_command_index >= m_commands.size())
        return;
    auto &command = m_commands[m_command_index];
    size_t jump = m_command_index + 1;
    if (command.getJump1() != Command::kinvalid_jump)
        jump = command.getJump1() - 1;

    switch (command.getType()) {
    case Command::MoveLeft:
        m_tape.setHead(m_tape.getHead() - 1);
        break;
    case Command::MoveRight:
        m_tape.setHead(m_tape.getHead() + 1);
        break;
    case Command::WriteZero:
        m_tape.writeOnHead(0);
        break;
    case Command::WriteOne:
        m_tape.writeOnHead(1);
        break;
    case Command::MoveIF:
        jump = m_tape.readOnHead() ? command.getJump1() - 1 : command.getJump2() - 1;
        break;
    case Command::End:
        return;
    case Command::Invalid:
        return;
    }

    m_command_index = jump;
}

void PostMachine::reset()
{
    m_command_index = 0;
}

bool PostMachine::isEnd() const
{
    if (isError())
        return true;
    return m_commands[m_command_index].getType() == Command::End;
}

bool PostMachine::isError() const
{
    if (m_command_index >= m_commands.size())
        return true;
    return m_commands[m_command_index].getType() == Command::Invalid;
}

size_t PostMachine::getCommandIndex() const
{
    return m_command_index;
}

const QVector<Command> &PostMachine::getCommands() const
{
    return m_commands;
}

QVector<Command> &PostMachine::getCommands()
{
    return m_commands;
}

const Tape &PostMachine::getTape() const
{
    return m_tape;
}

Tape &PostMachine::getTape()
{
    return m_tape;
}

void PostMachine::setCommandIndex(size_t index)
{
    m_command_index = index;
}

void PostMachine::setCommands(const QVector<Command> &commands)
{
    m_commands = commands;
    reset();
}

void PostMachine::setTape(const Tape &tape)
{
    m_tape = tape;
    reset();
}
