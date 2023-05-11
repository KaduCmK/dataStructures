#include <stdio.h>
#include <stdlib.h>

// listas encadeadas so conseguem ser navegadas em uma direcao (p frente)...
// atribuir a um node tanto o endereco do prox node como o endereco do node anterior p fazer uma lista duplamente encadeada
// assim fica possivel navegar de tras pra frente e vice versa

typedef struct Node {
    struct Node *anterior;
    int valor;
    struct Node *proximo;
} Node;

typedef struct Lista {
    Node *inicio;
    Node *fim;
    int tamanho;
} Lista;

// Instancia uma nova lista duplamente encadeada vazia
Lista * doublyLinkedList() {
    Lista *l = (Lista*) malloc(sizeof(Lista));
    l->inicio = NULL;
    l->fim = NULL;
    l->tamanho = 0;

    return l;
}

// Instancia um novo node com o valor fornecido
Node * newNode(int valor) {
    Node *n = (Node*) malloc(sizeof(Node));
    n->valor = valor;
    n->anterior = NULL;
    n->proximo = NULL;

    return n;
}


// Deleta a lista por completo
void destroy(Lista *lista) {
    Node *n = lista->inicio;
    while (n->proximo != NULL) {
        n = n->proximo;
        free(n->anterior);
    }
    free(n);
    free(lista);
}

// Exibe os valores da lista, do inicio ao fim
void display(Lista *lista) {
    Node *n = lista->inicio;
    while (n != NULL) {
        printf("%d ", n->valor);
        n = n->proximo;
    }
    printf("\n");
}

// Encontrar o indice da primeira ocorrencia de um elemento na lista;
// Retorna -1 se o valor nao for encontrado
int findIndex(Lista *lista, int valor) {
    Node *n = lista->inicio;
    for (int i = 1; i <= lista->tamanho; i++) {
        if (n->valor == valor) return i;
        n = n->proximo;
    }
    return -1;
}

// Retorna o elemento presente no index fornecido
int findAt(Lista *lista, int index) {
    Node *n = lista->inicio;
    for (int i = 0; i < index-1; i++) {
        n = n->proximo;
    }

    return n->valor;
}

// Adiciona um elemento ao inicio da lista
void push(Lista *lista, int valor) {
    Node *n = newNode(valor);

    // Lista vazia
    if (lista->tamanho == 0) {
        lista->inicio = n;
        lista->fim = n;
    }
    else {
        n->proximo = lista->inicio;
        lista->inicio->anterior = n;
        lista->inicio = n;
    }
    lista->tamanho++;
}

// Adiciona um elemento na posicao i da lista
void add(Lista *lista, int valor, int index) {
    Node *n = newNode(valor);
    Node *aux = lista->inicio;
    for (int i = 1; i < index-1; i++) {
        aux = aux->proximo;
    }
    n->anterior = aux;
    n->proximo = aux->proximo;
    n->proximo->anterior = n;
    aux->proximo = n;
    lista->tamanho++;
}

// Adiciona um elemento ao final da lista
void append(Lista *lista, int valor) {
    Node *n = newNode(valor);

    // Lista vazia
    if (lista->tamanho == 0) {
        lista->inicio = n;
        lista->fim = n;
    }
    else {
        n->anterior = lista->fim;
        lista->fim->proximo = n;
        lista->fim = n;
    }
    lista->tamanho++;
}

// Remove o primeiro elemento da lista
void removeFirst(Lista *lista) {
    Node *prox = lista->inicio->proximo;
    prox->anterior = NULL;
    free(lista->inicio);
    lista->inicio = prox;
    lista->tamanho--;
}

// Remove o i-esimo elemento da lista
void remover(Lista *lista, int index) {
    Node *remover = lista->inicio;
    for (int i = 1; i < index; i++) {
        remover = remover->proximo;
    }
    remover->anterior->proximo = remover->proximo;
    remover->proximo->anterior = remover->anterior;
    free(remover);
    lista->tamanho--;
}

// Remove o ultimo elemento da lista
void pop(Lista *lista) {
    Node *prev = lista->fim->anterior;
    prev->proximo = NULL;
    free(lista->fim);
    lista->fim = prev;
    lista->tamanho--;
}

int main() {
    Lista *l1 = doublyLinkedList();

    for (int i = 1; i <= 5; i++) {
        append(l1, i);
    }

    display(l1);
    printf("%d\n", findAt(l1, 2));
    // printf("%d", findIndex(l1, 4));
    printf("tamanho da lista = %d\n\n", l1->tamanho);
    destroy(l1);
    return 0;
}