#include <bits/stdc++.h>
using namespace std;

/**
 * Clase para la paginación de la memoria.
 */
class PagedArray {
    ///Atributos.
private:
    vector<int> numbers;
    int tamPag;
    int low =0;
    int high = (256*6)-1;
    int pages[1536];

public:
    int pageAmount;
    /// Métodos.
    bool buscar(int valor, vector<int>& refMarc);
    int predecir(int pag[], vector<int>& refMarc, int tamPag, int indice);
    void pagOptima(int pag[], int tamPag, int nMarc);
    void fillPage(vector<int> vec);
    void replace(int arr[]);
    void write();
    int parseLine(char* line);
    int getMemoryUsage();
    void fill();

};
