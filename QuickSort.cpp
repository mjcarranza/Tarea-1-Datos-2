//
// Created by Mario Carranza on 23/8/21.
//

#include "QuickSort.h"

/*
 * Funcion de ordenamiento:
 * @param arr[] --> Array a ordenar
 * @param low   --> Indice inicial
 * @param high  --> Indice final
 * */
void QuickSort::sort(int *array, int low, int high) {
    if (low < high)
    {
        /* pi es el indice de particion, arr[p] es ahora en el lugar correcto
           at right place */
        int divIndex = division(array, low, high);

        // Ordenar elementos separadamente antes y despues de la division.
        sort(array, low, divIndex - 1);
        sort(array, divIndex + 1, high);
    }
}

/*
 * Toma el ultimo elemeto como pivote, lo posiciona en su correcta posicion en el array
 * ordenado, y posiciona los elementos mas pequenos (mas pequenos que el pivote)
 * a la izquierda del pivote y los elementos mayores a la derecha del pivote.
 */
int QuickSort::division(int *array, int low, int high)
{
    int pivot = array[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            exchange(&array[i], &array[j]);
        }
    }
    exchange(&array[i + 1], &array[high]);
    return (i + 1);
}


/*
 * Funcion para intercambiar dos elementos del array
 */
void QuickSort::exchange(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}