#include <stdio.h>

                                                           // Función para realizar una búsqueda lineal en el arreglo
int buscadorValor(int arr[], int n, int valor) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == valor)
            return i;                                      // Se encontró el valor, retorna la posición
    }
    return -1;                                             // Valor no encontrado
}

int buscarElemento(int arr[], int n, int x) {
    int inicio = 0, fin = n - 1;
    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2;
        
                                                      // Si el elemento está en el medio
        if (arr[medio] == x)
            return medio;
        
                                                      // Si el elemento es más pequeño, buscar en la mitad izquierda
        if (arr[medio] < x)
            inicio = medio + 1;
        	                                      // Si el elemento es más grande, buscar en la mitad derecha
        else
            fin = medio - 1;
    }
                                                      // Si no se encuentra el elemento
    return -1;
}

int buscarElementoRecursivo(int arr[], int inicio, int fin, int x) {
    if (fin >= inicio) {
        int medio = inicio + (fin - inicio) / 2;

                                                              // Si el elemento está en el medio
        if (arr[medio] == x)
            return medio;

                                                              // más pequeño, buscar en la mitad izquierda
        if (arr[medio] > x)
            return buscarElementoRecursivo(arr, inicio, medio - 1, x);//llamamos a la misma funcion para buscar

                                                               // más grande, buscar en la mitad derecha
        return buscarElementoRecursivo(arr, medio + 1, fin, x);
    }
                                                               // Si no se encuentra el elemento
    return -1;
}


int main() {                                              //Funcíon primcipal


    int arr[] = {2, 4, 6, 23, 56, 79};
    int n = sizeof(arr) / sizeof(arr[0]);                 //  
    
                                                          // Valor ingresado por el usuario
    int valor;
    printf("Ingrese un valor entero: ");
    scanf("%d", &valor);
    
                                                             // Realizar búsqueda del valor
    int posicion = buscadorValor(arr, n, valor);             //ingresado por el usuario en el arreglo.....|:wq

    int indice = buscarElemento(arr, n, valor);
    int indice1 = buscarElementoRecursivo(arr, 0, n - 1, valor);
 
                                                              // Mostrar resultado.... 
    if (posicion != - 1|| indice != -1 || indice1 != -1){
        printf("El valor %d se encuentra en la posición:\n", valor);
        printf(" %d del arreglo(Búsqueda Lineal).\n", posicion);
        printf(" %d del arreglo(Búsqueda binaria).\n", indice);
        printf(" %d del arreglo(Búsqueda recursiva binaria).\n", indice1);
    } 
    else
        printf("El valor %d no se encuentra en el arreglo.\n", valor);
    
    return 0;
}
