# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int n, p, q;

// Implementa o insertion sort
void insertion_sort (int *vetor, int n) {
    for (int i = 1; i < n; i++) {
        int chave = vetor[i], j;

        for (j = i - 1; j >= 0 && vetor[j] < chave; j--) {
            vetor[j + 1] = vetor[j];
        }

        vetor[j + 1] = chave;
    }
}

int main () {
    // Lê n e q enquanto não for fim de arquivo (EOF)
    while (scanf("%d %d", &n, &q) != EOF) {
        // Cria um vetor de inteiros
        int *notas = malloc(n * sizeof(int));

        // Faz a leitura do vetor
        for (int i = 0; i < n; i++) {
            scanf("%d", &notas[i]);
        }

        // Ordena o vetor de maneira decrescente
        insertion_sort(notas, n);

        // Lê as q consultas
        while (q--) {
            // Lê a posição p
            scanf("%d", &p);
            // Imprime a nota da posição p
            printf("%d\n", notas[--p]);
        }
    }

    return 0;
}