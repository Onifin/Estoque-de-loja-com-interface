#include "incluircd.h"
#include "ui_incluircd.h"

IncluirCD::IncluirCD(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IncluirCD)
{
    ui->setupUi(this);
}

IncluirCD::~IncluirCD()
{
    delete ui;
}

void IncluirCD::clear(){
    ui->lineEdit_nome->setText("");
    ui->lineEdit_preco->setText("");
    ui->lineEdit_faixas->setText("");
}

void IncluirCD::on_buttonBox_accepted()
{
    QString nome = ui->lineEdit_nome->text();
    QString preco = ui->lineEdit_preco->text();
    QString numero_de_faixas = ui->lineEdit_faixas->text();

    emit signIncluirCd(nome, preco, numero_de_faixas);
}

