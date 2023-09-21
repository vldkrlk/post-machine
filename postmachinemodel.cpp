#include "postmachinemodel.hpp"

PostMachineModel::PostMachineModel() {}

bool PostMachineModel::isRunning() const
{
    return false;
}

const Tape &PostMachineModel::getTape() const
{
    return m_core.getTape();
}

QVector<Command> PostMachineModel::getCommands() const
{
    return m_core.getCommands();
}

void PostMachineModel::setTape(const Tape &tape)
{
    m_core.setTape(tape);
}

void PostMachineModel::setCommands(const QVector<Command> &commands)
{
    m_core.setCommands(commands);
}

void PostMachineModel::moveTape(Tape::index_t delta) {}

void PostMachineModel::run() {}

void PostMachineModel::stop() {}

void PostMachineModel::nextStep()
{
    m_core.nextStep();
}
