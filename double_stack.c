#include <stdio.h>
#include <stdlib.h>
#include "double_stack.h"

// Inicializar la pila
void initialize(Stack* s) {
    s->top = NULL;
}

// Verificar si la pila está vacía y mostrar un mensaje en pantalla
int isEmpty(Stack* s) {
     return s->top == NULL;
}

// Push: agregar un valor a la pila
void push(Stack* s, double value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Stack Overflow: No se puede asignar memoria.\n");
        return;
    }
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

// Eliminar y devolver el valor en la parte superior de la pila
double pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow: La pila está vacía.\n");
        return -1.0; // aqui se utiliza un valor específico para indicar error
    }
    Node* temp = s->top;
    double poppedValue = temp->data;
    s->top = s->top->next;
    free(temp);
    return poppedValue;
}

// Devolver el valor en la parte superior de la pila sin eliminarlo
double top(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack Underflow: La pila está vacía.\n");
        return -1.0; // Usar un valor específico para indicar error
    }
    return s->top->data;
}

// Mostrar el contenido de la pila
void display(Stack* s) {
    if (isEmpty(s)) {
        return;
    }
    Node* current = s->top;
    printf("Contenido de la pila:\n");
    while (current != NULL) {
        printf("%.1f ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Liberar la memoria dinámica de la pila
void freeStack(Stack* s) {
    Node* current = s->top;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    s->top = NULL;
}

// MOstrar si la pila esta vacia o no
int isEmpty1(Stack* s) {
    if (s->top == NULL) {
        printf("La pila está vacía.\n");
        return 1;
    } else {
        printf("La pila no está vacía.\n");
        return 0;
    }
}


