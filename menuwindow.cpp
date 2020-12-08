#include "menuwindow.h"
#include "ui_menuwindow.h"

MenuWindow::MenuWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuWindow)
{
    ui->setupUi(this);
    ui->radioButton->setChecked(true);
    }

MenuWindow::~MenuWindow()
{
    delete ui;
}

void MenuWindow::ret()
{
    this->show();
    delete mw;
}

void MenuWindow::on_pushButton_clicked()
{
    int m;
    int n;
    int bomb;
    if (ui->radioButton->isChecked())
    {
        m=9;
        n=9;
        bomb=10;
    }
    else if (ui->radioButton_2->isChecked())
    {
        m=16;
        n=16;
        bomb=40;
    }
    else if (ui->radioButton_3->isChecked())
    {
        m=30;
        n=16;
        bomb=99;
    }
    else {
        n=ui->spinBox->value();
        m=ui->spinBox_2->value();
        bomb=ui->spinBox_3->value();
    }
    mw = new MainWindow(n, m, bomb);
    connect(mw, &MainWindow::showMenu, this, &MenuWindow::ret);
    mw->show();
    this->hide();
}

void MenuWindow::on_checkBox_stateChanged(int arg1)
{

}

void MenuWindow::on_pushButton_3_clicked()
{
    QWidget::close();
}
