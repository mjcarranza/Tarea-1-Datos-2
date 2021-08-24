//
// Created by Mario Carranza on 21/8/21.
//

#ifndef TAREA1DATOS_PAGEDARRAY_H
#define TAREA1DATOS_PAGEDARRAY_H

class PagedArray {
    //Attributes

    //Methods
    bool buscar(int valor, vector<int>& refMarc);

    // funcion para encontrar el marco que no ha sido usado recientemente
    // y podria utilizarse en el futuro despues del indice dado en pag[0...tamPag-1]
    int predecir(int pag[], vector<int>& refMarc, int tamPag, int indice);

    // se utiliza el metodo de paginacion Optima:
    void pagOptima(int pag[], int tamPag, int nMarc);
};

#endif //TAREA1DATOS_PAGEDARRAY_H
