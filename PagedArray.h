//
// Created by Mario Carranza on 21/8/21.
//

#ifndef TAREA1DATOS_PAGEDARRAY_H
#define TAREA1DATOS_PAGEDARRAY_H
#include <bits/stdc++.h>

using namespace std;

class PagedArray {
    //Attributes

    //Methods
    PagedArray()= default;
    bool buscar(int valor, vector<int>& refMarc);

    // funcion para encontrar el marco que no ha sido usado recientemente
    // y podria utilizarse en el futuro despues del indice dado en pag[0...tamPag-1]
    int predecir(int pag[], vector<int>& refMarc, int tamPag, int indice);

    // se utiliza el metodo de paginacion Optima:
    void pagOptima(int pag[], int tamPag, int nMarc);

    int parseLine(char* line);
    int getMemoryUsage();
};

#endif //TAREA1DATOS_PAGEDARRAY_H
