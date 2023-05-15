#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>

enum Direcciones { up, down, left, right, none };

class Player : public QGraphicsItem
{
public:
    QRectF CDI();
    QRectF CAA();
    explicit Player(QObject *parent = nullptr);
    QPixmap *bomber;
    QPointF posJugador;
    void set_pos(int x, int y);
    int get_posx() {
        return posJugador.x();
    }
    int get_posy() {
        return posJugador.y();
    }

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

    void set_dir(Direcciones dir) {
        this->dir = dir;
    }
    void validarmovimiento(int [17][17]);

private:
    int posx;
    int posy;
    int dx, dy;
    float imx, imy, ancho, alto;
    Direcciones dir;
    Direcciones last;
    int velo;



public slots:
    void actualizar(int [17][17]);
};

#endif // PLAYER_H
