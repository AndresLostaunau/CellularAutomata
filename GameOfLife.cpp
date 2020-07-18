#include<vector>
#include<iostream>
#include <fstream>
#include <random>
#include <time.h>
#include <string>
using namespace std;

class Cell{
public:
    int posX, posY;
    int value;                      //Value 0 = free, 1 = tree, 2 = fire

    Cell(int x, int y):posX(x),posY(y),value(0){}

    Cell(int x, int y, int value):posX(x),posY(y),value(value){}

    Cell(Cell* c):posX(c->posX),posY(c->posY),value(c->value){}
};


class Matrix{
public:
    vector<vector<Cell*>> matriz;
    int dimX, dimY, velocidad, poblacion_inicial, direccion;

    Matrix(int x, int y):dimX(x),dimY(y){
        for(int i = 0; i < y+8; i++){
            vector<Cell*> vecx;
            for(int j = 0; j < x+8; j++){
                vecx.push_back(new Cell(j-4,i-4));
            }
            matriz.push_back(vecx);
        }
    }


    void percentageInit(int p){
        poblacion_inicial = p;
        int n = p*dimX*dimY/100;
        int x,y;
        if(p<=50){
            for(int i = 0; i < n; i++){
                srand(time(nullptr));
                x = rand()%dimX + 4;
                y = rand()%dimY + 4;
                if(matriz[x][y]->value==0){
                    matriz[x][y]->value=1;
                }else{
                    i--;
                }
            }
        }else{
            n= dimX*dimY - n;
            for(int i = 0; i < dimY+8; i++){
                for(int j = 0; j < dimX+8; j++){
                    matriz[j][i]->value=1;
                }
            }
            for(int i = 0; i < n; i++){
                srand(time(nullptr));
                x = rand()%dimX+4;
                y = rand()%dimY+4;
                if(matriz[x][y]->value==1){
                    matriz[x][y]->value=0;
                }else{
                    i--;
                }
            }
        }
    }

    void startFire(){
        int x,y;
        bool started = false;
        while(!started){
            srand(time(nullptr));
            x = rand()%dimX + 4;
            y = rand()%dimY + 4;
            if(matriz[x][y]->value==1){
                matriz[x][y]->value=2;
                started = true;
                cout<<"Fire position: x = "<<y-4<<", y = "<<x-4<<endl;
            }
        }
    }

    void rule(vector<vector<Cell *>> prev_matriz, int y, int x){
        if(direccion == 8){
            for(int j = y-1; j < y+2; j++){
                for(int i = x-1; i < x+2; i++){
                    if(prev_matriz[j][i]->value==1){
                        matriz[j][i]->value=2;
                    }
                }
            }
        } else if(direccion==0){
            for(int j = y-1; j < y+2; j++){
                for(int i = x; i < x+2+velocidad; i++){
                    if(prev_matriz[j][i]->value==1){
                        matriz[j][i]->value=2;
                    }
                }
            }
        } else if(direccion==1){
            if(velocidad==1){
                if(matriz[y+1][x-1]->value==1)
                    matriz[y+1][x-1]->value=2;
                if(matriz[y-1][x+1]->value==1)
                    matriz[y-1][x+1]->value=2;
            }
            if(velocidad>=2){
                if(matriz[y+2][x]->value==1)
                    matriz[y+2][x]->value=2;
                if(matriz[y+2][x+1]->value==1)
                    matriz[y+2][x+1]->value=2;
                if(matriz[y+2][x+2]->value==1)
                    matriz[y+2][x+2]->value=2;
                if(matriz[y+1][x+2]->value==1)
                    matriz[y+1][x+2]->value=2;
                if(matriz[y][x+2]->value==1)
                    matriz[y][x+2]->value=2;
            }else if(velocidad==3){
                if(matriz[y+3][x]->value==1)
                    matriz[y+3][x]->value=2;
                if(matriz[y+3][x+1]->value==1)
                    matriz[y+3][x+1]->value=2;
                if(matriz[y+3][x+2]->value==1)
                    matriz[y+3][x+2]->value=2;
                if(matriz[y+3][x+3]->value==1)
                    matriz[y+3][x+3]->value=2;
                if(matriz[y+2][x+3]->value==1)
                    matriz[y+2][x+3]->value=2;
                if(matriz[y+1][x+3]->value==1)
                    matriz[y+1][x+3]->value=2;
                if(matriz[y][x+3]->value==1)
                    matriz[y][x+3]->value=2;
            }
            if(matriz[y+1][x]->value==1)
                matriz[y+1][x]->value=2;
            if(matriz[y+1][x+1]->value==1)
                matriz[y+1][x+1]->value=2;
            if(matriz[y][x+1]->value==1)
                matriz[y][x+1]->value=2;
        }else if(direccion==2){
            for(int j = y; j < y+2+velocidad; j++){
                for(int i = x-1; i < x+2; i++){
                    if(prev_matriz[j][i]->value==1){
                        matriz[j][i]->value=2;
                    }
                }
            }
        } else if(direccion==3){
            if(velocidad==1){
                if(matriz[y-1][x-1]->value==1)
                    matriz[y-1][x-1]->value=2;
                if(matriz[y+1][x+1]->value==1)
                    matriz[y+1][x+1]->value=2;
            }
            if(velocidad>=2){
                if(matriz[y+2][x]->value==1)
                    matriz[y+2][x]->value=2;
                if(matriz[y+2][x-1]->value==1)
                    matriz[y+2][x-1]->value=2;
                if(matriz[y+2][x-2]->value==1)
                    matriz[y+2][x-2]->value=2;
                if(matriz[y+1][x-2]->value==1)
                    matriz[y+1][x-2]->value=2;
                if(matriz[y][x-2]->value==1)
                    matriz[y][x-2]->value=2;
            }else if(velocidad==3){
                if(matriz[y+3][x]->value==1)
                    matriz[y+3][x]->value=2;
                if(matriz[y+3][x-1]->value==1)
                    matriz[y+3][x-1]->value=2;
                if(matriz[y+3][x-2]->value==1)
                    matriz[y+3][x-2]->value=2;
                if(matriz[y+3][x-3]->value==1)
                    matriz[y+3][x-3]->value=2;
                if(matriz[y+2][x-3]->value==1)
                    matriz[y+2][x-3]->value=2;
                if(matriz[y+1][x-3]->value==1)
                    matriz[y+1][x-3]->value=2;
                if(matriz[y][x-3]->value==1)
                    matriz[y][x-3]->value=2;
            }
            if(matriz[y+1][x]->value==1)
                matriz[y+1][x]->value=2;
            if(matriz[y+1][x-1]->value==1)
                matriz[y+1][x-1]->value=2;
            if(matriz[y][x-1]->value==1)
                matriz[y][x-1]->value=2;
        }else if(direccion==4){
            for(int j = y-1; j < y+2; j++){
                for(int i = x-1-velocidad; i < x; i++){
                    if(prev_matriz[j][i]->value==1){
                        matriz[j][i]->value=2;
                    }
                }
            }
        } else if(direccion==5){
            if(velocidad==1){
                if(matriz[y+1][x-1]->value==1)
                    matriz[y+1][x-1]->value=2;
                if(matriz[y-1][x+1]->value==1)
                    matriz[y-1][x+1]->value=2;
            }
            if(velocidad>=2){
                if(matriz[y-2][x]->value==1)
                    matriz[y-2][x]->value=2;
                if(matriz[y-2][x-1]->value==1)
                    matriz[y-2][x-1]->value=2;
                if(matriz[y-2][x-2]->value==1)
                    matriz[y-2][x-2]->value=2;
                if(matriz[y-1][x-2]->value==1)
                    matriz[y-1][x-2]->value=2;
                if(matriz[y][x-2]->value==1)
                    matriz[y][x-2]->value=2;
            }else if(velocidad==3){
                if(matriz[y-3][x]->value==1)
                    matriz[y-3][x]->value=2;
                if(matriz[y-3][x-1]->value==1)
                    matriz[y-3][x-1]->value=2;
                if(matriz[y-3][x-2]->value==1)
                    matriz[y-3][x-2]->value=2;
                if(matriz[y-3][x-3]->value==1)
                    matriz[y-3][x-3]->value=2;
                if(matriz[y-2][x-3]->value==1)
                    matriz[y-2][x-3]->value=2;
                if(matriz[y-1][x-3]->value==1)
                    matriz[y-1][x-3]->value=2;
                if(matriz[y][x-3]->value==1)
                    matriz[y][x-3]->value=2;
            }
            if(matriz[y-1][x]->value==1)
                matriz[y-1][x]->value=2;
            if(matriz[y-1][x-1]->value==1)
                matriz[y-1][x-1]->value=2;
            if(matriz[y][x-1]->value==1)
                matriz[y][x-1]->value=2;
        }else if(direccion==6){
            for(int j = y-1 - velocidad ; j < y; j++){
                for(int i = x-1; i < x+2; i++){
                    if(prev_matriz[j][i]->value==1){
                        matriz[j][i]->value=2;
                    }
                }
            }
        } else if(direccion==7){
            if(velocidad==1){
                if(matriz[y-1][x-1]->value==1)
                    matriz[y-1][x-1]->value=2;
                if(matriz[y+1][x+1]->value==1)
                    matriz[y+1][x+1]->value=2;
            }
            if(velocidad>=2){
                if(matriz[y-2][x]->value==1)
                    matriz[y-2][x]->value=2;
                if(matriz[y-2][x+1]->value==1)
                    matriz[y-2][x+1]->value=2;
                if(matriz[y-2][x+2]->value==1)
                    matriz[y-2][x+2]->value=2;
                if(matriz[y-1][x+2]->value==1)
                    matriz[y-1][x+2]->value=2;
                if(matriz[y][x+2]->value==1)
                    matriz[y][x+2]->value=2;
            }else if(velocidad==3){
                if(matriz[y-3][x]->value==1)
                    matriz[y-3][x]->value=2;
                if(matriz[y-3][x+1]->value==1)
                    matriz[y-3][x+1]->value=2;
                if(matriz[y-3][x+2]->value==1)
                    matriz[y-3][x+2]->value=2;
                if(matriz[y-3][x+3]->value==1)
                    matriz[y-3][x+3]->value=2;
                if(matriz[y-2][x+3]->value==1)
                    matriz[y-2][x+3]->value=2;
                if(matriz[y-1][x+3]->value==1)
                    matriz[y-1][x+3]->value=2;
                if(matriz[y][x+3]->value==1)
                    matriz[y][x+3]->value=2;
            }
            if(matriz[y-1][x]->value==1)
                matriz[y-1][x]->value=2;
            if(matriz[y-1][x+1]->value==1)
                matriz[y-1][x+1]->value=2;
            if(matriz[y][x+1]->value==1)
                matriz[y][x+1]->value=2;
        }
    }

    vector<vector<Cell *>> clonar(){
        vector<vector<Cell *>> prev_matriz;
        vector<Cell*> aux_matriz;
        for(int i = 0; i < dimY+8; i++ ){
            aux_matriz.clear();
            for(int j = 0; j < dimX+8;j++){
                aux_matriz.push_back(new Cell(j-4,i-4,matriz[i][j]->value));
            }
            prev_matriz.push_back(aux_matriz);
        }
        return prev_matriz;
    }

    void actulizar_loop(){
        int i = 1;
        srand(time(NULL));
        while(i < 21){
            direccion = rand()%9;
            velocidad = rand()%4;
            actualizar(i);
            i++;
        }
        firePercentage();

    }

    bool actualizar(int contador){
        auto prev_matriz=clonar();
        for(int i = 4; i < dimY+4; i++){
            for(int j = 4; j < dimX+4; j++){
                if(prev_matriz[j][i]->value==2){
                    rule(prev_matriz,j,i);
                }
            }
        }
        printer(contador);
        return !(matrix_to_string(prev_matriz)==matrix_to_string(matriz));
    }

    void firePercentage(){
        int total = 0, quemado = 0, des;
        for(int i = 4; i < dimY+4; i++){
            for(int j = 4; j < dimX+4; j++){
                if(matriz[i][j]->value==1){
                    total++;
                }else if (matriz[i][j]->value==2){
                    total++;
                    quemado++;
                }
            }
        }
        des = 100*quemado/total;
        cout<<"Porcentage de destruccion: "<<des<<"% \n";
    }

    string matrix_to_string(vector<vector<Cell *>> m){
        string out;
        for(int i = 0; i <dimY; i++){
            for(int j = 0; j<dimX;j++){
                if(m[i+4][j+4]->value==0){
                    out.append("- ");
                }else if(m[i+4][j+4]->value==1){
                    out.append("O ");
                }else if(m[i+4][j+4]->value==2){
                    out.append("X ");
                }
            }
            out.append("\n");
        }
        return out;
    }

    void printer(int n){
        cout<<"\nIteracion "<<n<<": \n";
        cout<<matrix_to_string(matriz);
        cout<<"Datos:\nDensidad poblacional: "<<poblacion_inicial<<" %\nVelocidad: "<<(velocidad+1)*6<<"km/h\nDireccion: ";
        if(direccion==9)
            cout<<"-\n";
        else
            cout<<(360 - direccion*45)%360<<" o \n\n";
    }
    
    void execute(int init){
        percentageInit(init);
        startFire();
        //printer();
        actulizar_loop();
    }
};


