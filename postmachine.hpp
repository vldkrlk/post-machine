#ifndef POSTMACHINE_HPP
#define POSTMACHINE_HPP

#include <QVector>
#include "command.hpp"
#include "tape.hpp"

class PostMachine
{
public:
    void nextStep();
    void reset();
    bool isEnd() const;
    bool isError() const;

    size_t getCommandIndex() const;

    const QVector<Command> &getCommands() const;
    QVector<Command> &getCommands();

    const Tape &getTape() const;
    Tape &getTape();

    void setCommandIndex(size_t index);
    void setCommands(const QVector<Command> &commands);
    void setTape(const Tape &tape);

private:
    size_t m_command_index = 0;
    QVector<Command> m_commands;
    Tape m_tape;
};

#endif
