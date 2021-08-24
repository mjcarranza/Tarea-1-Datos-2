#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string.h>

using namespace std;
string texto;   // para guardar all the texto del archivo .txt

int main(){
    // leer texto en archivo .txt ----->>>
    ifstream archivo1("numbers.txt");

    ofstream archivo2("numbers.txt"); // abrir archivo de texto para escribir en el (si no existe se crea)
    int number;
    int convert;
    cout<< "Introduzca la cantidad de numeros a introducir en el texto: ";
    cin >> number;  // se pide al usuario el numero de numeros que desea en el archivo de texto
    double value;
    srand(time(NULL));
    for (int i = 0; i < number; ++i) {
        value = rand();     // generacion de numeros aleatorios  // hacer division entera para usar solo el numero entero
        convert = (int) value;
        string valueStr = to_string(convert);
        archivo2 << texto << valueStr +", "; // insertar texto en archivo txt
    }
    archivo1.close();               // cerrar archivo .txt para liberar memoria
    archivo2.close();

}

