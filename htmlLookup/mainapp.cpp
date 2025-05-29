#include "mainapp.h"
#include "ui_mainapp.h"

mainapp::mainapp(QString fileName, QWidget *parent)
{
QWidget(parent), ui(new Ui::mainapp)
    {
        ui->setupUi(this);
    }
}

mainapp::~mainapp()
{
    delete ui;
}
