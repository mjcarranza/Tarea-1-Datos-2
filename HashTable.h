#include <list>
#include <iostream>
#include "PagedArray.h"
using namespace std;

/**
 * Clase para el manejo de las paginas de memoria
 */
class HashTable{
private:
    PagedArray pgArr;  /// esta declaricion es para inet5entar ver si puedo traer la cantidad de paginas que necesito
    static const int hashGroups = 10000; // delimitar esta variable con el valor de la cantidad de paginas
    /// Creacion de la tabla

public:
    list<pair<int , long>> table[hashGroups];
    /// Metodos
    int hashFunction(int key);
    void insert(int key, int value);
    int search(int key);
};
