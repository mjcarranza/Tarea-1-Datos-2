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



//int main(){
//    int pag[]={1,2,3,4,5,6}; // numero de paginas del programa // ver si se3 puede calcular este numero utilizando un contador que se incrementa cada vez que se introduce un nuevo numero al txt
//    int nMarc = 6; // este es el numero maximo de paginas que se pueden cargar a memoria
//    int tamPag = sizeof (pag) / sizeof (pag[0]); // estes es el tamanio de cada pagina
//    pagOptima(pag, tamPag, nMarc);
//    return 0;
//}
