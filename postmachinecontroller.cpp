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

void PostMachineController::CommandEntered(size_t index,
                                           QString data,
                                           QString params,
                                           QString comment)
{
    m_model->getCommands()[index] = Command(data, params, comment);
}

void PostMachineController::InsertCommand(size_t index)
{
    if (m_model->getCommands().size() < index)
        m_model->getCommands().append(Command("", "", ""));
    else
        m_model->getCommands().insert(index, Command("", "", ""));
}

void PostMachineController::DeleteCommand(size_t index)
{
    if (m_model->getCommands().size() > index)
        m_model->getCommands().remove(index);
    else if (!m_model->getCommands().empty())
        m_model->getCommands().pop_back();
}

void PostMachineController::ChangeTapeValue(Tape::index_t index)
{
    m_model->getTape().setValue(index, !m_model->getTape().getValue(index));
}

void PostMachineController::Start()
{
    m_model->reset();
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

void PostMachineController::CleanAll()
{
    m_model->setCommands({});
    m_model->getTape().clear();
}

void PostMachineController::LoadFile(QString url)
{
    m_model->loadFromFile(url);
}

void PostMachineController::SaveFile(QString url)
{
    m_model->saveToFile(url);
}

void PostMachineController::LoadTape(QString url)
{
    m_model->getTape().loadFromFile(url);
}

void PostMachineController::SaveTape(QString url)
{
    m_model->getTape().saveToFile(url);
}

void PostMachineController::Timer() {}

PostMachineModel *PostMachineController::GetModel() const
{
    return m_model;
}
