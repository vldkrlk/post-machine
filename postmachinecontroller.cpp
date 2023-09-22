#include "postmachinecontroller.hpp"
#include "QDebug"

PostMachineController::PostMachineController(PostMachineModel *model)
    : m_model(model)
{}

void PostMachineController::MoveTapeRight()
{
    m_model->moveTape(1);
}

void PostMachineController::MoveTapeLeft()
{
    m_model->moveTape(-1);
}

void PostMachineController::CommandEntered(size_t index, QString data, QString params)
{
    m_model->getCommands()[index] = Command(data, params);
}

void PostMachineController::InsertCommand(size_t index)
{
    m_model->getCommands().insert(index, Command("", ""));
}

void PostMachineController::DeleteCommand(size_t index)
{
    m_model->getCommands().remove(index);
}

void PostMachineController::ChangeTapeValue(Tape::index_t index)
{
    m_model->getTape().setValue(index, !m_model->getTape().getValue(index));
}

void PostMachineController::Start()
{
    m_model->run();
}

void PostMachineController::Stop()
{
    m_model->stop();
}

void PostMachineController::Step()
{
    m_model->nextStep();
}

PostMachineModel *PostMachineController::GetModel() const
{
    return m_model;
}
