#ifndef POSTMACHINEVIEW_HPP
#define POSTMACHINEVIEW_HPP

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class PostMachineView; }
QT_END_NAMESPACE

class PostMachineModel;

class PostMachineView : public QMainWindow
{
    Q_OBJECT

public:
    PostMachineView(QWidget *parent = nullptr);
    ~PostMachineView();

    void loadDataFromModel(const PostMachineModel *model);

private:
    Ui::PostMachineView *ui;
};
#endif // POSTMACHINEVIEW_HPP
