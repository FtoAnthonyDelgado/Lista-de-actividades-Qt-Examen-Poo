#include "widget.h"
#include "ui_widget.h"
#include "personadialog.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QStringList titulos;
    setWindowTitle("Lista de cosas por hacer");
    ui->tableWidget->setColumnCount(4);
    titulos << "Nombre or Name" << "Fecha or Date" << "Prioridad or Priority" << "Tipo or Type";
    ui->tableWidget->setHorizontalHeaderLabels(titulos);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_agregar_clicked()
{
    //funcion para ejecutar personadialog primero y definimos como padre a widget
    int res, fila;
    QString nombre,prioridad,tipo,fecha;
    PersonaDialog pd(this);
    pd.setWindowTitle("Agregar Cosas Por Hacer");
    res = pd.exec();
    if(res == QDialog::Rejected)
        return;
    nombre = pd.nombre();
    fecha = pd.fecha();
    prioridad = pd.prioridad();
    tipo = pd.tipo();
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
    fila = ui->tableWidget->rowCount() -1;
    ui->tableWidget->setItem(fila, NOMBRE,new QTableWidgetItem(nombre));
    ui->tableWidget->setItem(fila, FECHA,new QTableWidgetItem((fecha)));
    ui->tableWidget->setItem(fila, PRIORIDAD,new QTableWidgetItem(prioridad));
    ui->tableWidget->setItem(fila, TIPO,new QTableWidgetItem(tipo));


}

