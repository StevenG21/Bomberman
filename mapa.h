#ifndef MAPA_H
#define MAPA_H

#include <QGraphicsItem>
#include <QObject>
#include <QTimer>
#include <ctime>
#include <QPixmap>
#include <QPainter>
#include <QRectF>
#include <QKeyEvent>
#include <iostream>
using namespace std;
class mapa : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit mapa(QObject *parent = nullptr);

    QPixmap *bloques[3];
    QString rutas[3] = {":/Images/bmpSolido.png", ":/Images/bmpSuelo.png", ":/Images/bmpDestruible.png"};


    int filas,columnas;
    void dir(int);
    float ancho;
    float alto;
    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);



    void generarmatriz();
private:
int velocidad=0;
int **matriz;

signals:

public slots:



};

#endif // MAPA_H
