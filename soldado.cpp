#include "soldado.h"

int soldado::getX() const
{
    return x;
}

void soldado::setX(int value)
{
    x = value;
}

int soldado::getY() const
{
    return y;
}

void soldado::setY(int value)
{
    y = value;
}

soldado::soldado(QGraphicsItem *carr):QGraphicsPixmapItem(carr)
{
    setPixmap(QPixmap(":/Images/playmove.png"));

}

QGraphicsPixmapItem *soldado::solido()
{
    QPixmap sol;
    sol.load(":/Images/bmpSolido.png");

    QGraphicsPixmapItem* pixmapItem = new QGraphicsPixmapItem(sol);
    return pixmapItem;
}



void soldado::posicion()
{
    QList<QGraphicsItem*> items = collidingItems(Qt::IntersectsItemBoundingRect);
        for (QGraphicsItem* item : qAsConst(items)) {
            if (item->data(Qt::UserRole) == 1 || item->data(Qt::UserRole) == 2) {
                // Si el objeto colisionado es un bloque 1 o 2, detén al jugador
                cout<<"colisiona"<<endl;
                setPos(previousPosition_);
            }
        }

        // Actualiza la posición anterior del jugador
        previousPosition_ = pos();
    setPos(x,y);
}

void soldado::posicion(int newX, int newY)
{
    x=newX;
    y=newY;
    setPos(x,y);
}

void soldado::advances()
{

          }

