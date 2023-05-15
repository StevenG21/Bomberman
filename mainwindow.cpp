#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    generarmapa();
    ui->setupUi(this);
    scene=new QGraphicsScene(this);
    jugador = new Player;



        scene->setSceneRect(0,0,63*columnas,53*filas);
        //scene->addRect(scene->sceneRect());
        ui->graphicsView->setScene(scene);
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                 X = i * anchobloque;
                 Y = j * altobloque;
                      if(matriz[i][j]==0){
                    // Crear objeto QGraphicsPixmapItem para el bloque 0
                            QGraphicsPixmapItem* bloque0 = new QGraphicsPixmapItem(QPixmap(":/Images/bmpSuelo.png"));
                            bloque0->setPos(X, Y);

                            scene->addItem(bloque0);
                   }
                      if(matriz[i][j]==1){

                          // Crear objeto QGraphicsPixmapItem para el bloque 1
                                  QGraphicsPixmapItem* bloque1 = new QGraphicsPixmapItem(QPixmap(":/Images/bmpSolido.png"));
                                  bloque1->setPos(X, Y);
                                   bloque1->setData(Qt::UserRole, 1); // Establecer el atributo data en 1
                                  scene->addItem(bloque1);

                   }
                      if(matriz[i][j]==2){
                          // Crear objeto QGraphicsPixmapItem para el bloque 2
                                 QGraphicsPixmapItem* bloque2 = new QGraphicsPixmapItem(QPixmap(":/Images/bmpDestruible.png"));
                                 bloque2->setPos(X, Y);
                                 bloque2->setData(Qt::UserRole, 2); // Establecer el atributo data en 2

                                 scene->addItem(bloque2);

                   }
                      if(matriz[i][j]==3){
                          // Crear objeto QGraphicsPixmapItem para el bloque 3
                                 QGraphicsPixmapItem* bloque3 = new QGraphicsPixmapItem(QPixmap(":/Images/bmpSuelo.png"));
                                 bloque3->setPos(X, Y);
                                 scene->addItem(bloque3);
                                 bloque3->setData(Qt::UserRole, 3);
                   }




                    //agregar más casos para cada imagen que necesites
                }

            }
        jugador->setPos(50,15);
 scene->addItem(jugador);





}





MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_F4)
            close();

        if (event->key() == Qt::Key_A) {
            jugador->set_dir(Direcciones::left);
        } else if (event->key() == Qt::Key_S) {
            jugador->set_dir(Direcciones::down);
        } else if (event->key() == Qt::Key_D) {
            jugador->set_dir(Direcciones::right);
        } else if (event->key() == Qt::Key_W) {
            jugador->set_dir(Direcciones::up);
        } else if (event->key() == Qt::Key_M) {
            if (timer->isActive())
                timer->stop();
            else
                timer->start(500);
        }

        jugador->actualizar(matriz);




        scene->update();
}



void MainWindow::generarmapa()
{
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





void MainWindow::hmov()
{

}
