#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <QString>

class Command
{
public:
    enum Type { MoveLeft, MoveRight, WriteZero, WriteOne, MoveIF, End, Invalid };
    const static size_t kinvalid_jump = std::numeric_limits<size_t>::max();

    Command(QString command, QString jumps, QString comment);

    Type getType() const;
    size_t getJump1() const;
    size_t getJump2() const;

    QString getCommand();
    QString getJumps();
    QString getComment();

private:
    Type m_type = Invalid;
    size_t m_jump1 = kinvalid_jump;
    size_t m_jump2 = kinvalid_jump;
    QString m_comment;
};

#endif
