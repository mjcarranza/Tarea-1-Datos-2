#include "PagedArray.h"
#include "QuickSort.h"
#include "HashTable.h"
#include <bits/stdc++.h>
#include <tuple>
#include <iostream>
using namespace std;
HashTable ht;
QuickSort qst;

/**
 * Método para buscar una página en específico dentro del array completo.
 * @param valor Valor dentro del array segun el indice de la funcion pagOptima().
 * @param refMarc
 * @return
 */
bool PagedArray::buscar(int valor, vector<int>& refMarc){
    for (int i = 0; i < refMarc.size(); ++i) {
        if (refMarc[i] == valor) {
            return true;
        }
    }
    return false;
}
/**
 * Funcion para predecir cual de las paginas sera la menos utilizada en el futuro.
 * @param pag Arreglo que contiene 6 paginas.
 * @param refMarc Vector.
 * @param tamPag Tamanio de las paginas.
 * @param indice
 * @return
 */
int PagedArray::predecir(int pag[], vector<int>& refMarc, int tamPag, int indice){
    int res = -1, comp = indice;
    for (int i = 0; i < refMarc.size(); ++i) {
        int j;
        for (int j = indice; j < tamPag; ++j) {
            if (refMarc[i] == pag[j]) {
                if (j > comp) {
                    comp = j;
                    res = i;
                }
                break;
            }
        }
        if(j == tamPag){
            return i;
        }
    }
    return (res == -1) ? 0 : res;
}
/**
 * Metodo de paginacion para el cambio de paginas
 * @param pag Arreglo previamente ordenado en la clase QickSort
 * @param tamPag Tamanio de cada pagina del arreglo
 * @param nMarc numero de paginas totales
 */
void PagedArray::pagOptima(int pag[], int tamPag, int nMarc){
    vector<int> refMarc;
    for (int i = 0; i < tamPag; ++i) {
        if (buscar(pag[i], refMarc)){
            continue;
        }
        if (refMarc.size() < nMarc){
            refMarc.push_back(pag[i]);
        }
        else{
            int j = predecir(pag, refMarc, tamPag, i+1);
            refMarc[j] = pag[i];
        }
    }
}
/**
 * Asume que un digito sera encontrado y la linea termina en kb.
 * @param linea
 * @return
 */
int PagedArray::parseLine(char* linea){
    int i = strlen(linea);
    const char* p = linea;
    while (*p <'0' || *p > '9') p++;
    linea[i-3] = '\0';
    i = atoi(p);
    return i;
}
/**
 * Metodo para saber la cantidad de memoria fisica utilizada por este programa en KB.
 * @return Retorna el valor de memoria utilizado por el programa.
 */
int PagedArray::getMemoryUsage(){
    FILE* archivo = fopen("/proc/self/status", "r");
    int resultado = -1;
    char linea[128];

    while (fgets(linea, 128, archivo) != NULL){
        if (strncmp(linea, "VmSize:", 7) == 0){
            resultado = parseLine(linea);
            break;
        }
    }
    fclose(archivo);
    cout<<resultado<<endl;
    return resultado;
}
/**
 * Funcion para rellenar por primera vez las 6 paginas.
 * @param vec Vector con los valores leidos del txt.
 */
void PagedArray::fillPage(vector<int> vec) {
    tamPag=256;
    int l = 0;
    int h = 256;
    numbers = vec;
    pageAmount = numbers.size() / 256; /// este numero es el que me va a decir que tan larga es la hashTable.
    int pageCont=0;
    int pgsize = 256;

    /// Llenar un array de 6 paginas con los elemntos del vector.
    fill();

    /// llenar el hashTable con el numero de pagina y la direccion del espacio en memoria donde inicia.
    for (int i = 1; i < pageAmount+1; ++i) {
        ht.insert(i, pageCont * pgsize);
        pageCont++;
    }
    /// se obtiene la cantidad de memoria utilizada ()debe ser menor que 12 kB.
    getMemoryUsage();
    /// Ordenar el array.
    qst.sort(pages,low,high);
    /// enviar el array obtenido del sort al metodo de pagina optima // hacer que pagina optima utilice el array completo, e intercambie.
    replace(pages);
    /// verificar que el arreglo de numero este completamente ordenado antes de terminar
    if (numbers[l]>numbers[h]){
        fillPage(numbers);
    }
    write();

}
/**
 * Funcion para rellenar la pagina 1.
 */
void PagedArray::fill() {
    /// Ciclo para llenar el array de 6 paginas.
    for (int i = 0; i < 256*6; ++i) {
        pages[i] = numbers[i];
    }
}
/**
 * Funcion para reemplazar los valores ordenados de las paginas.
 * @param arr Arreglo de paginas.
 * @param low Indice donde inicia el arreglo de paginas dentro del arreglo principal
 */
void PagedArray::replace(int *arr) {
    int l=low;
    for (int i = 0; i < sizeof(arr)/4; ++i) {
        numbers[l]=arr[i];
        l++;
    }
    for (int i = 0; i < sizeof(arr)/4; ++i) {
        arr[i]=numbers[high];
        high++;
    }
    low=high;
}
/**
 * Metodo para guardar el resultado del algoritmo en un archivo txt.
 */
void PagedArray::write() {
    vector<string> output;
    string tempStr;
    int tempInt;
    ofstream outfile;

    outfile.open("archivo_resultado.txt", ios::out);
    /// Convertir los numeros del vector en string.
    for (int i = 0; i < numbers.size(); ++i) {
        tempInt = numbers[i];
        tempStr = to_string(tempInt);
        outfile<<tempStr<<",";
    }


}
