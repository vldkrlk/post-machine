#ifndef POSTMACHINEMODEL_HPP
#define POSTMACHINEMODEL_HPP

#include <QString>
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

    int getTimerDelay();
    void setTimerDelay(int delay);

    QString getProblem() const;
    void setProblem(QString problem);

    void saveToFile(QString url) const;
    void loadFromFile(QString url);

   private:
    QString m_problem;
    bool m_is_working = false;
    int m_timer_delay = 2000;
};

#endif
