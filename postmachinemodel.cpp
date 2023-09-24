#include "postmachinemodel.hpp"

PostMachineModel::PostMachineModel() {}

bool PostMachineModel::isRunning() const
{
    return m_is_working;
}

void PostMachineModel::moveTape(Tape::index_t delta)
{
    auto head = getTape().getHead();
    getTape().setHead(head + delta);
}

void PostMachineModel::run()
{
    m_is_working = true;
}

void PostMachineModel::stop()
{
    m_is_working = false;
}

int PostMachineModel::getTimerDelay()
{
    return m_timer_delay;
}
