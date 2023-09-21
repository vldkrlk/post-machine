#include "postmachineview.hpp"
#include "./ui_postmachineview.h"

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

void PostMachineView::loadDataFromModel(const PostMachineModel *model) {}
