#ifndef PARTICULA_H
#define PARTICULA_H

#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>
#include <iostream>
#include "math.h"
#define g 10
#define pi 3.1415
using namespace std;


class Particula : public QGraphicsItem
{
public:
   // Constructor para inicializar la posicion en x,y en todo instante, el radio la posicion inicial en x,y,
    //la velocidad en x,y y el angulo
    Particula(float m_x, float m_y, float m_r): px(m_x), py(m_y), r(m_r),y0(py),x0(px){vx=80;vy=80;t=0;ang=45;}
    void mover(float vertlim); // Metodo para actualizar posición de la particula
    void colision (float horzlim, float vertlim); // Metodo para detectar choques de la particula con bordes
    void setvelocidad(float vel_x, float vel_y); // Metodo para cambiar velocidad en x,y
    void setposicion(float x, float y);  // Metodo para cambiar las coordenadas x,y de la particula
    float getradio();   //Metodo para obtener el radio
    float getpos_x();    //Metodo para obtener la posicion en x
    float getpos_y();    //Metodo para obtener la posicion en y    
    float getvel_x();    //Metodo para obtener la velocidad en x
    float getvel_y();    //Metodo para obtener la velocidad en y
    void setangulo(int a); //Metodo para cambiar el angulo
    int getangulo(); //Metodo para obtener el angulo

    //Redefinicion de los metodos boundingRect() y paint() de la clase QGraphicsItem
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem*option,QWidget*widget);

private:
    float px;  //Coordenada x
    float py;  //Coordenada y
    float r;   //Radio
    float vx;  //Velocidad en x
    float vy;  //Velocidad en y
    float y0; // Posicion inicial en y
    float x0; // Posicion inicial en x
    int ang;  //Angulo
    float t;  //Delta de tiempo


    Particula();
};

#endif // PARTICULA_H
