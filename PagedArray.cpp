//
// Created by Mario Carranza on 21/8/21.
//

#include "PagedArray.h"

#include <bits/stdc++.h>
using namespace std;

bool PagedArray::buscar(int valor, vector<int>& refMarc){
    for (int i = 0; i < refMarc.size(); ++i) {
        if (refMarc[i] == valor) {
            return true;
        }
    }
    return false;
}

// funcion para encontrar el marco que no ha sido usado recientemente
// y podria utilizarse en el futuro despues del indice dado en pag[0...tamPag-1]
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

// se utiliza el metodo de paginacion Optima:
void PagedArray::pagOptima(int pag[], int tamPag, int nMarc){
    vector<int> refMarc;
    int aciertos = 0;
    float razonFallos = 0;
    for (int i = 0; i < tamPag; ++i) {
        if (buscar(pag[i], refMarc)){
            aciertos++;
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
    razonFallos = (float) (tamPag-aciertos)/tamPag;
    cout<<"Razon de Fallos: "<< razonFallos;
    cout<<"\n Rendimiento: "<< (1-razonFallos)*100<<"%";
}

/*
 * Asume que un digito sera encontrado y la linea termina en kb
 */
int PagedArray::parseLine(char* linea){
    int i = strlen(linea);
    const char* p = linea;
    while (*p <'0' || *p > '9') p++;
    linea[i-3] = '\0';
    i = atoi(p);
    return i;
}

/*
 * Metodo para saber la cantidad de memoria fisica utilizada por este programa en KB
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
    return resultado;
}

/*
 * Funcion para rellenar por primera vez las 6 paginas
 */
void PagedArray::fillPage(vector<int> vec) {
    numbers = vec;
    int indice = 0;
    pageAmount = numbers.size() / 256; // este numero es el que me va a decir que tan larga es la hashTable

    // Llenar las paginas con los elemntos del vector
    fill1(0);
    fill2(256);
    fill3(512);
    fill4(768);
    fill5(1024);
    fill6(1280);

    // llenar el hashTable con el numero de pagina y la direccion del espacio en memoria donde inicia
    // continuar en la pagina 4 del cuaderno (flacha encerrada con circulo rojo)
}

/*
 * Funcion para rellenar la pagina 1
 * @param ind sera la posicion en memoria donde empieza la pagina a rellenar
 */
vector<int> PagedArray::fill1(int ind) {
    int indice = ind;
    // Ciclo para llenar la pagina 1
    for (int i = 0; i < 256; ++i) {
        page1.push_back(numbers[indice]);
        indice++;
    }
    return page1;
}

vector<int> PagedArray::fill2(int ind) {
    int indice = ind;
    // Ciclo para llenar la pagina 2
    for (int i = 0; i < 256; ++i) {
        page2.push_back(numbers[indice]);
        indice++;
    }
    return page2;
}

vector<int> PagedArray::fill3(int ind) {
    int indice = ind;
    // Ciclo para llenar la pagina 3
    for (int i = 0; i < 256; ++i) {
        page3.push_back(numbers[indice]);
        indice++;
    }
    return page3;
}

vector<int> PagedArray::fill4(int ind) {
    int indice = ind;
    // Ciclo para llenar la pagina 4
    for (int i = 0; i < 256; ++i) {
        page4.push_back(numbers[indice]);
        indice++;
    }
    return page4;
}

vector<int> PagedArray::fill5(int ind) {
    int indice = ind;
    // Ciclo para llenar la pagina 5
    for (int i = 0; i < 256; ++i) {
        page5.push_back(numbers[indice]);
        indice++;
    }
    return page5;
}

vector<int> PagedArray::fill6(int ind) {
    int indice = ind;
    // Ciclo para llenar la pagina 6
    for (int i = 0; i < 256; ++i) {
        page6.push_back(numbers[indice]);
        indice++;
    }
    return page6;
}


//int main(){
//    int pag[]={1,2,3,4,5,6}; // numero de paginas del programa // ver si se3 puede calcular este numero utilizando un contador que se incrementa cada vez que se introduce un nuevo numero al txt
//    int nMarc = 6; // este es el numero maximo de paginas que se pueden cargar a memoria
//    int tamPag = sizeof (pag) / sizeof (pag[0]); // estes es el tamanio de cada pagina
//    pagOptima(pag, tamPag, nMarc);
//    return 0;
//}
