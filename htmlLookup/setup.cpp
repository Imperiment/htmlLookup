#include "setup.h"
#include "ui_setup.h"
#include "mainapp.h"

#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QTreeWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


QString fileNameFromTree;

// TODO:
// 1. Fix the visual bug with remove and open btns in the setup window


void MainWindow::on_testBtn_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Choose File (.html)", "C:/Users/davos/Documents/Funzies/formInformatika", "HTML Files (*.html);;All Files (*)");
    if (fileName.isEmpty()) {
        return;
    }

    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Error!", "Can't open file!");
        return;
    }

    QTextStream in(&file);
    QString content = in.readAll();
    file.close();

    QTreeWidgetItem* itemSelect = new QTreeWidgetItem();

    ui->destinationResult->setText(fileName);
    itemSelect->setText(0, fileName);
    ui->treeWidget->addTopLevelItem(itemSelect);



}

void MainWindow::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    if (item) {
        fileNameFromTree = item->text(column);
        ui->destinationResult->setText(fileNameFromTree);
        ui->openBtn->setEnabled(true);
        ui->removeBtn->setEnabled(true);
    }
}


void MainWindow::on_removeBtn_clicked()
{
    QTreeWidgetItem* selectedItem = ui->treeWidget->currentItem();
    if (selectedItem) {
        delete selectedItem;
        fileNameFromTree.clear();
        ui->destinationResult->setText(fileNameFromTree);
        ui->openBtn->setEnabled(false);
        ui->treeWidget->setFocus();
        ui->removeBtn->setEnabled(false);
        ui->removeBtn->update();

    }
}

void closeMainBox(QString selectedItem) {
    mainapp *main = new mainapp();
    main->show();
    this->close();
}


void MainWindow::on_openBtn_clicked()
{
    QTreeWidgetItem* selectedItem = ui->treeWidget->currentItem();
    int selectedColumn = ui->treeWidget->currentColumn();
    QString fileName = selectedItem->text(selectedColumn);
    if (selectedItem) {
        closeMainBox(fileName);
    }
}

