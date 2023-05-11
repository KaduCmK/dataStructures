#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct Node {
    int valor;
    struct Node *proximo;
} Node;

typedef struct Lista {
    Node *inicio;
    Node *fim;
    int tamanho;
} Lista;

Lista * linkedList(void);
Node * newNode(int);
void display(Lista*);

void push(Lista*, int);
void append(Lista*, int);

void remover(Lista*, int);
void pop(Lista*);

#endif