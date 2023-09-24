#include "postmachineview.hpp"
#include <QFileDialog>
#include <QMessageBox>
#include "./ui_postmachineview.h"
#include "postmachinecontroller.hpp"
#include "postmachinemodel.hpp"

PostMachineView::PostMachineView(PostMachineController *controller, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PostMachineView)
    , controller(controller)
{
    ui->setupUi(this);
    ui->commands_widget->setSelectionBehavior(QAbstractItemView::SelectRows);
    connect(ui->tape_widget, &TapeWidget::ValueChanged, this, &PostMachineView::tape_value_changed);
    connect(ui->about_action, &QAction::triggered, this, &PostMachineView::about);
    connect(ui->instruction_action, &QAction::triggered, this, &PostMachineView::instruction);
    connect(ui->exit_action, &QAction::triggered, this, &PostMachineView::exit);

    connect(ui->new_file_button, &QPushButton::clicked, this, &PostMachineView::new_file);

    connect(ui->save_file_button, &QPushButton::clicked, this, &PostMachineView::save_file);
    connect(ui->save_action, &QAction::triggered, this, &PostMachineView::save_file);

    connect(ui->load_file_button, &QPushButton::clicked, this, &PostMachineView::load_file);
    connect(ui->load_action, &QAction::triggered, this, &PostMachineView::load_file);

    connect(ui->load_tape_button, &QPushButton::clicked, this, &PostMachineView::load_tape);
    connect(ui->load_tape_action, &QAction::triggered, this, &PostMachineView::load_tape);

    connect(ui->save_tape_button, &QPushButton::clicked, this, &PostMachineView::save_tape);
    connect(ui->save_tape_action, &QAction::triggered, this, &PostMachineView::save_tape);
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

    if (model.isRunning()) {
        ui->status_label->setText("Виконується");
    } else {
        if (model.isError())
            ui->status_label->setText("Машина зупинилася через помилку під час виконання");
        else if (model.isEnd())
            ui->status_label->setText("Машина зупинилася на команді зупинки");
        else
            ui->status_label->setText("Машина очікує команди");
    }

    auto commands = model.getCommands();

    ui->commands_widget->setRowCount(commands.size());
    for (int i = 0; i < commands.size(); ++i) {
        auto command_item = new QTableWidgetItem(commands[i].getCommand()
                                                 + (i == model.getCommandIndex() ? "  <---" : ""));
        ui->commands_widget->setItem(i, 0, command_item);
        auto jump_item = new QTableWidgetItem(commands[i].getJumps());
        ui->commands_widget->setItem(i, 1, jump_item);
        auto comment_item = new QTableWidgetItem(commands[i].getComment());
        ui->commands_widget->setItem(i, 2, comment_item);
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
    auto comment = ui->commands_widget->item(row, 2)->text();

    controller->CommandEntered(row, command, argc, comment);

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

void PostMachineView::save_tape()
{
    controller->SaveTape(
        QFileDialog::getSaveFileName(this, "Виберіть файл для збереження", "", "*.post"));
    loadDataFromModel(*controller->GetModel());
}

void PostMachineView::load_tape()
{
    controller->LoadTape(
        QFileDialog::getOpenFileName(this, "Виберіть файл для збереження", "", "*.post"));
    loadDataFromModel(*controller->GetModel());
}

void PostMachineView::new_file()
{
    controller->CleanAll();
    loadDataFromModel(*controller->GetModel());
}

void PostMachineView::load_file()
{
    controller->LoadFile(
        QFileDialog::getOpenFileName(this, "Виберіть файл для збереження", "", "*.post"));
    loadDataFromModel(*controller->GetModel());
}

void PostMachineView::save_file()
{
    controller->SaveFile(
        QFileDialog::getSaveFileName(this, "Виберіть файл для збереження", "", "*.post"));
    loadDataFromModel(*controller->GetModel());
}

void PostMachineView::exit()
{
    QApplication::exit(0);
}

void PostMachineView::about()
{
    QMessageBox::about(this, "Про програму", "Автор");
}

void PostMachineView::instruction()
{
    QMessageBox::about(this, "Інструкція", "");
}

void PostMachineView::timer()
{
    controller->Timer();
    loadDataFromModel(*controller->GetModel());
}
