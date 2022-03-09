# include <stdio.h>
# include <stdlib.h>
# include <string.h>

char linha[2550];
int casos;

// Implementa o insertion sort
void insertion_sort (char **vetor, int n) {
    for (int i = 1; i < n; i++) {
        char *chave = vetor[i];
        int j;

        /* 
            A comparação entre os tamanhos das strings é feita na função strlen, 
            que retorna o tamanho da string.
        */
        for (j = i - 1; j >= 0 && strlen(vetor[j]) < strlen(chave); j--) {
            vetor[j + 1] = vetor[j];
        }

        vetor[j + 1] = chave;
    }
}

int main () {
    // Lê a quantidade de casos de teste
    scanf("%d", &casos);

    // Repetição dos casos de teste
    while (casos--) {
        // Cria um vetor de strings (ou matriz de caracteres)
        char **palavras = malloc(50 * sizeof(char *));
        int j = 0, n = 0;

        // Lê toda a linha de uma vez, incluindo os espaços
        scanf(" %[^\n]", linha);

        // Reserva espaço para a 1ª linha
        palavras[0] = malloc(50 * sizeof(char));

        // Itera sobre todas as posições da linha
        for (int i = 0; linha[i] != '\0'; i++) {
            // Se for um espaço
            if (linha[i] == ' ') {
                // Adiciona o caracter de fim de string
                palavras[n++][j] = '\0';
                // Reserva espaço para a próxima linha
                palavras[n] = malloc(50 * sizeof(char));
                // A coluna é resetada
                j = 0;
            }

            else {
                // Adiciona a palavra no final da linha
                palavras[n][j++] = linha[i];
            }
        }

        // Adiciona o caracter de fim de string
        palavras[n++][j] = '\0';

        // Ordena o vetor pelo tamanho de maneira decrescente
        insertion_sort(palavras, n);

        // Imprime os elementos do vetor
        for (int i = 0; i < n; i++) {
            printf("%s%c", palavras[i], " \n"[i == n - 1]);
        }
    }

    return 0;
}