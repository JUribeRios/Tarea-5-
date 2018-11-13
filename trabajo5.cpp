#include "trabajo5.h"
#include "ui_trabajo5.h"

Trabajo5::Trabajo5(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Trabajo5)
{
    ui->setupUi(this);

    srand(time(NULL));
    timer=new QTimer(this);
    scene=new QGraphicsScene(this);
    scene->setSceneRect(0,0,ANCHO,ALTO);

    ui->graphicsView->setScene(scene);

    scene->addRect(scene->sceneRect());

    ui->graphicsView->resize(scene->width(),scene->height());
    this->resize(ui->graphicsView->width()+100,ui->graphicsView->height()+100);

    part = new Particula(50,50,30);
    scene->addItem(part);
    part->mover(ALTO);

    timer->stop();
    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar_escena()));
}

Trabajo5::~Trabajo5()
{
    delete ui;
    delete part;
    delete timer;
    delete scene;
}

void Trabajo5::on_pushButton_clicked()
{
    timer->start(20);
}

void Trabajo5::actualizar_escena()
{
    part->mover(ALTO);
    part->colision(ANCHO,ALTO);
}
