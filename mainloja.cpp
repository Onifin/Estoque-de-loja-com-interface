#include "mainloja.h"
#include "ui_mainloja.h"

MainLoja::MainLoja(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainLoja),
      janela_incluir_livro(nullptr),
      janela_incluir_CD(nullptr),
      janela_incluir_DVD(nullptr),
      X(),
      total_itens(nullptr)
{
    ui->setupUi(this);
    //QVBoxLayout* layout = new QVBoxLayout();
    //setLayout(layout);
    //setMinimumSize(1000, 600);

    janela_incluir_livro = new IncluirLivro(this);
    janela_incluir_CD = new IncluirCD(this);
    janela_incluir_DVD = new IncluirDVD(this);
    total_itens = new QLabel(this);

    ui->statusbar->insertWidget(0, new QLabel("Total de itens: "));

    connect(janela_incluir_livro, & IncluirLivro::signIncluirLivro, this, & MainLoja::slotIncluirLivro);
    connect(janela_incluir_CD, & IncluirCD::signIncluirCd, this, & MainLoja::slotIncluirCD);
    connect(janela_incluir_DVD, & IncluirDVD::signIncluirDvd, this, & MainLoja::slotIncluirDVD);

    ui->statusbar->insertWidget(1, total_itens);

    //ui->labelLivros->setStyleSheet("background-color:lightgray ");

    //ui->labelLivros->setAlignment(Qt::AlignCenter);

    ui->tableLivros->setStyleSheet( "QHeaderView::section { text-align:center }"
                                    "QHeaderView::section { font: bold }"
                                    "QHeaderView::section { background-color:lightgray }");

    ui->tableCds->setStyleSheet( "QHeaderView::section { text-align:center }"
                                    "QHeaderView::section { font: bold }"
                                    "QHeaderView::section { background-color:lightgray }");

    ui->tableDvds->setStyleSheet( "QHeaderView::section { text-align:center }"
                                    "QHeaderView::section { font: bold }"
                                    "QHeaderView::section { background-color:lightgray }");

    ui->tableLivros->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);
    ui->tableLivros->horizontalHeader()->setSectionResizeMode(1,QHeaderView::ResizeToContents);
    ui->tableLivros->horizontalHeader()->setSectionResizeMode(2,QHeaderView::ResizeToContents);

    ui->tableCds->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);
    ui->tableCds->horizontalHeader()->setSectionResizeMode(1,QHeaderView::ResizeToContents);
    ui->tableCds->horizontalHeader()->setSectionResizeMode(2,QHeaderView::ResizeToContents);

    ui->tableDvds->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);
    ui->tableDvds->horizontalHeader()->setSectionResizeMode(1,QHeaderView::ResizeToContents);
    ui->tableDvds->horizontalHeader()->setSectionResizeMode(2,QHeaderView::ResizeToContents);

    exibeLivros();
    exibeCds();
    exibeDvds();
}

MainLoja::~MainLoja()
{
    delete ui;
}

void MainLoja::exibeLivros()
{
    ui->tableLivros->clearContents();
    ui->tableLivros->setRowCount(X.getNumLivro());

    for(int i = 0; i <= (X.getNumLivro()-1); i++){
        Livro L = X.getLivro(i);
        QLabel* aux_nome = new QLabel(L.getNome().c_str());
        QLabel* aux_preco = new QLabel(QString::number(L.getPreco(),'f',2));
        QLabel* aux_autor = new QLabel(L.getAutor().c_str());

        aux_nome->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        aux_preco->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
        aux_autor->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);

        ui->tableLivros->setCellWidget(i,0, aux_nome);
        ui->tableLivros->setCellWidget(i,1, aux_preco);
        ui->tableLivros->setCellWidget(i,2, aux_autor);
    }

    total_itens->setNum(X.getNumLivro()+X.getNumCD()+X.getNumDVD());
}

void MainLoja::exibeCds()
{
    ui->tableCds->clearContents();
    ui->tableCds->setRowCount(X.getNumCD());

    for(int i = 0; i <= (X.getNumCD()-1); i++){
        CD C = X.getCD(i);
        QLabel* aux_nome = new QLabel(C.getNome().c_str());
        QLabel* aux_preco = new QLabel(QString::number(C.getPreco(),'f',2));
        QLabel* aux_numero_faixas = new QLabel(QString::number(C.getNumFaixas()));

        aux_nome->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        aux_preco->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
        aux_numero_faixas->setAlignment(Qt::AlignCenter|Qt::AlignVCenter);

        ui->tableCds->setCellWidget(i,0, aux_nome);
        ui->tableCds->setCellWidget(i,1, aux_preco);
        ui->tableCds->setCellWidget(i,2, aux_numero_faixas);
    }

    total_itens->setNum(X.getNumLivro()+X.getNumCD()+X.getNumDVD());
}

void MainLoja::exibeDvds()
{
    ui->tableDvds->clearContents();
    ui->tableDvds->setRowCount(X.getNumDVD());

    for(int i = 0; i <= (X.getNumDVD()-1); i++){
        DVD D = X.getDVD(i);
        QLabel* aux_nome = new QLabel(D.getNome().c_str());
        QLabel* aux_preco = new QLabel(QString::number(D.getPreco(),'f',2));
        QLabel* aux_duracao = new QLabel(QString::number(D.getDuracao()));

        aux_nome->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);
        aux_preco->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
        aux_duracao->setAlignment(Qt::AlignCenter|Qt::AlignVCenter);

        ui->tableDvds->setCellWidget(i,0, aux_nome);
        ui->tableDvds->setCellWidget(i,1, aux_preco);
        ui->tableDvds->setCellWidget(i,2, aux_duracao);
    }

    total_itens->setNum(X.getNumLivro()+X.getNumCD()+X.getNumDVD());
}



void MainLoja::on_tableLivros_cellDoubleClicked(int row)
{
    if(row <= X.getNumLivro()-1){
        if(X.excluirLivro(row)) exibeLivros();
    }

}

void MainLoja::on_tableCds_cellDoubleClicked(int row)
{
    if(row <= X.getNumCD()-1){
        if(X.excluirCD(row)) exibeCds();
    }

}

void MainLoja::on_tableDvds_cellDoubleClicked(int row)
{
    if(row <= X.getNumDVD()-1){
        if(X.excluirDVD(row)) exibeDvds();
    }
}

void MainLoja::slotIncluirLivro(QString nome, QString preco, QString autor)
{
    Livro novo_livro(nome.toStdString() , round(preco.toFloat()*100), autor.toStdString());

    if(novo_livro.getNome() != "" && novo_livro.getAutor() != "" && novo_livro.getPreco()>0){
        X.incluirLivro(novo_livro);
        exibeLivros();
        return;
    }
    QMessageBox::critical(this, "Livro invalido", "Nao foi possivel incluir o Livro: \nNome="+nome.toLatin1() + "\nPreco=" + preco.toLatin1() + "\nAutor=" + autor.toLatin1());

}
void MainLoja::slotIncluirCD(QString nome, QString preco, QString numfaixas)
{

    CD novo_CD(nome.toStdString() , round(preco.toFloat()*100), numfaixas.toFloat());

    if(novo_CD.getNome() != "" && novo_CD.getNumFaixas()>0 && novo_CD.getPreco()>0){
        X.incluirCD(novo_CD);
        exibeCds();
        return;
    }
    QMessageBox::critical(this, "CD invalido", "Nao foi possivel incluir o CD: \nNome="+nome.toLatin1() + "\nPreco=" + preco.toLatin1() + "\nNum faixas=" + numfaixas.toLatin1());
}
void MainLoja::slotIncluirDVD(QString nome, QString preco, QString duracao)
{
    DVD novo_DVD(nome.toStdString() , round(preco.toFloat()*100), duracao.toFloat());

    if(novo_DVD.getNome() != "" && novo_DVD.getDuracao()>0 && novo_DVD.getPreco()>0){
        X.incluirDVD(novo_DVD);
        exibeDvds();
        return;
    }
    QMessageBox::critical(this, "DVD invalido", "Nao foi possivel incluir o DVD: \nNome="+nome.toLatin1() + "\nPreco=" + preco.toLatin1() + "\nNum Duracao=" + duracao.toLatin1());

}

//LER | SALVAR | SAIR

void MainLoja::on_actionLer_triggered()
{
    QString arquivo = QFileDialog::getOpenFileName(this, "Ler estoque", QString() ,"Text Files(*.txt)");
    if(!X.ler(arquivo.toStdString())) QMessageBox::critical(this, "Erro", "Erro em abrir arquivo");

    exibeLivros();
    exibeCds();
    exibeDvds();
}


void MainLoja::on_actionSalvar_triggered()
{
    QString arquivo = QFileDialog::getSaveFileName(this, "Salvar estoque", QString(), "Text Files(*.txt)");
    if(!X.salvar(arquivo.toStdString())) QMessageBox::critical(this, "Erro", "Erro no salvamento do arquivo");
}


void MainLoja::on_actionSair_triggered()
{
    QCoreApplication::quit();
}


void MainLoja::on_actionIncluir_Livro_triggered()
{
    (*janela_incluir_livro).clear();
    (*janela_incluir_livro).setVisible(true);
}


void MainLoja::on_actionIncluir_CD_triggered()
{
    (*janela_incluir_CD).clear();
    (*janela_incluir_CD).setVisible(true);
}


void MainLoja::on_actionIncluir_DVD_triggered()
{
    (*janela_incluir_DVD).clear();
    (*janela_incluir_DVD).setVisible(true);
}

