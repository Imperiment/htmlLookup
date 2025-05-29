#ifndef MAINAPP_H
#define MAINAPP_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class mainapp;
}
QT_END_NAMESPACE

class mainapp : publid QWidget
{
    Q_OBJECT
public:
    explicit mainapp(QString fileName, QWidget *parent = nullptr);
    ~mainapp();

private slots:

private:
    Ui::mainapp *ui;
};

#endif // MAINAPP_H
