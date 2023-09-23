#include "postmachinemodel.hpp"

PostMachineModel::PostMachineModel() {}

bool PostMachineModel::isRunning() const
{
    return m_is_working;
}

bool PostMachineModel::isEnd() const
{
    return m_core.isEnd();
}

bool PostMachineModel::isError() const
{
    return m_core.isError();
}

const Tape &PostMachineModel::getTape() const
{
    return m_core.getTape();
}

Tape &PostMachineModel::getTape()
{
    return m_core.getTape();
}

const QVector<Command> &PostMachineModel::getCommands() const
{
    return m_core.getCommands();
}

QVector<Command> &PostMachineModel::getCommands()
{
    return m_core.getCommands();
}

size_t PostMachineModel::getCommandIndex() const
{
    return m_core.getCommandIndex();
}

void PostMachineModel::setTape(const Tape &tape)
{
    m_core.setTape(tape);
}

void PostMachineModel::setCommands(const QVector<Command> &commands)
{
    m_core.setCommands(commands);
}

void PostMachineModel::moveTape(Tape::index_t delta)
{
    auto head = m_core.getTape().getHead();
    m_core.getTape().setHead(head + delta);
}

void PostMachineModel::run()
{
    m_is_working = true;
}

void PostMachineModel::stop()
{
    m_is_working = false;
}

void PostMachineModel::nextStep()
{
    m_core.nextStep();
}
