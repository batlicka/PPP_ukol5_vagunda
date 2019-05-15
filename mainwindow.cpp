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
        Nvalue=ui->lineEditValueN->text().toDouble();
    }
    double N = Nvalue;
    double result=0;
    int NProc = NumberOfProcessors;

#pragma omp parallel num_threads(NProc) private(N) shared(result)
        #pragma omp for reduction (+:result)
        for(int i=0; i<N;i++){
            result+=(1/N)*(4/(1+ ((i+0.5)/N)*((i+0.5)/N) ));
        }
    
    ui->lineEditResult->setText(QString::number(result));

}
