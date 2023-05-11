#include <stdio.h>
#include "linkedlist.h"

int main() {
    Lista *l1 = linkedList();

    for (int i = 1; i <= 4; i++) {
        append(l1, i);
    }
    remover(l1, 3);

    append(l1, 50);
    display(l1);
    pop(l1);
    display(l1);

    printf("%d", l1->tamanho);

    return 0;
}