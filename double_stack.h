#ifndef DOUBLE_STACK_H
#define DOUBLE_STACK_H

typedef struct Node {
    double data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

void initialize(Stack* s);
int isEmpty(Stack* s);
int isEmpty1(Stack* s);
void push(Stack* s, double value);
double pop(Stack* s);
double top(Stack* s);
void display(Stack* s);
void freeStack(Stack* s);

#endif // DOUBLE_STACK_H
