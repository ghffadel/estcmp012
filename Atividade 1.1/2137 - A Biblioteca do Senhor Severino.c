# include <stdio.h>
# include <stdlib.h>
# include <string.h>

int n;

// Implementa o insertion sort
void insertion_sort (char **vetor, int n) {
    for (int i = 1; i < n; i++) {
        char *chave = vetor[i];
        int j;

        /* 
            A comparação entre strings é feita na função strcmp, que retorna um 
            número maior que 0 caso a primeira string for maior que a segunda.
        */
        for (j = i - 1; j >= 0 && strcmp(vetor[j], chave) > 0; j--) {
            vetor[j + 1] = vetor[j];
        }

        vetor[j + 1] = chave;
    }
}

int main () {
    // Lê o tamanho n enquanto não for fim de arquivo (EOF)
    while (scanf("%d", &n) != EOF) {
        // Cria um vetor de strings (ou matriz de caracteres)
        char **livros = malloc(n * sizeof(char *));

        // Faz a leitura do vetor
        for (int i = 0; i < n; i++) {
            livros[i] = malloc(4 * sizeof(char));
            scanf(" %s", livros[i]);
        }

        // Ordena o vetor de maneira crescente
        insertion_sort(livros, n);

        // Imprime os elementos do vetor
        for (int i = 0; i < n; i++) {
            printf("%s\n", livros[i]);
        }
    }

    return 0;
}