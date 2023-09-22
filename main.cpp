#include "postmachinecontroller.hpp"
#include "postmachinemodel.hpp"
#include "postmachineview.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    PostMachineModel *model = new PostMachineModel();
    model->setCommands({Command("hi", "0,4"), Command("<", "0,3")});

    PostMachineController *controller = new PostMachineController(model);

    PostMachineView *view = new PostMachineView(controller);
    view->loadDataFromModel(*model);

    view->show();
    return a.exec();
}
