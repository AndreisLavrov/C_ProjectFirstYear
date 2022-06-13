#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>
#include "renderarea.h"

namespace Ui {
class AboutDialog;
}

class AboutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AboutDialog(QWidget *parent = nullptr);
    ~AboutDialog();

private slots:

    void on_tabWidget_tabBarClicked(int index);

private:
    Ui::AboutDialog *ui;
    RenderArea* _logo;


};



#endif // ABOUTDIALOG_H
