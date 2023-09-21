#include "postmachinemodel.hpp"
#include "postmachineview.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    PostMachineModel model;
    model.setCommands({Command("hi", "0,4"), Command("<", "0,3")});
    QApplication a(argc, argv);
    PostMachineView w;
    w.loadDataFromModel(model);
    w.show();
    return a.exec();
}
