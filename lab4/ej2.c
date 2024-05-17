#include <stdio.h>

// Función para encontrar el mínimo en un arreglo
int encontrarMinimo(int arreglo[], int longitud) {
    int minimo = arreglo[0]; // Inicializamos el mínimo con el primer elemento del arreglo
    
                                                        //hacemos iteraciones sobre el arreglo para buscar el mínimo
    for (int i = 1; i < longitud; i++) {
        if (arreglo[i] < minimo) {
            minimo = arreglo[i];
        }
    }
    
    return minimo;                                      // Retornamos el valor mínimo encontrado
}


int encontrarMaximo(int arreglo[], int longitud) {
    int maximo = arreglo[0];                           // Inicializamos el máximo con el primer elemento del arreglo
    for (int i = 1; i < longitud; i++) {
        if (arreglo[i] > maximo) {
            maximo = arreglo[i];
        }
    }
    return maximo;
}  


void encontrarMinMax(int *arreglo, int * minimo, int * maximo, int longitud){
*minimo = *maximo = arreglo[0];                         //inicializamos los valores de los punteros
    for (int i = 1; i < longitud; i++) {
        if (*(arreglo + i) < *minimo) {
            *minimo = *(arreglo + i);
        } else if (*(arreglo + i) > *maximo) {
            *maximo = *(arreglo + i);
        }
    }
}   



int main() {
    int arreglo[] = {21, 24, 65, 3, 56, 12, 35, 15};
    int longitud = sizeof(arreglo) / sizeof(arreglo[0]); // Calculamos la longitud del arreglo
    
                                                     // Llamamos a la función para encontrar el mínimo
    int minimo = encontrarMinimo(arreglo, longitud);
    int maximo = encontrarMaximo(arreglo, longitud);
    void encontrarMinMax(int *arreglo, int * minimo, int * maximo, int longitud);
   
                                                     // Imprimimos el mínimo encontrado
    printf("El valor minimo en el arreglo es: %d\n", minimo);
    printf("El valor máximo en el arreglo es: %d\n", maximo);
    return 0;
}
