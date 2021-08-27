//
// Created by Mario Carranza on 26/8/21.
//

#include <list>
#include <iostream>
using namespace std;

class HashTable{
private:
    static const int hashGroups = 10; // delimitar esta variable con el valor de la cantidad de paginas
    // Creacion de la tabla
    list<pair<int , int>> table[hashGroups];
public:
    // Metodos
    HashTable();
    bool isEmpty() const;
    int hashFunction(int key);
    void insert(int key, int value);
    int search(int key);
    //void printTab();
};
