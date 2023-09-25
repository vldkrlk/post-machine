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

    void CleanAll();
    void LoadFile(QString url);
    void SaveFile(QString url);
    void LoadTape(QString url);
    void SaveTape(QString url);

    void Timer();

    void HighSpeed();
    void NormalSpeed();
    void LowSpeed();
    void CustomSpeed(int speed);

    PostMachineModel *GetModel() const;

private:
    PostMachineModel *m_model;
};

#endif
