#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_agregar_clicked();



private:
    Ui::Widget *ui;

    enum Columna
    {
        NOMBRE, FECHA, PRIORIDAD, TIPO
    };
};
#endif // WIDGET_H
