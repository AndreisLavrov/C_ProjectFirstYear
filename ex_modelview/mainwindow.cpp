#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "addrowdialog.h"
#include <QFileDialog>
#include <QMessageBox>
#include "aboutdialog.h"
#include <QHBoxLayout>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->addRowButton, SIGNAL(clicked()), this, SLOT(addRowSlot()));
    QObject::connect(ui->actionLoad, SIGNAL(triggered()), this, SLOT(loadFile()));
    QObject::connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(showAbout()));
    
    _exampleModel = new ExampleModel(this);

    proxyModel = new QSortFilterProxyModel(this);

    proxyModelPrice = new CustomProxyModel(this);

    proxyModelYear = new CustomProxyModel1(this);

    proxyModelRating = new CustomProxyModel2(this);

    proxyModel->setSourceModel(_exampleModel);

    proxyModelPrice->setSourceModel(proxyModel);

    proxyModelYear->setSourceModel(proxyModelPrice);

    proxyModelRating->setSourceModel(proxyModelYear);

    ui->tableView->setModel(proxyModelRating);

    ui->tableView->setSortingEnabled(true);

    proxyModel->setFilterKeyColumn(1);
    
    _shownDetailsColumn = 0;


}


void MainWindow::loadFile()
{
    delete _exampleModel;
    
    _exampleModel = new ExampleModel(this);
    QString fileName = QFileDialog::getOpenFileName(this, "Open File",
                                                    "../",
                                                    "Data (*.csv)");
    _exampleModel->fillDataTableFromFile(fileName);
    
    proxyModel->setSourceModel(_exampleModel);

    _shownDetailsColumn = 0;
}


void MainWindow::showAbout()
{
    AboutDialog d;
    d.exec();
}

void MainWindow::addRowSlot()
{
    AddRowDialog d(this);
    if (d.exec() == QDialog::Accepted)
    {
        _exampleModel->appendRow(d.getNewRow());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_removeRowButton_clicked()
{
    QString name = ui ->lineEdit->text();
    bool success = _exampleModel->removeRow(name);

}


void MainWindow::on_pushButton_4_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Open File", ".../", "Data (*.csv)");
    _exampleModel->saveDataToFile(fileName);
}


void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    proxyModelPrice->setFilterMinimumPrice(value);
}


void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    proxyModelYear->setFilterMinimumYear(value);
}



void MainWindow::on_comboBox_activated(int index)
{
    if(index == 1)
    {
        ui->tableView->sortByColumn(0,Qt::AscendingOrder);
    }
    else if(index == 2)
    {
        ui->tableView->sortByColumn(1,Qt::AscendingOrder);
    }
    else if(index == 3)
    {
        ui->tableView->sortByColumn(2,Qt::DescendingOrder);
    }
    else if(index == 4)
    {
        ui->tableView->sortByColumn(3,Qt::DescendingOrder);
    }
    else if(index == 5)
    {
        ui->tableView->sortByColumn(3,Qt::AscendingOrder);
    }
    else if(index == 6)
    {
        ui->tableView->sortByColumn(4,Qt::DescendingOrder);
    }
    else if(index == 7)
    {
        ui->tableView->sortByColumn(4,Qt::AscendingOrder);
    }
    else if(index == 0)
    {
        ui->tableView->reset();
    }
}


void MainWindow::on_checkBox_2_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked)
    {
        proxyModelRating->setFilterMinimumRating(4);
    }
    else
    {
        proxyModelRating->setFilterMinimumRating(3);
    }
}


void MainWindow::on_checkBox_3_stateChanged(int arg1)
{
    proxyModelRating->setFilterMinimumRating(3);
}


void MainWindow::on_checkBox_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked)
    {
        proxyModel->setFilterKeyColumn(5);
        proxyModel->setFilterRegExp("^Fiction$");
    }

}

void MainWindow::on_comboBox_2_currentIndexChanged(int index)
{
    proxyModel->setFilterKeyColumn(index);
}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    proxyModel->setFilterFixedString(arg1);
}

void MainWindow::on_checkBox_4_stateChanged(int arg1)
{
    if(arg1 == Qt::Checked)
    {
        proxyModel->setFilterKeyColumn(5);
        proxyModel->setFilterRegExp("^Non Fiction$");
    }
}




