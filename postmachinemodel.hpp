#ifndef POSTMACHINEMODEL_HPP
#define POSTMACHINEMODEL_HPP

#include "postmachine.hpp"

class PostMachineModel
{
public:
    bool isRunning() const;
    const Tape &getTape() const;
    const QVector<Command> &getCommands() const;

    void moveTape(Tape::index_t delta);
    void run();
    void stop();
    void nextStep();

private:
    PostMachine m_core;
};

#endif
