#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <omp.h> //openmp
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ButtonCalculatePI_clicked();

private:
    Ui::MainWindow *ui;
    int NumberOfProcessors;
    double Nvalue;
};

#endif // MAINWINDOW_H
