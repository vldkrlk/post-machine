#ifndef POSTMACHINEVIEW_HPP
#define POSTMACHINEVIEW_HPP

#include <QMainWindow>
#include <QTableWidgetItem>

#include "tapewidget.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class PostMachineView; }
QT_END_NAMESPACE

class PostMachineModel;
class PostMachineController;

class PostMachineView : public QMainWindow
{
    Q_OBJECT

public:
    PostMachineView(PostMachineController *controller, QWidget *parent = nullptr);
    ~PostMachineView();

    void loadDataFromModel(const PostMachineModel &model);

private slots:
    void on_scroll_left_button_clicked();

    void on_scroll_right_button_clicked();

    void on_commands_widget_itemChanged(QTableWidgetItem *item);

    void on_insert_button_clicked();

    void on_remove_button_clicked();

    void on_tape_value_changed(Tape::index_t);

    void on_run_button_clicked();

    void on_stop_button_clicked();

    void on_step_button_clicked();

private:
    Ui::PostMachineView *ui;
    PostMachineController *controller;
    bool m_table_editing = false;
};
#endif // POSTMACHINEVIEW_HPP
