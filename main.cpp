#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "QuickSort.h"
#include "PagedArray.h"

using namespace std;

/*
 * Metodo principal para la ejecucion del programa.
 */
int main(){
    // Variables locales para este metodo
    string linea;
    ifstream File;
    vector <string> numeros;

    // Se abre el archivo con los numeros enteros separados por coma.
    File.open( "texto.txt" , ios::in);

    // Se obtiene cada linea del archivo.
    while(getline(File,linea)){
        stringstream strstr(linea);
        string numero;

        // Se separa cada numero entero y se inserta en un vector.
        while(getline(strstr,numero, ',')){
            numeros.push_back(numero);
        }
    }

    // No es necesario.
    for (int i = 0; i < numeros.size(); ++i) {
        cout<<numeros[i]<<endl;
    }
    // Se cierra el archivo txt.
    File.close();

    //Llamada a la clase PagedArray.
}
