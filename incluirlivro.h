#ifndef INCLUIRLIVRO_H
#define INCLUIRLIVRO_H

#include <QDialog>

namespace Ui {
class IncluirLivro;
}

class IncluirLivro : public QDialog
{
    Q_OBJECT

public:
    explicit IncluirLivro(QWidget *parent = nullptr);
    ~IncluirLivro();

    void clear();

private:
    Ui::IncluirLivro *ui;

signals:
    QString signIncluirLivro(QString nome, QString preco, QString autor);

private slots:
    void on_buttonBox_accepted();
};

#endif // INCLUIRLIVRO_H
