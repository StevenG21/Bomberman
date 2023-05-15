#include "player.h"
#define vel 4
#include <iostream>
#define anchobloque 63
#define altobloque 53
#define filas 17
#define columnas 17
using namespace std;
Player::Player(QObject *parent)
{
    dir=Direcciones::none;
    last=Direcciones::down;
    ancho=630/7; //tamaño del sprite
    alto=360/4;
    dx=dy=imy=imx=0;
    posx = 0;
    posy = 0;
velo = 4;

    bomber = new QPixmap(":/Images/NeoEarlyBomberman3.gif");
}

void Player::set_pos(int xn, int yn)
{
    posx=xn;
    posy=yn;
}






void Player::actualizar(int matriz[filas][columnas])
{
    imx += ancho;
    if(imx > ancho*6 ){
        imx = 0;
    }

    switch (dir) {
    case up:
          imy = 0;
          dx = 0;
          dy = -velo;


        break;
    case down:
    imy = 90*2;
    dx = 0;
    dy = velo;
        break;
    case Direcciones::left:
        imy = 90*3;
        dx = -velo;
        dy = 0;
        break;
    case Direcciones::right:
        imy = 90;
        dx = velo;
        dy = 0;
        break;
    case none:
        imy = 90*2;
        dx = 0;
        dy = 0;
        break;

}




    posJugador.setX(posJugador.x() + dx);
    posJugador.setY(posJugador.y() + dy);


 this->update();
validarmovimiento(matriz);


    cout<<posJugador.x()<<" x "<<posJugador.y()<<" y "<<endl;
}
QRectF Player::boundingRect() const
{


    return QRectF(posJugador.x(),posJugador.y(),ancho,alto);
}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{



       // Dibujar los rectángulos invisibles
       painter->setPen(Qt::red);
      // painter->setBrush(Qt::transparent);
       painter->drawRect(CDI());
       painter->setPen(Qt::green);
        painter->drawRect(CAA());




    painter->drawPixmap(posJugador.x(),posJugador.y(),*bomber,imx,imy,ancho,alto);

}

void Player::validarmovimiento(int matriz[17][17])
{
    int X = 0, Y = 0;


       for (int i = 0; i < filas; i++) {
           X = 0;
           for (int j = 0; j < columnas; j++) {
               QRectF bloqueRect(X, Y, 63, 53);

               if (matriz[i][j] == 1 && bloqueRect.intersects(CDI())) {
                   // Colisión detectada con un bloque sólido
                   // Realiza las acciones correspondientes, como detener el movimiento del jugador
                   velo = 0;

                   // También puedes agregar aquí código adicional específico para manejar la colisión con el bloque sólido

                   break; // Si no necesitas verificar más bloques sólidos después de la colisión, puedes usar break para salir del bucle interno
               }else{velo = 4;}

               X += 63;
           }

           Y += 53;

       }

    }


QRectF Player::CDI() //Colisiones derecha e izquierda
{
        qreal x = (90 - 25) / 2.0; // Calcula la diferencia de tamaño en el eje x y divide por 2
      // qreal y = (90 - 53) / 2.0; // Calcula la diferencia de tamaño en el eje y y divide por 2

     return QRectF((posJugador.x() + x)+dx, posJugador.y() + 53, 25, 25);
}

QRectF Player::CAA()// Colisiones Arriba y Abajo
{
        qreal x = (90 - 25) / 2.0; // Calcula la diferencia de tamaño en el eje x y divide por 2
      // qreal y = (90 - 53) / 2.0; // Calcula la diferencia de tamaño en el eje y y divide por 2

  return QRectF(posJugador.x() + x, (posJugador.y() + 53)+dy, 25, 25);
}
