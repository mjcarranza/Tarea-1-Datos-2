#include <iostream>
#include <vector>
#include "PagedArray.h"

using namespace std;
PagedArray pagArr;
/**
 * Metodo principal para la ejecucion del programa.
 * @return
 */
int main(){
    /// Variables locales para este metodo.
    string linea; /// Guarda el contenido de cada linea.
    ifstream File; /// Hace referncia al archivo.
    vector <string> numerosStr; /// Vector en el que se guardan los numeros extraidos del txt en formato string.
    vector <int> numerosInt; /// Vector en el que se guardan los numeros extraidos del txt en formato integer.
    string tempStr;
    int tempInt;

    /// Se abre el archivo que contiene los numeros enteros separados por coma.
    File.open( "texto.txt" , ios::in);

    /// Se obtiene cada linea del archivo.
    while(getline(File,linea)){
        stringstream strstr(linea);
        string numero;

        /// Se separa cada numero entero y se inserta en un vector.
        while(getline(strstr,numero, ',')){
            numerosStr.push_back(numero);
        }
    }
    /// Convertir lo leido en numeros.
    for (int i = 0; i < numerosStr.size(); ++i) {
        tempStr = numerosStr[i];
        tempInt = stoi(tempStr);
        numerosInt.push_back(tempInt);
    }
    File.close(); /// Se cierra el archivo porque ya no se va a leer.

    /// Llamada a la clase PagedArray.
    pagArr.fillPage(numerosInt);
}
