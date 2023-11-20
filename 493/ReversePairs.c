#include <stdio.h>
#include <stdlib.h>

int merge(int *v, int esquerda, int meio, int direita) {
    int j = meio + 1;
    int cont = 0;
    int *temp = (int *)malloc((direita - esquerda + 1) * sizeof(int));

    int i = esquerda;

    while (i <= meio) {
        while (j <= direita && v[i] > 2LL * v[j]) {
            j++;
        }
        cont += (j - (meio + 1));
        i++;
    }

    i = esquerda;
    j = meio + 1;
    int k = 0;

    while (i <= meio && j <= direita) {
        if (v[i] <= v[j]) {
            temp[k++] = v[i++];
        } else {
            temp[k++] = v[j++];
        }
    }

    while (i <= meio) {
        temp[k++] = v[i++];
    }

    while (j <= direita) {
        temp[k++] = v[j++];
    }

    k = 0;
    for (i = esquerda; i <= direita; i++) {
        v[i] = temp[k++];
    }

    free(temp);

    return cont;
}

int mergeSort(int *v, int esquerda, int direita) {
    int cont = 0;

    if (esquerda < direita) {
        int meio = (esquerda + direita) / 2;
        cont += mergeSort(v, esquerda, meio);
        cont += mergeSort(v, meio + 1, direita);
        cont += merge(v, esquerda, meio, direita);
    }

    return cont;
}

int reversePairs(int *v, int n) {
    int resultado = mergeSort(v, 0, n - 1);
    return resultado;
}

int main() {
    int v[] = {1, 3, 2, 3, 1};
    int n = sizeof(v) / sizeof(v[0]);

    int result = reversePairs(v, n);

    printf("Number of reverse pairs: %d\n", result);

    return 0;
}
