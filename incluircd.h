#ifndef INCLUIRCD_H
#define INCLUIRCD_H

#include <QDialog>

namespace Ui {
class IncluirCD;
}

class IncluirCD : public QDialog
{
    Q_OBJECT

public:
    explicit IncluirCD(QWidget *parent = nullptr);
    ~IncluirCD();

    void clear();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::IncluirCD *ui;

signals:
    QString signIncluirCd(QString nome, QString preco, QString numero_de_faixas);

};

#endif // INCLUIRCD_H
