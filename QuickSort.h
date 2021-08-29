class QuickSort {
private:
    // Atributos.
    int low = 0;
    int high = 255;
    int array[256*6]; // ver si es mejor cambiar el array por un vector
public:
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
    void sort(int *array, int l, int h);  // ver si es mejor cambiar el array por un vector
};
