#include "postmachineview.hpp"
#include "./ui_postmachineview.h"
#include "postmachinecontroller.hpp"
#include "postmachinemodel.hpp"

PostMachineView::PostMachineView(PostMachineController *controller, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PostMachineView)
    , controller(controller)
{
    ui->setupUi(this);
    connect(ui->tape_widget, &TapeWidget::ValueChanged, this, &PostMachineView::tape_value_changed);
}

PostMachineView::~PostMachineView()
{
    delete ui;
}

void PostMachineView::loadDataFromModel(const PostMachineModel &model)
{
    m_table_editing = true;
    ui->tape_widget->loadFromTape(model.getTape());

    ui->tape_widget->setEnabled(!model.isRunning());
    ui->insert_button->setEnabled(!model.isRunning());
    ui->remove_button->setEnabled(!model.isRunning());
    ui->scroll_left_button->setEnabled(!model.isRunning());
    ui->scroll_right_button->setEnabled(!model.isRunning());
    ui->run_button->setEnabled(!model.isRunning());
    ui->stop_button->setEnabled(model.isRunning());
    ui->step_button->setEnabled(!model.isRunning());
    ui->commands_widget->setEnabled(!model.isRunning());

    auto commands = model.getCommands();

    ui->commands_widget->setRowCount(commands.size());
    for (int i = 0; i < commands.size(); ++i) {
        auto command_item = new QTableWidgetItem(commands[i].getCommand());
        ui->commands_widget->setItem(i, 0, command_item);
        auto jump_item = new QTableWidgetItem(commands[i].getJumps());
        ui->commands_widget->setItem(i, 1, jump_item);
    }
    m_table_editing = false;
}

void PostMachineView::on_scroll_left_button_clicked()
{
    controller->MoveTapeLeft();
    loadDataFromModel(*controller->GetModel());
}

void PostMachineView::on_scroll_right_button_clicked()
{
    controller->MoveTapeRight();
    loadDataFromModel(*controller->GetModel());
}

void PostMachineView::on_commands_widget_itemChanged(QTableWidgetItem *item)
{
    if (m_table_editing)
        return;

    auto row = item->row();
    auto command = ui->commands_widget->item(row, 0)->text();
    auto argc = ui->commands_widget->item(row, 1)->text();

    controller->CommandEntered(row, command, argc);

    loadDataFromModel(*controller->GetModel());
}

void PostMachineView::on_insert_button_clicked()
{
    controller->InsertCommand(ui->commands_widget->currentRow());
    loadDataFromModel(*controller->GetModel());
}

void PostMachineView::on_remove_button_clicked()
{
    controller->DeleteCommand(ui->commands_widget->currentRow());
    loadDataFromModel(*controller->GetModel());
}

void PostMachineView::tape_value_changed(Tape::index_t index)
{
    controller->ChangeTapeValue(index);
    loadDataFromModel(*controller->GetModel());
}

void PostMachineView::on_run_button_clicked()
{
    controller->Start();
    loadDataFromModel(*controller->GetModel());
}

void PostMachineView::on_stop_button_clicked()
{
    controller->Stop();
    loadDataFromModel(*controller->GetModel());
}

void PostMachineView::on_step_button_clicked()
{
    controller->Step();
    loadDataFromModel(*controller->GetModel());
}
