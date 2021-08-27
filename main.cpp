#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "PagedArray.h"

using namespace std;
PagedArray pagArr;
/*
 * Metodo principal para la ejecucion del programa.
 */
int main(){
    // Variables locales para este metodo
    string linea; // Guarda el contenido de cada linea
    ifstream File; // Hace referncia al archivo
    vector <string> numerosStr; // Vector en el que se guardan los numeros extraidos del txt en formato string
    vector <int> numerosInt; // Vector en el que se guardan los numeros extraidos del txt en formato integer
    string tempStr;
    int tempInt;

    // Se abre el archivo con los numeros enteros separados por coma.
    File.open( "texto.txt" , ios::in);                      // SE PUEDE CAMBIAR PARA QUE LEA EL QUE EL USUARIO QUIERA

    // Se obtiene cada linea del archivo.
    while(getline(File,linea)){
        stringstream strstr(linea);
        string numero;

        // Se separa cada numero entero y se inserta en un vector.
        while(getline(strstr,numero, ',')){
            numerosStr.push_back(numero);
        }
    }
    //int vec[numerosStr.size()];
    for (int i = 0; i < numerosStr.size(); ++i) {
        tempStr = numerosStr[i];
        tempInt = stoi(tempStr);
        //vec[i] = tempInt;
        numerosInt.push_back(tempInt);
    }

//    // imprimir el vector // No es necesario. //
//    for (int i = 0; i < numerosStr.size(); ++i) {
//        cout<<vec[i]<<endl;
//    }

    File.close(); // Se cierra el archivo porque ya no se va a leer

    //Llamada a la clase PagedArray.
    pagArr.fillPage(numerosInt);
}
