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
void restar_matrices();
// void multiplicar_matrices();

//funciones de apoyo para matrices
void llenar_matriz(float*,int,int);
void mostrar_matriz(float*,int,int);
void realizar_suma_matrices(float*,float*,int,int);
void realizar_resta_matrices(float*, float*, int, int); 
void ordenar_resultado_matrices(float*, int, int);
//funciones de ordenamiento
void ordenar_mat_asc(float*,int,int);
void ordenar_mat_desc(float*,int,int);
void ordenar_mat_serp_asc(float*,int,int);
void ordenar_mat_serp_desc(float *, int, int);
void serpentina_asc(float *, int, int);
void serpentina_desc(float *, int, int);

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
    cout << "7.-Salir." << endl;
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
            do
            {
                sumar_matrices();
            } while (preguntar_repetir());
            mostrar_menu();
            break;
        case 6:
            restar_matrices();
            break;
        case 7:
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
    int row,col,cont=0;
    cout << "ingrese la cantidad de filas: ",cin >> row;
    cout << "ingrese la cantidad de columnas: ",cin >> col;
    float mat1[row*col];
    cout << "a continuacion ingrese los valores correspondientes a la primera matriz."<<endl;
    llenar_matriz(mat1,row,col);

    float mat2[row*col];
    cout << "a continuacion ingrese los valores correspondientes a la segunda matriz." << endl;
    llenar_matriz(mat2,row,col);
    realizar_suma_matrices(mat1,mat2,row,col);
        
}

void restar_matrices()
{
    cout << "----------SUMA DE MATRICES----------" << endl;
    int row, col, cont = 0;
    cout << "ingrese la cantidad de filas: ", cin >> row;
    cout << "ingrese la cantidad de columnas: ", cin >> col;
    float mat1[row * col];
    cout << "a continuacion ingrese los valores correspondientes a la primera matriz." << endl;
    llenar_matriz(mat1, row, col);

    float mat2[row * col];
    cout << "a continuacion ingrese los valores correspondientes a la segunda matriz." << endl;
    llenar_matriz(mat2, row, col);
    realizar_resta_matrices(mat1, mat2, row, col);
}

// funcionesde apoyo para matrices
//NOTA: las matrices se convierten en vectores para facilitar el paso por parametros y gestionarlas de manera mas sencilla
void llenar_matriz(float* matriz,int row,int col){
    int fila = 1;
    int columna = 1;
    for(int i=0;i<row*col;i++){
        cout << "Ingrese el valor correspondiente a la posicion ("<<fila<<","<<columna<<") de la matriz: ",cin>> matriz[i];
        if(columna%col==0){
            fila++;
            columna=1;
        }else{
            columna++;
        }
    }
    cout << "acabas de ingresar: " << endl;
    mostrar_matriz(matriz,row,col);
    cout << endl;
}

void mostrar_matriz(float* matriz,int row,int col){
    int fila=1;
    int columna=1;
    for(int i=0;i<row*col;i++){
        if(columna==1){
            cout << "[ ";
        }
        cout << matriz[i]<< " ";
        
        if(columna%col==0){
            cout << "]"<<endl;
            fila++;
            columna=1;
        }else{
            columna++;
        }
    }
}

void realizar_suma_matrices(float* mat1,float* mat2,int row,int col){
    float resultado[row*col];
    for(int i=0;i<row*col;i++){
        resultado[i] = mat1[i]+mat2[i];
    }
    ordenar_resultado_matrices(resultado,row,col);
    mostrar_matriz(resultado,row,col);
}

void realizar_resta_matrices(float* mat1,float* mat2,int row,int col){
    float resultado[row*col];
    for(int i=0;i<row*col;i++){
        resultado[i] = mat1[i]-mat2[i];
    }
    ordenar_resultado_matrices(resultado,row,col);
    mostrar_matriz(resultado,row,col);
}


void ordenar_resultado_matrices(float* matriz,int row,int col){
    int opcion;
    cout << "Como desea ordenar el resultado?"<<endl;
    cout <<"1.-De manera ascendiente."<<endl;
    cout <<"2.-De manera descendiente."<<endl;
    cout <<"3.-En serpentina de manera ascendiente."<<endl;
    cout <<"4.-En serpentina de manera descendiente."<<endl;
    cout <<"5.-No quiero ordenar el resultado."<<endl;
    cout <<"Ingrese una opcion: ",cin >> opcion;
    switch(opcion){
        case 1:
            //Ordenar de manera ascendiente
            ordenar_mat_asc(matriz,row,col);
            break;
        case 2:
            //Ordenar de manera descendiente
            ordenar_mat_desc(matriz,row,col);
            break;
        case 3:
            //Ordenar en serpentina de manera ascendiente
            ordenar_mat_serp_asc(matriz,row,col);
            break;
        case 4:
            //Ordenar en serpentina de manera ascendiente
            ordenar_mat_serp_desc(matriz,row,col);
            break;
        case 5:
            break;
        default:
            cout << "Por favor ingrese una opcion valida."<<endl<<endl;
            ordenar_resultado_matrices(matriz,row,col);
    }
}

//funciones de ordenamiento
void ordenar_mat_asc(float* matriz,int row,int col){
    int aux,tam=row*col;
    for (int i=0;i<tam;i++) {
        for (int j=0; j<tam-1;j++) {
            if (matriz[j]>matriz[j + 1]) {
                aux=matriz[j];
                matriz[j]=matriz[j + 1];
                matriz[j+1] = aux;
            }
        }
    }
}

void ordenar_mat_desc(float* matriz,int row,int col){
    int aux,tam=row*col;
    for (int i=0;i<tam;i++) {
        for (int j=0; j<tam-1;j++) {
            if (matriz[j]<matriz[j + 1]) {
                aux=matriz[j];
                matriz[j]=matriz[j + 1];
                matriz[j+1] = aux;
            }
        }
    }
}
//ALERTA   SOLO FUNCIONA PARA MATRICES 2X2 Y 3X3
void ordenar_mat_serp_asc(float* matriz,int row,int col){
    int aux,tam=row*col;
    for (int i=0;i<tam;i++) {
        for (int j=0; j<tam-1;j++) {
            if (matriz[j]>matriz[j + 1]) {
                aux=matriz[j];
                matriz[j]=matriz[j + 1];
                matriz[j+1] = aux;
            }
        }
    }
    serpentina_asc(matriz,row,col);
}
//ALERTA   SOLO FUNCIONA PARA MATRICES 2X2 Y 3X3
void ordenar_mat_serp_desc(float* matriz,int row,int col){
    int aux,tam=row*col;
    for (int i=0;i<tam;i++) {
        for (int j=0; j<tam-1;j++) {
            if (matriz[j]<matriz[j + 1]) {
                aux=matriz[j];
                matriz[j]=matriz[j + 1];
                matriz[j+1] = aux;
            }
        }
    }
    serpentina_desc(matriz,row,col);
}

void serpentina_asc(float* matriz, int row, int col){
    int fila=1,columna=1;
    float copia[row*col];
    for(int i=0;i<row*col;i++){
        copia[i]=matriz[i];
    }
    ordenar_mat_desc(copia, row, col);
    for(int i=0;i<row*col;i++){
        if(fila%2==0){
            matriz[i]=copia[i];            
        }
        if(columna%col==0){
            fila++;
            columna=1;
        }else{
            columna++;
        }
    }
}

void serpentina_desc(float* matriz, int row, int col){
    int fila=1,columna=1;
    float copia[row*col];
    for(int i=0;i<row*col;i++){
        copia[i]=matriz[i];
    }
    ordenar_mat_asc(copia, row, col);
    for(int i=0;i<row*col;i++){
        if(fila%2==0){
            matriz[i]=copia[i];            
        }
        if(columna%col==0){
            fila++;
            columna=1;
        }else{
            columna++;
        }
    }
}