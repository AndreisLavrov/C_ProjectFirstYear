#include "aboutdialog.h"
#include "ui_aboutdialog.h"
#include <QPainter>
#include "renderarea.h"
#include <QHBoxLayout>


AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
}

AboutDialog::~AboutDialog()
{
    delete ui;
}


void AboutDialog::on_tabWidget_tabBarClicked(int index)
{
    _logo = new RenderArea(this);
    QHBoxLayout* horMainLayout = new QHBoxLayout(ui->graphicsView);
    horMainLayout->addWidget(_logo);
}

