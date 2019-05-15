#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <omp.h> //openmp
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ButtonCalculatePI_clicked()
{

    if(!ui->lineEditProcNumber->text().isEmpty()){
        NumberOfProcessors=ui->lineEditProcNumber->text().toInt();
    }

    if(!ui->lineEditValueN->text().isEmpty()){
        Nvalue=ui->lineEditValueN->text().toInt();
    }
    int N = Nvalue;
    double result=0;
    int NProc = NumberOfProcessors;
    omp_set_num_threads(NProc);
#pragma omp parallel private(N) shared(result)
    {
        #pragma omp for reduction (+:result)
        for(int i=0; i<N;i++){
            result+=(1/(double)N)*(4/(1+ ((i+0.5)/(double)N)*((i+0.5)/(double)N) ));
        }
    }
    ui->lineEditResult->setText(QString::number(result));

}
