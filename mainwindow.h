#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColorDialog>
#include <QValidator>
#include <cstdlib>
#include <ctime>
#include "lista_figura.h"
#include "paintboard.h"
#include "figura.h"
#include "rectangulo.h"
#include "circulo.h"
#include "rectangulosombreado.h"




namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void inicializar_colores();

private:
    Ui::MainWindow *ui;
    lista_figura *lista;
    PaintBoard *board;
    QColor currentColor, backGroundColor;
    QValidator *validator;
    void resetValues();


private slots:
    void on_pbGenerar_clicked();
    void on_pbAgregarCirculo_clicked();
    void on_pbMover_clicked();
    void on_pbLimpiar_clicked();
    void on_pbColor_2_clicked();
    void on_pbColor_clicked();
    void on_pbAgregar_clicked();
    void actualizar_Data_CurrentFigura (int cual);
    void on_pbRemove_clicked();
    void on_pbCalAreas_clicked();
    void on_pbInsertar_clicked();
};

#endif // MAINWINDOW_H
