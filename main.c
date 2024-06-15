#include <stdio.h>
#include <stdlib.h>

// Definimos la estructura del nodo de la pila
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Definición de la estructura de la pila
typedef struct {
    Node* top; // Puntero al nodo superior de la pila
} Stack;

// Inicializar la pila
void initialize(Stack* s) {
    s->top = NULL;
}

//Verifica si la pila esta vacia
int isEmpty1(Stack* s) {
 return s->top == NULL;  
}


int isEmpty(Stack* s) {
    if (s->top == NULL) {
        printf("La pila está vacía.\n");
        return 1;
    } else {
        printf("La pila no está vacía.\n");
        return 0;
    }
}



// Push: agregar un valor a la pila
void push(Stack* s, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {    //comprobamos que se asigno memoria
        printf("Stack Overflow: No se puede asignar memoria.\n");
        return;
    }
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

// Pop: eliminar y devolver el valor en la parte superior de la pila
int pop(Stack* s) {
    if (isEmpty1(s)) {
        printf("Stack Underflow: La pila está vacía.\n");
        return -1;
    }
    Node* temp = s->top;
    int poppedValue = temp->data;
    s->top = s->top->next;
    free(temp);
    return poppedValue;
}

// Mostrar el contenido de la pila
void display(Stack* s) {
    if (isEmpty1(s)) {
        printf("La pila está vacía.\n");
        return;
    }
    Node* current = s->top;
    printf("Contenido de la pila:\n");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int top(Stack* s) {
    if (isEmpty1(s)) {
        printf("Stack Underflow: La pila está vacía.\n");
        return -1;
    }
    return s->top->data;
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


int main() {
    Stack s;
    initialize(&s);
    printf("hacemos la primera verificación si esta vacio:\n");
    isEmpty(&s);
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
    isEmpty(&s);//verificamos y mostramos si la pila esta vacia
    display(&s); // Mostrar el contenido de la pila después de un pop
    printf("El elemento en la parte superior es: %d\n", top(&s));// Mostrar el elemento en la parte superior de la pila sin eliminarlo
    freeStack(&s); // Liberar la memoria dinámica de la pila

    return 0;
}
