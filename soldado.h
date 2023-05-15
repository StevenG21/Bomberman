#ifndef SOLDADO_H
#define SOLDADO_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QPixmap>
#include <iostream>
using namespace std;

class soldado: public QObject,
        public QGraphicsPixmapItem
{
    Q_OBJECT

private:
    QPointF previousPosition_;
    int x=63;
    int y=53;




public:

    void advances();

    soldado(QGraphicsItem* carr = 0);
    QGraphicsPixmapItem* solido();

    int getX() const;
    void setX(int value);
    int getY() const;
    void setY(int value);

    //Definir posicion graficar
    void posicion();
    void posicion(int newX, int newY);



};

#endif // SOLDADO_H
