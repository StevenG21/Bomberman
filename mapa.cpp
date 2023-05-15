#include "mapa.h"


mapa::mapa(QObject *parent) : QObject(parent)
{

    filas = 15;
    columnas = 15;
    for(int m=0;m<3;m++){
    bloques[m] = new QPixmap();
    bloques[m]->load(rutas[m]);
    }

    generarmatriz();





    // Dimensiones del sprite
    ancho =63;
    alto=53;


 //   connect(timer,&QTimer::timeout,this,&sprite::refresh);

}



QRectF mapa::boundingRect() const
{
   return QRectF(0,0,ancho,alto);//retorna un rectangulo
}

void mapa::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    for(int i=0; i<filas; i++){
        for(int j=0; j<columnas; j++){
            int x = i*ancho;
            int y = j*alto;
            switch(matriz[i][j]){
                case 0:

                    painter->drawPixmap(x, y, *bloques[1]);
                    break;
                case 1:
                    painter->drawPixmap(x, y, *bloques[0]);
                    break;
                case 2:
                    painter->drawPixmap(x, y, *bloques[2]);
                    break;
                case 3:
                    painter->drawPixmap(x, y, *bloques[1]);
                    break;


                //agregar más casos para cada imagen que necesites
            }
        }
    }
}



//void escenario::refresh()//Animacion
//{



//    columnas +=64;
//    if(columnas >=384){
//        columnas=0;
//    }
//    this->update(-ancho/2,-alto/2,ancho,alto);

//}
void mapa::generarmatriz(){
    {
            srand(time(NULL));
            matriz = new int *[filas];
            for (int i=0; i<filas;i++){
                matriz[i]= new int[columnas];
            }

            for(int i=0; i<filas;i++){
                for(int j=0;j<columnas;j++){
                    if(i==0 || j==0 || i==filas-1 || j==columnas-1){
                        matriz[i][j]=1;
                        cout << matriz[i][j] <<" ";
                    }
                    else if(i%2 == 0 && j%2==0){
                        matriz[i][j]=1;
                        cout << matriz[i][j] <<" ";
                    }
                    else if((i==1 && (j==1||j==2))||(j==1 && i==2)||(i==filas-2 && (j==columnas-3 || j==columnas-2)) || (i==filas-3 && j== columnas-2)){
                        matriz[i][j]=0;
                        cout << matriz[i][j] <<" ";//Inicio del jugador
                    }
                    else{
                        matriz[i][j]=rand()%2+2;
                        cout << matriz[i][j] <<" ";//aleatorio entre destruibles y libres 2;3
                    }
                }
                cout <<endl;
            }

        }
}


