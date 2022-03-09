# include <stdio.h>
# include <stdlib.h>
# include <string.h>

char comportou;
int comportaram, n;

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
    // Lê a quantidade n
    scanf("%d", &n);

    // Cria um vetor de strings (ou matriz de caracteres)
    char **criancas = malloc(n * sizeof(char *));

    // Faz a leitura do vetor
    for (int i = 0; i < n; i++) {
        criancas[i] = malloc(20 * sizeof(char));
        scanf(" %c %s", &comportou, criancas[i]);
        // Incrementa a contagem das crianças que se comportaram
        if (comportou == '+') comportaram++;
    }

    // Ordena o vetor de maneira crescente
    insertion_sort(criancas, n);

    // Imprime os elementos do vetor e quantas crianças se comportaram ou não
    for (int i = 0; i < n; i++) {
        printf("%s\n", criancas[i]);
    }

    printf("Se comportaram: %d | Nao se comportaram: %d\n", comportaram, n - comportaram);

    return 0;
}