
#include <iostream>
#include <stdio.h>
using namespace std;
//Metodo que valida que todo numero ingresado sea mayor a cero 
//No saldra del bucle while hasta que sea mayor a ceroa
int mayorACero(int num) {
    if (num <= 0) {
        do {
            cout << "El numero ingresado debe ser mayor a cero: ";
            cin >> num;
        } while (num <= 0);
    }
    return num;
}

//Llena la matriz inicial con el numero de pasos 
//Si el numero de pasos es menor a filas * columas > llena con valor 0
int** llemarMatriz(int filas, int colu, int pasos)
{
    int cont = 1;
    int** array2D = 0;
    array2D = new int* [colu];
    //Corre la matriz
    for (int h = 0; h < filas; h++){
        array2D[h] = new int[colu];
        for (int w = 0; w < colu; w++){   
            //varifica que el numero de pasos no sea mayor al ingresado
            if (cont <= pasos) {
            array2D[h][w] = cont;
                        cont = cont + 1;
            }
            //Si ya es mayor lo rellena con 0 hasta salir del for
            else {
                array2D[h][w] = 0;
            }
            
        }
    }
    //Retorna la matriz
    return array2D;
}

//Crea una matriz ingresando datos desde la posicion de pasos
int** llemarMatrizAdelante(int filas, int colu, int pasos, int recorrer)
{
    int cont = 0;
    int cont2 = 1;
    int cont3 = 0;
    int** array2D = 0;
    array2D = new int* [colu];
    //Corre la matriz
    for (int h = 0; h < filas; h++) {
        array2D[h] = new int[colu];
        for (int w = 0; w < colu; w++) {
            //Llena con 0 hasta el dato que cont sea menor que  recorrer
            if (cont < recorrer) {
                array2D[h][w] = 0;
                cont = cont + 1;
            }
            else {
                //Corremos solo el numero de pasos existentes
                if(cont2 <= pasos){
                array2D[h][w] = cont2;
                cont2 = cont2 + 1;
                }
                //Se llena con 0 si el numero de pasos no termina con el final de la matriz
                else {
                    array2D[h][w] = 0;
                }
            }

        }
    }
    //If que valida si es necesario escrbir al inicio de la matriz
    if (cont2 < pasos) {
        for (int h = 0; h < filas; h++) {
            for (int w = 0; w < colu; w++) {
                    if (cont2 <= pasos) {
                        //Escribe los datos al inicio de la matriz
                        array2D[h][w] = cont2;
                        cont2 = cont2 + 1;
                    }
                }
        }
    }
    return array2D;
}

int** llemarMatrizAtras(int filas, int colu, int pasos, int recorrer)
{
    int cont = 0;
    int cont2 = 1;
    int cont3 = 0;
    int** array2D = 0;
    array2D = new int* [colu];
    //Calculo desde que numero se debe correr 
    int res = (filas * colu) - recorrer;
    //Corre la matriz
    for (int h = 0; h < filas; h++) {
        array2D[h] = new int[colu];
        for (int w = 0; w < colu; w++) {
            //llena con 0 los valores que se debe correr
            if (cont < res) {
                array2D[h][w] = 0;
                cont = cont + 1;
            }
            else {
                //Corremos solo el numero de pasos existentes
                if (cont2 <= pasos) {
                    array2D[h][w] = cont2;
                    cont2 = cont2 + 1;
                }
                //Se llena con 0 si el numero de pasos no termina con el final de la matriz
                else {
                    array2D[h][w] = 0;
                }
            }

        }
    }
    //If que valida si es necesario escrbir al inicio de la matriz
    if (cont2 < pasos) {
        for (int h = 0; h < filas; h++) {
            for (int w = 0; w < colu; w++) {
                if (cont2 <= pasos) {
                    //Escribe los datos al inicio de la matriz
                    array2D[h][w] = cont2;
                    cont2 = cont2 + 1;
                }
            }
        }
    }
    
    return array2D;
}


//Valida que el numero de pasos sea menor al numero de filas * columnas
int validarPasos(int fil, int col) {
    int pasos = 0;
    cout << " Ingrese numero de pasos: ";
    cin >> pasos;
    pasos = mayorACero(pasos);
    bool validacion = false;
    do {
        //bucle while hasta que numero ingresdo sea menor a filas * columnas
        int res = fil * col;
        if (res >= pasos) {
            validacion = true;
        }else {
            cout << "Numero de pasos icorrectos, Ingrese un numero mayor a cero y menor a: " << res << " ";
            cin >> pasos;
            pasos = mayorACero(pasos);
            validacion = false;
        }
    } while (validacion != true);

    return pasos;
}

//Imprimer la matriz
void imprimirMatriz(int** matriz, int filas, int columnas) {
    //Rrecorre la matriz
    for (int h = 0; h < filas; h++) {
        for (int w = 0; w < columnas; w++) {
            //Evita el salto de linea > hasta que pase a la siquiete fila
            printf("%i,", matriz[h][w]);
        }
        //Salto de linea
        printf("\n");
    }
}


int main(void)
{   
    cout << " Bienvenido_____ \n" << endl;
    //Creamos variables que reciben datos por consola
    int filas = 0; //Numero de filas
    int columnas = 0;  //Numero de columnas
    //Creamos una matriz con 
    int pasos = 0; //Numero de pasos | para recorrer
    int recorrer1 = 0;
    int recorrer2 = 0;
    //Pedimos ingreso de datos
    cout << " Ingrese numero de filas: ";
    cin >> filas;

    filas = mayorACero(filas);

    cout << " Ingrese numero de columnas: ";
    cin >> columnas;
    columnas = mayorACero(columnas);
    pasos = validarPasos(filas, columnas);
    
    //Creamos la matriz inicial
    int** matriz = 0;
    //Creamos una matriz ingresando el numero de columnas 
    matriz = new int* [columnas];
    //llamamos al metodo que llena la matriz con datos iniciales
    matriz = llemarMatriz(filas, columnas, pasos);
    //Imprimimos la matriz inicial
    imprimirMatriz(matriz, filas, columnas);

    //variable para selecion de opcion
    char selection;
    do {
        //Imprimimos menu
        cout << "\n************** Menu ****************" << endl;
        cout << "____________________________________" << endl;
        cout << "Configurar Parametros              1" << endl;
        cout << "Adelante                           2" << endl;
        cout << "Atras                              3" << endl;
        cout << "Salir                              4" << endl;
        cout << "____________________________________" << endl;
        cout << "Seleccione Opcion: ";
        cin >> selection;

        switch (selection) {
        case '1': 
            //Penticion nueva de datos
            cout << " Ingrese numero de filas: ";
            cin >> filas;
            filas = mayorACero(filas);
            cout << " Ingrese numero de columnas: ";
            cin >> columnas;
            columnas = mayorACero(columnas);
            pasos = validarPasos(filas, columnas);
            matriz = llemarMatriz(filas, columnas, pasos);
            imprimirMatriz(matriz, filas, columnas);
            //reiniciamos datos
            recorrer1 = 0;
            recorrer2 = 0;
            break;
        case '2':
            //Primero pedimos el numero de pasos a recorrer 
            //sumamos los pasos existentes 
            recorrer1 = validarPasos(filas, columnas) + recorrer1;
            //generamos la matriz hacia adelante con el numero de pasos existentes
            matriz = llemarMatrizAdelante(filas, columnas, pasos, recorrer1);
            //imprimimos matriz
            imprimirMatriz(matriz, filas, columnas);
            break;
        case '3':
            //Primero pedimos el numero de pasos a recorrer 
            //sumamos los pasos existentes 
            recorrer2 = validarPasos(filas, columnas) + recorrer2;
            //generamos la matriz hacia atras con el numero de pasos existentes
            matriz = llemarMatrizAtras(filas, columnas, pasos, recorrer2);
            //imprimimos matriz
            imprimirMatriz(matriz, filas, columnas);
            break;
      
        }

    } while (selection != '4');
    //Salimos en caso de que la opcion sea 4
    cout << " \n Gracias por usar nuestro sistema  \n Saliendo..... \n \n ";
    cin.ignore();
    cin.get();

    return 0;
}