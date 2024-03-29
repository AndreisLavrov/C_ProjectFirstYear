#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTransposeProxyModel>
#include "examplemodel.h"
#include <QSortFilterProxyModel>
#include "customproxymodel.h"
#include "customproxymodel1.h"
#include "customproxymodel2.h"
#include "renderarea.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    
private slots:
   void loadFile();

   void addRowSlot();

   void on_removeRowButton_clicked();

   void on_pushButton_4_clicked();

   void on_horizontalSlider_valueChanged(int value);

   void on_horizontalSlider_2_valueChanged(int value);

   void showAbout();

   void on_comboBox_activated(int index);

   void on_checkBox_2_stateChanged(int arg1);

   void on_checkBox_3_stateChanged(int arg1);

   void on_checkBox_stateChanged(int arg1);

   void on_lineEdit_2_textChanged(const QString &arg1);

   void on_comboBox_2_currentIndexChanged(int index);

   void on_checkBox_4_stateChanged(int arg1);


private:
    size_t _shownDetailsColumn;
    ExampleModel *_exampleModel;
    QSortFilterProxyModel *proxyModel;
    Ui::MainWindow *ui;
    CustomProxyModel *proxyModelPrice;
    CustomProxyModel1 *proxyModelYear;
    CustomProxyModel2 *proxyModelRating;
    //RenderArea* _logo;
};
#endif // MAINWINDOW_H
