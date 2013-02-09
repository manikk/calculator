#include "dialog.h"
#include "ui_dialog.h"
#include <QStringList>
#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->operationClicked = "";
    this->mem = "";
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::onNumberButtonClicked()
{
    QString btnName = sender()->objectName();
    QStringList strList = btnName.split("_");
    ui->lineEdit->setText(ui->lineEdit->text() + strList.at(1));
}

void Dialog::onPlusButtonClicked()
{
    this->operationClicked = "+";
    this->mem = ui->lineEdit->text();
    ui->lineEdit->setText("");
}

void Dialog::onMinusButtonClicked()
{
    this->operationClicked = "-";
    this->mem = ui->lineEdit->text();
    ui->lineEdit->setText("");
}

void Dialog::onClearButtonClicked()
{
    this->operationClicked = "";
    ui->lineEdit->setText("");
    this->mem = "";
}

void Dialog::onEqualButtonClicked()
{
    int operand1 = this->mem.toInt();
    int operand2 = ui->lineEdit->text().toInt();
    int res;
    if(this->operationClicked == "+") {
        res = operand1 + operand2;
        ui->lineEdit->setText(QString::number(res));
    }else if(this->operationClicked == "-"){
       res = operand1 - operand2;
       ui->lineEdit->setText(QString::number(res));
    }
}



void Dialog::resetLineEdit()
{
    ui->lineEdit->setText("");
}
