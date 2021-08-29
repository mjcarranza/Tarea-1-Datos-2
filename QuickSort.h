class QuickSort {
private:
    /// Atributos.
    int low = 0;
    int high = 255;
public:
    /// Metodos.
    static void exchange(int *a, int *b);
    static int division(int array[], int low, int high);
    void sort(int *array, int l, int h);
};
