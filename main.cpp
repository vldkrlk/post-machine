#include "postmachinemodel.hpp"
#include "postmachineview.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    PostMachineModel model;
    QApplication a(argc, argv);
    PostMachineView w;
    w.loadDataFromModel(&model);
    w.show();
    return a.exec();
}
