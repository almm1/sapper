#include "menuwindow.h"
#include "ui_menuwindow.h"

MenuWindow::MenuWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuWindow)
{
    ui->setupUi(this);
}

MenuWindow::~MenuWindow()
{
    delete ui;
}

void MenuWindow::on_pushButton_clicked()
{
    MainWindow w;
    //this->hide();
    w.show();
   // if (ui->checkBox->checkState() == Qt::CheckState())
    {

    }
}

void MenuWindow::on_checkBox_stateChanged(int arg1)
{

}
