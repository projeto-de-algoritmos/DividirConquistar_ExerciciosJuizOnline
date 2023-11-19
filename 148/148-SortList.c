#include <stdio.h>

// Definicao da struct de no da lista.
struct List {
    int val;
    struct List* next;
};

// Funcao para mesclar duas listas ordenadas.
struct List* merge(struct List* l1, struct List* l2) {
    if (l1 == NULL && l2 == NULL) return NULL;
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    struct List* temp, *tail;
    // Inicializacao do no temporario e da cauda da lista mesclada.
    if (l1->val > l2->val) {
        temp = l2;
        tail = l2;
        l2 = l2->next;
    } else {
        temp = l1;
        tail = l1;
        l1 = l1->next;
    }

    // Loop para mesclar os elementos ordenadamente.
    while (l1 != NULL || l2 != NULL) {
        if (l1 != NULL && l2 != NULL) {
            if (l1->val > l2->val) {
                tail->next = l2;
                l2 = l2->next;
                tail = tail->next;
            } else {
                tail->next = l1;
                l1 = l1->next;
                tail = tail->next;
            }
        } else if (l1 != NULL) {
            tail->next = l1;
            break;
        } else {
            tail->next = l2;
            break;
        }
    }

    return temp;
}

// Funcao para ordenar uma lista usando a abordagem Merge Sort.
struct List* sortList(struct List* head) {
    if (head == NULL || head->next == NULL) return head;

    struct List* slow = head, *fast = head, *prev = head;
    // Encontrar o ponto medio da lista.
    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // Dividir a lista em duas partes.
    prev->next = NULL;
    // Chamar recursivamente para ordenar cada metade.
    head = sortList(head);
    slow = sortList(slow);
    // Mesclar as listas ordenadas.
    return merge(head, slow);
}