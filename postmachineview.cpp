#include "postmachineview.hpp"
#include "./ui_postmachineview.h"
#include "postmachinemodel.hpp"

PostMachineView::PostMachineView(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PostMachineView)
{
    ui->setupUi(this);
}

PostMachineView::~PostMachineView()
{
    delete ui;
}

void PostMachineView::loadDataFromModel(const PostMachineModel &model)
{
    ui->tape_widget->loadFromTape(model.getTape());
    auto commands = model.getCommands();

    ui->commands_widget->setRowCount(commands.count());
    for (int i = 0; i < commands.size(); ++i) {
        qDebug() << "hi";
        ui->commands_widget->setItem(i, 0, new QTableWidgetItem(commands[i].getCommand()));
        ui->commands_widget->setItem(i, 1, new QTableWidgetItem(commands[i].getJumps()));
    }
}
