#include <stdio.h>
#include <stdlib.h>
#include "double_stack.h"

int main() {
    Stack s;
    initialize(&s);
    printf("hacemos la primera verificación si esta vacio:\n");
    isEmpty1(&s);
    printf("hacemos el primer push:\n");
    push(&s, 10); //hacemos push
    display(&s);
    printf("hacemos tres push mas:\n");
    push(&s, 46);
    push(&s, 106);
    push(&s, 16);
    display(&s); // Mostrar el contenido de la pila después de los pushes
    printf("hacemos pop:");
    int poppedValue = pop(&s);
    printf("Valor eliminado: %d\n", poppedValue);
    
    printf("hacemos otra verificación si esta vacio:\n");
    isEmpty1(&s);//verificamos y mostramos si la pila esta vacia
    display(&s); // Mostrar el contenido de la pila después de un pop
    printf("El elemento en la parte superior es: %.1f\n", top(&s));// Mostrar el elemento en la parte superior de la pila sin eliminarlo
    freeStack(&s); // Liberar la memoria dinámica de la pila

    return 0;
}
