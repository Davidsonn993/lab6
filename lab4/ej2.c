#include <stdio.h>

// Función para encontrar el mínimo en un arreglo
int encontrarMinimo(int arreglo[], int longitud) {
    int minimo = arreglo[0]; // Inicializamos el mínimo con el primer elemento del arreglo
    
    // Iteramos sobre el arreglo para encontrar el mínimo
    for (int i = 1; i < longitud; i++) {
        if (arreglo[i] < minimo) {
            minimo = arreglo[i];
        }
    }
    
    return minimo; // Retornamos el valor mínimo encontrado
}

int main() {
    int arreglo[] = {21, 24, 65, 3, 56, 12, 35, 15};
    int longitud = sizeof(arreglo) / sizeof(arreglo[0]); // Calculamos la longitud del arreglo
    
    // Llamamos a la función para encontrar el mínimo
    int minimo = encontrarMinimo(arreglo, longitud);
    
    // Imprimimos el mínimo encontrado
    printf("El valor minimo en el arreglo es: %d\n", minimo);
