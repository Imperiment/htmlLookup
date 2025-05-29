#ifndef SETUP_H
#define SETUP_H

#include <QMainWindow>
#include <QTreeWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_testBtn_clicked();

    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

    void on_removeBtn_clicked();

    void on_openBtn_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // SETUP_H
