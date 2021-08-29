#include <iostream>
#include <list>
#include "HashTable.h"
#include "PagedArray.h" // uasr el header para cambiar paginas, etc.
#include "QuickSort.h" // usar el header para ordenar los elementos de las paginas que entran a esta clase por medio de la clase PagedArray
using namespace std;

/*
 * Funcion para buscar una pagina en especifico
 * @key numero de pagina
 */
int HashTable::search(int key) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for (; bItr!= end(cell) ; bItr++) {
        if (bItr->first == key){
            keyExists = true;
            return bItr->second;
        }
    }
}

int HashTable::hashFunction(int key) {
    return key % hashGroups;
}

/*
 * Funcion para insertar paginas a la tabla
 * @key es el numero de pagina
 * @value es el espacio en memoria donde inicia la pagina
 */
void HashTable::insert(int key, int value) {
    int hashValue = hashFunction(key);
    auto& cell = table[hashValue];
    auto bItr = begin(cell);
    bool keyExists = false;
    for (; bItr != end(cell) ; bItr++) {
        if (bItr->first == key){
            keyExists = true;
            bItr->second = value;
            cout<<"La llave introducida ya existe! Valor reemplzado!"<<endl;  // si la llave que estoy insertando es igual a otra ya existente
                                                        // esta reemplaza el viejo valor con el nuevo
            break;
        }
    }
    if (!keyExists){
        cell.emplace_back(key, value);
    }
}
