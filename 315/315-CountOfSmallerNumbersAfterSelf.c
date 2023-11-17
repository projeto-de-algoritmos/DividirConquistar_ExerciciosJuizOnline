// Funcao para contar elementos menores durante o merge.
void merge(int* contagens, int* indices, int* nums, int esquerda, int meio, int direita) {
    int i = esquerda; // Indice do subarray esquerdo.
    int j = meio + 1; // Indice do subarray direito.
    int k = 0; // Indice temporario.
    int temp[direita - esquerda + 1]; // Array temporario para mesclar.

    // Mescla os subarrays ordenados e conta os elementos menores a direita.
    while (i <= meio && j <= direita) {
        if (nums[indices[i]] <= nums[indices[j]]) {
            contagens[indices[i]] += j - (meio + 1);
            temp[k++] = indices[i++];
        } else {
            temp[k++] = indices[j++];
        }
    }

    // Lidar com elementos remanescentes no subarray esquerdo.
    while (i <= meio) {
        contagens[indices[i]] += j - (meio + 1);
        temp[k++] = indices[i++];
    }

    // Lidar com elementos remanescentes no subarray direito.
    while (j <= direita) {
        temp[k++] = indices[j++];
    }

    // Copiar os elementos mesclados de volta ao array original.
    for (int x = 0; x < k; x++) {
        indices[esquerda + x] = temp[x];
    }
}

// Funcao de ordenacao por mesclagem e contagem.
void mergeSort(int* contagens, int* indices, int* nums, int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;
        // Chamar mergeSort recursivamente para subarrays esquerdo e direito.
        mergeSort(contagens, indices, nums, esquerda, meio);
        mergeSort(contagens, indices, nums, meio + 1, direita);
        // Mesclar subarrays ordenados.
        merge(contagens, indices, nums, esquerda, meio, direita);
    }
}

// Funcao principal para contar elementos menores a direita.
int* countSmaller(int* nums, int tamanho, int* returnSize) {
    *returnSize = tamanho;
    int* contagens = (int*)malloc(tamanho * sizeof(int));
    int* indices = (int*)malloc(tamanho * sizeof(int));

    // Inicializar arrays de contagem e indices.
    for (int i = 0; i < tamanho; i++) {
        contagens[i] = 0;
        indices[i] = i;
    }

    // Realizar ordenacao por mesclagem e contagem.
    mergeSort(contagens, indices, nums, 0, tamanho - 1);

    // Liberar a memoria alocada para os indices.
    free(indices);

    return contagens;
}
