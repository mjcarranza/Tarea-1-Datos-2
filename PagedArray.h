//
// Created by Mario Carranza on 21/8/21.
//

#include <bits/stdc++.h>
using namespace std;

/*
 * Clase para la paginacion de la memoria
 */
class PagedArray {
    //Atributos
private:
    vector<int> numbers;
    int pageAmount;
    // Arreglos para las paginas
    vector<int> page1;
    vector<int> page2;
    vector<int> page3;
    vector<int> page4;
    vector<int> page5;
    vector<int> page6;

public:
    //Metodos
    bool buscar(int valor, vector<int>& refMarc);

    // funcion para encontrar el marco con menor probabilidad de uso en el futuro despues del indice dado en pag[0...tamPag-1]
    int predecir(int pag[], vector<int>& refMarc, int tamPag, int indice);
    // se utiliza el metodo de paginacion Optima:
    void pagOptima(int pag[], int tamPag, int nMarc);
    void fillPage(vector<int> vec);
    int parseLine(char* line);
    int getMemoryUsage();
    vector<int> fill1(int);
    vector<int> fill2(int);
    vector<int> fill3(int);
    vector<int> fill4(int);
    vector<int> fill5(int);
    vector<int> fill6(int);

};
