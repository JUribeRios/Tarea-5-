#ifndef TRABAJO5_H
#define TRABAJO5_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>
#include <cstdlib>
#include <ctime>
#include "particula.h"

#define ANCHO 1000
#define ALTO 500


#include <QMainWindow>

namespace Ui {
class Trabajo5;
}

class Trabajo5 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Trabajo5(QWidget *parent = nullptr);
    ~Trabajo5();

private slots:
    void on_pushButton_clicked();
    void actualizar_escena();

private:
    Ui::Trabajo5 *ui;
    QTimer *timer =nullptr;
    QGraphicsScene *scene = nullptr;
    Particula *part = nullptr;
};

#endif // TRABAJO5_H
