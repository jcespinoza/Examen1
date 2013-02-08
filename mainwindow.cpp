#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "string.h"
#include <ostream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Validar que todos los line edits solo
    // Solo soporten valores entre 0 y 600
    validator = new QIntValidator(0, 600, this);
    ui->leMX->setValidator(validator);
    ui->leMY->setValidator(validator);
    ui->leAlto->setValidator(validator);
    ui->leAncho->setValidator(validator);
    ui->leRadio->setValidator(validator);

    this->lista = new lista_figura();
    this->board = new PaintBoard();

    this->board->setListaFiguras(this->lista);


    this->ui->gridLayout->addWidget(this->board,
                                    0,0,1,1);

    this->inicializar_colores();

    connect(this->board,SIGNAL(currentFiguraChanged(int)),
            this,SLOT(actualizar_Data_CurrentFigura(int)));

    srand(time(0)); // Inicializar la semilla del random

}

MainWindow::~MainWindow()
{
    delete ui;
    delete this->board;
    delete this->lista; // o  this->lista->limpiar();
}

void MainWindow::on_pbAgregar_clicked()
{
    Rectangulo *R;
    if (!ui->checkBoxSombreado->isChecked())
          R = new Rectangulo();
    else
          R = new RectanguloSombreado();

    // TODO ... llenar del UI los parametros
    QColor color = this->ui->lblColor->palette().background().color();
    QColor fondo = this->ui->lblFondo->palette().background().color();

    R->setColor(color);
    R->setFondo(fondo);
    R->setX(ui->spinBoxX->value());
    R->setY(ui->spinBoxY->value());
    R->setAlto(ui->leAlto->text().toInt());
    R->setAncho(ui->leAncho->text().toInt());

    this->lista->agregar(R);

    this->board->update();

}

void MainWindow::on_pbColor_clicked()
{
    QColor color = QColorDialog::getColor();
    QPalette pal = ui->lblColor->palette();
    pal.setColor(ui->lblColor->backgroundRole(),color);
    ui->lblColor->setPalette(pal);
    ui->lblColor->setAutoFillBackground(true);


    //ui->lblColor->setStyleSheet("background-color: green");

}

void MainWindow::actualizar_Data_CurrentFigura (int cual)
{
    QString temp;
    temp.setNum(cual);
    this->ui->leCurrentFigura->setText(temp);
    if(cual!=0)
    {
        Figura *F=this->lista->recuperar(cual);
        temp.setNum(F->getX());
        ui->leMX->setText(temp);
        temp.setNum(F->getY());
        ui->leMY->setText(temp);
   }
}

void MainWindow::inicializar_colores()
{

    QPalette pal = ui->lblFondo->palette();
    pal.setColor(ui->lblFondo->backgroundRole(),Qt::blue);
    ui->lblFondo->setPalette(pal);
    ui->lblFondo->setAutoFillBackground(true);

    pal = ui->lblColor->palette();
    pal.setColor(ui->lblColor->backgroundRole(),Qt::black);
    ui->lblColor->setPalette(pal);
    ui->lblColor->setAutoFillBackground(true);

}

void MainWindow::on_pbColor_2_clicked()
{
    QColor color = QColorDialog::getColor();
    QPalette pal = ui->lblFondo->palette();
    pal.setColor(ui->lblFondo->backgroundRole(),color);
    ui->lblFondo->setPalette(pal);
    ui->lblFondo->setAutoFillBackground(true);
}

void MainWindow::on_pbLimpiar_clicked()
{
    this->lista->limpiar();
    this->board->update();
}

void MainWindow::on_pbMover_clicked()
{
    int cual = ui->leCurrentFigura->text().toInt();
    if (cual!=0)
    {
        Figura *F = lista->recuperar(cual);
        F->setX(ui->leMX->text().toInt());
        F->setY(ui->leMY->text().toInt());
        this->board->update();

    }
}

void MainWindow::on_pbAgregarCirculo_clicked()
{
    Circulo *C = new Circulo();
    // TODO ... llenar del UI los parametros
    QColor color = this->ui->lblColor->palette().background().color();
    QColor fondo = this->ui->lblFondo->palette().background().color();

    C->setColor(color);
    C->setFondo(fondo);
    C->setX(ui->spinBoxX->value());
    C->setY(ui->spinBoxY->value());
    C->setRadio(ui->leRadio->text().toInt());
    this->lista->agregar(C);
    this->board->update();
}

void MainWindow::on_pbGenerar_clicked()
{
    int cuantos = ui->leGenerar->text().toInt();
    for (int i=0; i< cuantos; i++)
    {
        int x = rand()%500;
        int y = rand()%400;
        QColor fondo(rand()%255,rand()%255,rand()%255);
        int alto = rand()%40;
        int ancho = rand()%40;
        Rectangulo *R = new Rectangulo(x,y,ancho,alto,Qt::black,fondo);
        this->lista->agregar(R);

    }
    this->board->update();
}

void MainWindow::on_pbRemove_clicked()
{
    int p = ui->leCurrentFigura->text().toInt();
    if(p == 0) return;
    if(!lista->vacia() && lista->remover(p) != 0){
        board->update();
        resetValues();
    }
}

void MainWindow::resetValues(){
    ui->leCurrentFigura->setText(QString("0"));
    ui->leMX->setText(QString("0"));
    ui->leMY->setText(QString("0"));
}

void MainWindow::on_pbCalAreas_clicked()
{
    ui->lwAreas->clear();
    lista->ir_a_inicio();
    for(int i = 1; i <= lista->getCuantos(); i++){
        double ar = lista->recuperar()->area();
        QString f("Figura ");
        f = f + QString::number(i) + QString(" ");
        f = f + QString(lista->recuperar()->tipoFigura());
        ui->lwAreas->addItem(f + QString(" " + QString::number(ar)));
        lista->siguiente();
    }
}

void MainWindow::on_pbInsertar_clicked()
{
    Rectangulo *R;
    if (!ui->checkBoxSombreado->isChecked())
          R = new Rectangulo();
    else
          R = new RectanguloSombreado();

    // TODO ... llenar del UI los parametros
    QColor color = this->ui->lblColor->palette().background().color();
    QColor fondo = this->ui->lblFondo->palette().background().color();

    R->setColor(color);
    R->setFondo(fondo);
    R->setX(ui->spinBoxX->value());
    R->setY(ui->spinBoxY->value());
    R->setAlto(ui->leAlto->text().toInt());
    R->setAncho(ui->leAncho->text().toInt());
    lista->insertar(ui->spPosition->value(), R);
    board->update();
    qDebug() << "inserted it at " << ui->spPosition->value();
    qDebug() << "Now there are " << lista->getCuantos() << " figures";
}
