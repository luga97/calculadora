#include <iostream>
#include <string.h>
using namespace std;

//funciones principales del programa
void mostrar_menu();
bool preguntar_repetir();

//funciones principales de vectores
void sumar_vectores();
void restar_vectores();
void multiplicar_vectores();
void vectorXescalar();

//para ordenar los vectores
void ordenar_resultado_vect(float *, int tam);
void ordenar_vector_asc(float*,int tam);
void ordenar_vector_desc(float*,int tam);

//funciones de apoyo para vectores
void llenar_vector(float*,int);
void mostrar_vector(float*, int);
void realizar_suma_vectorial(float*, float*,int);
void realizar_resta_vectorial(float*, float*, int);
void realizar_multiplicacion_vectorial(float*, float*, int);
void multiplicar_escalar_vector(float*, float, int);

//funciones principales de matrices
void sumar_matrices();
// void restar_matrices();
// void multiplicar_matrices();

//funciones de apoyo para matrices
void llenar_matriz(float,int,int);
void mostrar_matriz(float,int,int);


int main(){
    mostrar_menu();
}


void mostrar_menu(){
    int opcion;
    cout << "----------MENU----------" << endl;
    cout << "1.-Sumar vectores."<<endl;
    cout << "2.-Restar vectores." << endl;
    cout << "3.-Multiplicar vectores." << endl;
    cout << "4.-Multiplicar vector por escalar." << endl;
    cout << "5.-Suma de matrices."<<endl;
    cout << "6.-Resta de matrices." << endl;
    cout << "7.-Multiplicacion de matrices." << endl;
    cout << "8.-Salir." << endl;
    cout << "Ingrese una opcion: ",cin >> opcion;
    switch(opcion){
        case 1:
            do{
                sumar_vectores();
            }while(preguntar_repetir());
            mostrar_menu();
            break;
        case 2:
            do{
                restar_vectores();
            }while(preguntar_repetir());
            mostrar_menu();
            break;
        case 3:
            do{
                multiplicar_vectores();
            }while (preguntar_repetir());
            mostrar_menu();
            break;

        case 4:
            do{
                vectorXescalar();
            } while (preguntar_repetir());
            mostrar_menu();
            break;
        case 5:
            sumar_matrices();
            break;
        case 6:
            //restar_matrices();
            break;
        case 7:
            //multiplicar_matrices();
            break;
        case 8:
            break;
        default:
            cout << "Por favor ingrese una opcion valida."<<endl;
            mostrar_menu();
            break;
    }
}

bool preguntar_repetir(){
    char opcion;
    cout << "Desea realizar este procedimiento nuevamente? (S/N)"<<endl,cin>>opcion;
    opcion = toupper(opcion);
    while(opcion!='S' && opcion!='N'){
        cout << "Por favor ingrese una opcion valida (S/N): ",cin >> opcion;
        opcion = toupper(opcion);
    }
    if(opcion=='S'){
        return true;
    }else{
        return false;
    }
}

//funciones principales de vectores
void sumar_vectores(){
    cout << "----------SUMA DE VECTORES----------" << endl;
    int tam;
    cout << "ingrese el tamano de los vectores: ",cin >> tam;
    float vect1[tam];
    cout << "a continuacion ingrese los valores correspondientes al primer vector."<<endl;
    llenar_vector(vect1, tam);
    float vect2[tam];
    cout << "a continuacion ingrese los valores correspondientes al segundo vector." << endl;
    llenar_vector(vect2, tam);
    realizar_suma_vectorial(vect1,vect2,tam);
}

void restar_vectores(){
    cout << "----------RESTA DE VECTORES----------" << endl;
    int tam;
    cout << "ingrese el tamano de los vectores: ", cin >> tam;
    float vect1[tam];
    cout << "a continuacion ingrese los valores correspondientes al primer vector." << endl;
    llenar_vector(vect1, tam);
    float vect2[tam];
    cout << "a continuacion ingrese los valores correspondientes al segundo vector." << endl;
    llenar_vector(vect2, tam);
    realizar_resta_vectorial(vect1, vect2, tam);
}

void multiplicar_vectores(){
    cout << "----------MULTIPLICACION DE VECTORES----------" << endl;
    int tam;
    cout << "ingrese el tamano de los vectores: ", cin >> tam;
    float vect1[tam];
    cout << "a continuacion ingrese los valores correspondientes al primer vector." << endl;
    llenar_vector(vect1, tam);
    float vect2[tam];
    cout << "a continuacion ingrese los valores correspondientes al segundo vector." << endl;
    llenar_vector(vect2, tam);
    realizar_multiplicacion_vectorial(vect1, vect2, tam);
}

void vectorXescalar(){
    cout << "----------MULTIPLICAR VECTOR POR ESCALAR----------" << endl;
    int tam;
    cout << "ingrese el tamano del vector: ", cin >> tam;
    float escalar,vector[tam];
    cout << "ingrese el valor del escalar: ", cin>>escalar;
    llenar_vector(vector, tam);
    multiplicar_escalar_vector(vector,escalar, tam);
}

//funciones de apoyo para vectores
void llenar_vector(float* vector,int tam){
    for(int i=0;i<tam;i++){
        cout << "ingrese el valor numero "<<(i+1)<<" del vector: ",cin>>vector[i];
    }
    cout << "acabas de ingresar: " << endl;
    mostrar_vector(vector, tam);
    cout << endl;
}

void mostrar_vector(float* vector,int tam){
    cout << "{ ";
    for(int i=0;i<tam;i++){
        cout << vector[i] << " ";
    }
    cout << "}";
}

void ordenar_resultado_vect(float* vector,int tam){
    int opcion;
    cout << "Como desea ordenar el resultado?"<<endl;
    cout << "1.-De manera ascendiente."<<endl;
    cout << "2.-De manera descendiente."<<endl;
    cout << "3.-No quiero ordenarlo"<<endl;
    cout << "Por favor ingrese una opcion: ",cin>>opcion;
    switch(opcion){
        case 1:
            ordenar_vector_asc(vector,tam);
            break;
        case 2:
            ordenar_vector_desc(vector,tam);
            break;
        case 3:
            break;
        default:
            cout << "Por favor ingrese una opcion valida." << endl;
            ordenar_resultado_vect(vector,tam);
            break;
    }
}


void ordenar_vector_asc(float* vector,int tam){
    int aux;
    for (int i=0;i<tam;i++) {
        for (int j=0; j<tam-1;j++) {
            if (vector[j]>vector[j + 1]) {
                aux=vector[j];
                vector[j]=vector[j + 1];
                vector[j+1] = aux;
            }
        }
    }
}

void ordenar_vector_desc(float* vector,int tam){
    int aux;
    for (int i=0;i<tam;i++) {
        for (int j=0; j<tam-1;j++) {
            if (vector[j]<vector[j + 1]) {
                aux=vector[j];
                vector[j]=vector[j + 1];
                vector[j+1] = aux;
            }
        }
    }
}


void realizar_suma_vectorial(float *vect1, float *vect2,int tam){
    float resultado[tam];
    for(int i=0;i<tam;i++){
        resultado[i] = vect1[i]+vect2[i];
    }
    ordenar_resultado_vect(resultado,tam);
    mostrar_vector(vect1,tam);
    cout <<" + ";
    mostrar_vector(vect2,tam);
    cout << " = ";
    mostrar_vector(resultado, tam);
    cout<<endl;
}

void realizar_resta_vectorial(float *vect1, float *vect2, int tam)
{
    float resultado[tam];
    for (int i = 0; i < tam; i++)
    {
        resultado[i] = vect1[i] - vect2[i];
    }
    ordenar_resultado_vect(resultado,tam);
    mostrar_vector(vect1, tam);
    cout << " - ";
    mostrar_vector(vect2, tam);
    cout << " = ";
    mostrar_vector(resultado, tam);
    cout << endl;
}

void realizar_multiplicacion_vectorial(float *vect1, float *vect2, int tam){
    float resultado[tam];
    for (int i = 0; i < tam; i++)
    {
        resultado[i] = vect1[i] * vect2[i];
    }
    ordenar_resultado_vect(resultado,tam);
    mostrar_vector(vect1, tam);
    cout << " * ";
    mostrar_vector(vect2, tam);
    cout << " = ";
    mostrar_vector(resultado, tam);
    cout << endl;
}

void multiplicar_escalar_vector(float* vector,float escalar, int tam){
    float resultado[tam];
    
    for (int i = 0; i < tam; i++){
        resultado[i] = escalar * vector[i];
    }
    ordenar_resultado_vect(resultado, tam);

    cout << escalar << " * ";
    mostrar_vector(vector, tam);
    cout << " = ";
    mostrar_vector(resultado, tam);
    cout << endl;
}


//funciones principales de matrices

void sumar_matrices(){
    cout << "----------SUMA DE MATRICES----------" << endl;
    int row,col;
    cout << "ingrese la cantidad de filas: ",cin >> row;
    cout << "ingrese la cantidad de columnas: ",cin >> col;
    float matriz1[row][col];
    cout << "a continuacion ingrese los valores correspondientes a la primera matriz."<<endl;
    
    //TODO llenar_matriz();
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout << "Ingrese el valor correspondiente a la posicion ("<<(i+1)<<","<<(j+1)<<") de la matriz: ",cin>> matriz1[i][j];
        }
    }
    cout << "acabas de ingresar: " << endl;

    //TODO funcion mostrar_matriz()
    for(int i=0;i<row;i++){
        cout << "[ ";
        for(int j=0;j<col;j++){
            cout << matriz1[i][j] << " ";
        }
        cout << "]"<<endl;
    }
    cout << endl;
    //finaliza llenar matriz.

    float matriz2[row][col];
    cout << "a continuacion ingrese los valores correspondientes a la segunda matriz." << endl;

    //TODO pasar a funcion llenar_matriz();
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout << "Ingrese el valor correspondiente a la posicion ("<<(i+1)<<","<<(j+1)<<") de la matriz: ",cin>> matriz2[i][j];
        }
    }
    cout << "acabas de ingresar: " << endl;
    
    //TODO funcion mostrar_matriz()
    for(int i=0;i<row;i++){
        cout << "[ ";
        for(int j=0;j<col;j++){
            cout << matriz2[i][j] << " ";
        }
        cout << "]"<<endl;
    }
    cout << endl;
    //finaliza llenar matriz.

    //finaliza funcion llenar matriz.

    //TODO funcion realizar_suma_matrices
    float resultado[row][col],aux;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
           resultado[i][j]=matriz1[i][j]+matriz2[i][j];
        }
    }

    //TODO ordenar_matriz
    int opcion;
    cout << "Como desea ordenar el resultado?"<<endl;
    cout <<"1.-De manera ascendiente."<<endl;
    cout <<"2.-De manera descendiente."<<endl;
    cout <<"3.-No quiero ordenar el resultado."<<endl;
    cout <<"Ingrese una opcion: ",cin >> opcion;
    
    switch(opcion){
        case 1:
            //Ordenar de manecera ascendiente
            for(int i=0;i<row;i++){
                cout<<"fila fija "<<(i+1)<<endl;
                for(int j=0;j<col;j++){
                    cout<<"columna fija "<<(j+1)<<endl;
                    for(int x=0;x<row;x++){
                        cout<<"fila dinamica "<<(x+1)<<endl;
                        for(int y=0;y<col;y++){
                            cout<<"columna dinamica "<<(y+1)<<endl;
                            cout<<"el valor fijo es "<<resultado[i][j]<<" y el valor dinamico es "<<resultado[x][y]<<endl;
                            if(resultado[x][y]<resultado[i][j]){
                                cout<<"entro al if"<<endl;
                                aux = resultado[x][y];
                                resultado[x][y] = resultado[i][j];
                                resultado[i][j] = aux;
                            }
                        }
                    }
                }
            }
            break;
    }



    //TODO funcion mostrar_matriz
    cout << "resultado: " << endl;
        for(int i=0;i<row;i++){
        cout << "[ ";
        for(int j=0;j<col;j++){
            cout << resultado[i][j] << " ";
        }
        cout << "]"<<endl;
    }
    //finaliza mostrar_matriz
    //finaliza realizar_suma_matrices
        
}

//funcionesde apoyo para matrices

/*void llenar_matriz(float** matriz,int row,int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout << "Ingrese el valor correspondiente a la posicion ("<<(i+1)<<","<<(j+1)<<") de la matriz: ",cin>> matriz[i][j];
        }
    }
    cout << "acabas de ingresar: " << endl;
    mostrar_matriz(matriz,row,col);
    cout << endl;
}*/

/*void mostrar_matriz(float** matriz,int row,int col){
    for(int i=0;i<row;i++){
        cout << "[ ";
        for(int j=0;j<col;j++){
            cout << matriz[i][j] << " ";
        }
        cout << "]";
    }
}*/