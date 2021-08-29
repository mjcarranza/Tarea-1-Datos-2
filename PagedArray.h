#include <bits/stdc++.h>
using namespace std;

/*
 * Clase para la paginacion de la memoria
 */
class PagedArray {
    //Atributos
    static const int pageSize= 256;
private:
    vector<int> numbers;
    int pages[1536];

public:
    int pageAmount;
    //Metodos
    bool buscar(int valor, vector<int>& refMarc);

    // funcion para encontrar el marco con menor probabilidad de uso en el futuro despues del indice dado en pag[0...tamPag-1]
    int predecir(int pag[], vector<int>& refMarc, int tamPag, int indice);
    // se utiliza el metodo de paginacion Optima:
    void pagOptima(int pag[], int tamPag, int nMarc);
    void fillPage(vector<int> vec);
    int parseLine(char* line);
    int getMemoryUsage();
    int totalPages();
    void fill();

};
