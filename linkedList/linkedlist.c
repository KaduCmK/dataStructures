#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
        int valor;
        struct Node *proximo;
} Node;

typedef struct lista {
    Node *inicio;
    Node *fim;
    int tamanho;
} Lista;


// funcao p instanciar uma lista vazia
Lista * linkedList() {
    Lista *l = (Lista*) malloc(sizeof(Lista));
    l->inicio = NULL;
    l->fim = NULL;
    l->tamanho = 0;

    return l;
}

// O(n)
// Percorre toda a lista e exibe todos os seus elementos, separados por espaço
void display(Lista *lista) {
    Node *n = lista->inicio;
    while (n != NULL) {
        printf("%d ", n->valor);
        n = n->proximo;
    }
    printf("\n");
}

void push(Lista *lista, int valor) {
    // Criando node do novo elemento
    Node *n = (Node*) malloc(sizeof(Node));
    n->valor = valor;

    // checar se lista ta vazia
    if (lista->inicio == NULL) {
        n->proximo = NULL;
        lista->inicio = n;
        lista->fim = n;
        lista->tamanho = 1;
    }
    else {
        n->proximo = lista->inicio;
        lista->inicio = n;
        lista->tamanho++;
    }
}

void append(Lista *lista, int valor) {
    // Criando node do novo elemento
    Node *n = (Node*) malloc(sizeof(Node));
    n->valor = valor;
    n->proximo = NULL;

    // checar se lista ta vazia
    if (lista->inicio == NULL) {
        lista->inicio = n;
        lista->fim = n;
        lista->tamanho = 1;
    }
    else {
        lista->fim->proximo = n;
        lista->fim = n;
        lista->tamanho++;
    }
}

void remover(Lista *lista, int index) {
    // navegando do inicio ate o index
    Node *previous = lista->inicio;
    for (int i = 1; i < index-1; i++) {
        previous = previous->proximo;
    }
    // linkando index-1 ao index+1
    Node *remover = previous->proximo;
    previous->proximo = remover->proximo;

    free(remover);
    lista->tamanho--;
}

// O(n)
// Percorre toda a lista ate o penultimo elemento;
// Elimina o ultimo elemento e atribui o penulimo ao ponteiro do fim da lista
void pop(Lista *lista) {
    Node *prev = lista->inicio;
    for (int i = 1; i < lista->tamanho - 1; i++) {
        prev = prev->proximo;
    }
    prev->proximo = NULL;
    free(lista->fim);
    lista->fim = prev;
    lista->tamanho--;
}

int main() {
    Lista *l1 = linkedList();

    append(l1, 1);
    append(l1, 2);
    append(l1, 3);
    append(l1, 4);
    remover(l1, 3);

    append(l1, 50);
    display(l1);
    pop(l1);
    display(l1);

    printf("%d", l1->tamanho);

    free(l1);

    return 0;
}