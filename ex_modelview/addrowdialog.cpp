#include "addrowdialog.h"
#include "ui_addrowdialog.h"
#include <QMessageBox>

AddRowDialog::AddRowDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddRowDialog)
{
    ui->setupUi(this);
    
    QObject::connect(ui->okButton, SIGNAL(clicked()), this, SLOT(saveAddedRow()));
    QObject::connect(ui->cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
}

void AddRowDialog::saveAddedRow()
{
    newRow.push_back(ui->NameLineEdit->text());
    newRow.push_back(ui->AuthorLineEdit->text());
    newRow.push_back(ui->RatingLineEdit->text());
    newRow.push_back(ui->PriceLineEdit->text());
    newRow.push_back(ui->YearLineEdit->text());
    newRow.push_back(ui->GenrelineEdit->text());

    newRow.push_back("");
    newRow.push_back("");
    newRow.push_back("");
    newRow.push_back("");
    newRow.push_back("");
    newRow.push_back("");

    
    accept();
}

const QList<QVariant>& AddRowDialog::getNewRow()
{
    return newRow;
}


AddRowDialog::~AddRowDialog()
{
    delete ui;
}
