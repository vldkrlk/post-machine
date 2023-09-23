#ifndef POSTMACHINEMODEL_HPP
#define POSTMACHINEMODEL_HPP

#include <QVector>

#include "postmachine.hpp"

class PostMachineModel
{
public:
    PostMachineModel();

    bool isRunning() const;
    bool isEnd() const;
    bool isError() const;
    const Tape &getTape() const;
    Tape &getTape();
    const QVector<Command> &getCommands() const;
    QVector<Command> &getCommands();
    size_t getCommandIndex() const;

    void setTape(const Tape &);
    void setCommands(const QVector<Command> &commands);

    void moveTape(Tape::index_t delta);
    void run();
    void stop();
    void nextStep();

private:
    PostMachine m_core;
    bool m_is_working = false;
};

#endif
