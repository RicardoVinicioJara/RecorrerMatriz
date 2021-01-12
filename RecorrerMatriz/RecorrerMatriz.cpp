#include <iostream>
#include <cstdio>

using namespace std;

//Metodo para validar ingreso de un numero
//Resibe como parametro un numero
//Valida que sea mayor a cero y menor o igual a 10
//Queda en buque infinito hasta que el numero este en el rango de 1 - 100
int validar_numero(int num) {
    if (num <= 0 or num > 100) {
        do {
            if (num <= 0) {
                cout << "El numero ingresado debe ser mayor a cero: ";
            } else {
                cout << "El numero ingresado debe ser menor a 101: ";
            }
            cin >> num;
        } while (num <= 0 or num > 100);
    }
    return num;
}

//Metodo para validad que el numero de pasos no sea mayor columnas*filas
//Pidel el ingreso de un numero
//Resibe como parametro numero de filas, columnas
//Valida que sea mayor a cero y menor a filas*columnas
//Queda en buque infinito hasta que el numero este en el rango de 0 - filas*columnas
int validar_pasos(int fil, int col) {
    int pasos = 0;
    cout << " Ingrese numero de pasos: ";
    cin >> pasos;
    if (pasos <= 0 or pasos > fil * col) {
        do {
            if (pasos <= 0) {
                cout << "El numero de pasos debe ser mayor a cero: ";
            } else {
                cout << "El numero de pasos debe ser menor a: " << fil * col << " ";
            }

            cin >> pasos;
        } while (pasos <= 0 or pasos > fil * col);
    }
    return pasos;
}

//Rrecorre la matriz
//Para recorrer se necesita saber el numero de filas y columnas
//Escibre en pantalla la matriz
//Con %i el salto de linea > hasta que pase a la siquiete fila
void imprimir_matriz(int **matriz, int filas, int columnas) {
    printf("\n \n");
    for (int h = 0; h < filas; h++) {
        for (int w = 0; w < columnas; w++) {
            printf("%i,", matriz[h][w]);
        }
        printf("\n");
    }
    printf("\n");
}

//Llena la matriz inicial con el numero de pasos en tamaño a filas y columnas
//Si el numero de pasos es menor a filas * columas
// Si la matriz tiene menos pasos que filas * columnas se llena con 0
//Imprime la matriz
void matriz_inicial(int filas, int colu, int pasos) {
    int cont = 1;
    int **matriz = new int *[colu];
    for (int h = 0; h < filas; h++) {
        matriz[h] = new int[colu];
        for (int w = 0; w < colu; w++) {
            //varifica que el numero de pasos no sea mayor al ingresado
            // Si ya es mayor lo rellena con 0 hasta salir del for
            if (cont <= pasos) {
                matriz[h][w] = cont;
                cont = cont + 1;
            } else {
                matriz[h][w] = 0;
            }
        }
    }
    imprimir_matriz(matriz, filas, colu);
}

//Se crea una nueva matriz inicial con el numero de pasos en tamaño a filas y columnas
//Se llena con 0 hasta el dato que cont sea menor que  recorrer
//Se llena los numeros de pasos hasta que sea el numero a recorrer
//Si cont2 pasa el numero de pasos se llena con ceros
void matriz_adelante(int filas, int colu, int pasos, int recorrer) {
    int cont = 0;
    int cont2 = 1;
    int **matriz = new int *[colu];
    for (int h = 0; h < filas; h++) {
        matriz[h] = new int[colu];
        for (int w = 0; w < colu; w++) {
            //Vereficamos hasta que datos debemos iniciar con cero
            if (cont < recorrer) {
                matriz[h][w] = 0;
                cont = cont + 1;
            } else {
                //Ingresmos los numeros de pasos
                if (cont2 <= pasos) {
                    matriz[h][w] = cont2;
                    cont2 = cont2 + 1;
                } else {//si se pasa cont2 del numero de pasos se llena con cero
                    matriz[h][w] = 0;
                }
            }

        }
    }//En caso de que cont2 sea siendo menor que numero de pasos,
    // quiere decir que es necesario escribir al inicio los numeos
    if (cont2 < pasos) {
        for (int h = 0; h < filas; h++) {
            for (int w = 0; w < colu; w++) {
                if (cont2 <= pasos) {
                    matriz[h][w] = cont2;
                    cont2 = cont2 + 1;
                }
            }
        }
    }
    imprimir_matriz(matriz, filas, colu);
}

//Se crea una nueva matriz inicial con el numero de pasos en tamaño a filas y columnas
//Calculo desde que numero se debe correr **
//Se llena con 0 hasta cont sea menor a res
//Se llena los numeros de pasos hasta que sea el numero a recorrer
//Si cont2 pasa el numero de pasos se llena con ceros
void matriz_atras(int filas, int colu, int pasos, int recorrer) {
    int cont = 0;
    int cont2 = 1;
    int **matriz = new int *[colu];
    int res = (filas * colu) - recorrer; //**
    for (int h = 0; h < filas; h++) {
        matriz[h] = new int[colu];
        for (int w = 0; w < colu; w++) {
            //llenamos con cero hasta  ** sea menor
            if (cont < res) {
                matriz[h][w] = 0;
                cont = cont + 1;
            } else {//llenamos con el numero de pasos
                if (cont2 <= pasos) {
                    matriz[h][w] = cont2;
                    cont2 = cont2 + 1;
                } else {//Si se termina los pasos antes de acabar de recorrer la matriz se llena con cero
                    matriz[h][w] = 0;
                }
            }
        }
    }
    //En caso de que cont2 sea siendo menor que numero de pasos,
    // quiere decir que es necesario escribir al inicio los numeo
    if (cont2 < pasos) {
        for (int h = 0; h < filas; h++) {
            for (int w = 0; w < colu; w++) {
                if (cont2 <= pasos) {
                    matriz[h][w] = cont2;
                    cont2 = cont2 + 1;
                }
            }
        }
    }
    imprimir_matriz(matriz, filas, colu);
}


int main(void) {
    //Variables Iniciales
    int filas = 0;
    int columnas = 0;
    int pasos = 0;
    int recorrer_adelante = 0; //Variable que incrementa segun recorre la matriz
    int recorrer_atras = 0;

    cout << " Bienvenido_____ \n" << endl;
    cout << " IVAN ARIEL BACULIMA MONTESDEOCA \n" << endl;

    //Pedimo Ingreso de datos
    cout << " Ingrese numero de filas: ";
    cin >> filas;
    filas = validar_numero(filas);

    cout << " Ingrese numero de columnas: ";
    cin >> columnas;
    columnas = validar_numero(columnas);

    pasos = validar_pasos(filas, columnas);


    //Llenamos la matriz inicial
    matriz_inicial(filas, columnas, pasos);

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
                filas = validar_numero(filas);
                cout << " Ingrese numero de columnas: ";
                cin >> columnas;
                columnas = validar_numero(columnas);
                pasos = validar_pasos(filas, columnas);
                matriz_inicial(filas, columnas, pasos);
                //reiniciamos datos
                recorrer_adelante = 0;
                recorrer_atras = 0;
                break;
            case '2':
                //Primero pedimos el numero de pasos a recorrer
                //sumamos los pasos existentes
                recorrer_adelante = validar_pasos(filas, columnas) + recorrer_adelante;
                //generamos la matriz hacia adelante con el numero de pasos existentes
                matriz_adelante(filas, columnas, pasos, recorrer_adelante);
                break;
            case '3':
                //Primero pedimos el numero de pasos a recorrer
                //sumamos los pasos existentes
                recorrer_atras = validar_pasos(filas, columnas) + recorrer_atras;
                //generamos la matriz hacia atras con el numero de pasos existentes
                matriz_atras(filas, columnas, pasos, recorrer_atras);
                break;
        }

    } while (selection != '4');
    //Salimos en caso de que la opcion sea 4
    cout << " \n Gracias por usar mi sistema en c++ \n HASTA PRONTO..... \n \n ";
    cin.ignore();
    cin.get();

    return 0;
}