#include <stdio.h>

double findMedianSortedArrays(int nums1[], int m, int nums2[], int n) {
    int x = m + n;
    int comprimentoTotal = (x % 2 == 0) ? 1 : -1; // Determine se o comprimento total é par ou ímpar

    int y = 0;  // Contador para elementos mesclados
    int i = 0;  // Ponteiro para nums1
    int j = 0;  // Ponteiro para nums2
    int q1, q2; // Valores para cálculo da mediana

    while (y <= x / 2) {
        q1 = q2; // Armazene o valor anterior de q2

        if (i < m && (j >= n || nums1[i] <= nums2[j])) {
            q2 = nums1[i];
            i++;
        } else {
            q2 = nums2[j];
            j++;
        }
        y++;
    }

    if (comprimentoTotal == 1) {
        return (q1 + q2) / 2.0; // Retorne a média de q1 e q2
    } else {
        return q2; // Retorne o valor de q2
    }
}

int main() {

    // Exemplo de uso
    int nums1[] = {1, 3};
    int m = sizeof(nums1) / sizeof(nums1[0]);
    int nums2[] = {2};
    int n = sizeof(nums2) / sizeof(nums2[0]);

    double result = findMedianSortedArrays(nums1, m, nums2, n);
    printf("A mediana é: %f\n", result);

    return 0;
}
