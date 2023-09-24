#ifndef POSTMACHINEMODEL_HPP
#define POSTMACHINEMODEL_HPP

#include <QVector>

#include "postmachine.hpp"

class PostMachineModel : public PostMachine
{
public:
    PostMachineModel();

    bool isRunning() const;

    void moveTape(Tape::index_t delta);
    void run();
    void stop();

private:
    bool m_is_working = false;
};

#endif
