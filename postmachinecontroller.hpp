#ifndef POSTMACHINECONTROLLER_HPP
#define POSTMACHINECONTROLLER_HPP

#include "postmachinemodel.hpp"

class PostMachineController
{
public:
    PostMachineController(PostMachineModel *model);

    void MoveTapeRight();
    void MoveTapeLeft();
    void CommandEntered(size_t index, QString data, QString params, QString comment);
    void InsertCommand(size_t index);
    void DeleteCommand(size_t index);
    void ChangeTapeValue(Tape::index_t index);
    void Start();
    void Stop();
    void Step();

    PostMachineModel *GetModel() const;

private:
    PostMachineModel *m_model;
};

#endif
