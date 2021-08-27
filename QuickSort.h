//
// Created by Mario Carranza on 23/8/21.
//

class QuickSort {
    // Atributos.
    int low;
    int high;
    int size;
    int array[]; // ver si es mejor cambiar el array por un vector

    // Constructor.
    QuickSort(int array[], int l, int h, int tam){  // ver si es mejor cambiar el array por un vector
        low = l;
        high = h;
        size = tam;
        //int arr[size] = array;

    }
    /*
     * Metodo pra intercambiar los valores de las variables low y high.
     */
    static void exchange(int *a, int *b);

    /*
     * Metodo que divide el array en partes mas pequenas.
     */
    static int division(int array[], int low, int high);  // ver si es mejor cambiar el array por un vector

    /*
     * Metodo para ordenar un array.
     */
    void sort(int array[], int low, int high);  // ver si es mejor cambiar el array por un vector

};
