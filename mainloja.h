#ifndef MAINLOJA_H
#define MAINLOJA_H

#include <QMainWindow>
#include <QFileDialog>
#include <QtWidgets>

#include "incluircd.h"
#include "incluirdvd.h"
#include "incluirlivro.h"
#include "loja.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainLoja; }
QT_END_NAMESPACE

class MainLoja : public QMainWindow
{
    Q_OBJECT

public:
    MainLoja(QWidget *parent = nullptr);
    ~MainLoja();

    void exibeLivros();
    void exibeCds();
    void exibeDvds();

private slots:
    void on_tableLivros_cellDoubleClicked(int row);

    void on_tableCds_cellDoubleClicked(int row);

    void on_tableDvds_cellDoubleClicked(int row);

    void on_actionLer_triggered();

    void on_actionSalvar_triggered();

    void on_actionSair_triggered();

    void on_actionIncluir_Livro_triggered();

    void on_actionIncluir_CD_triggered();

    void on_actionIncluir_DVD_triggered();

    void slotIncluirLivro(QString nome, QString preco, QString autor);
    void slotIncluirCD(QString nome, QString preco, QString numfaixas);
    void slotIncluirDVD(QString nome, QString preco, QString duracao);



private:
    Ui::MainLoja *ui;

    IncluirLivro* janela_incluir_livro;
    IncluirCD* janela_incluir_CD;
    IncluirDVD* janela_incluir_DVD;
    Loja X;
    QLabel* total_itens;
};
#endif // MAINLOJA_H
