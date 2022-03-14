# include <stdio.h>
# include <stdlib.h>

// Constante do tamanho máximo do vetor (maior valor de N)
# define MAXN 101

int main () {
    int n, *res;

    // Vetor que armazena as respostas
    res = malloc(MAXN * sizeof(int));

    // Faz o preprocessamento das respostas
    for (int i = 1; i < MAXN; i++) {
        // Possibilidades = possibilidades anteriores + novas possibilidades (acumulativo)
        res[i] = res[i - 1] + i * i;
    }

    // Continua lendo enquanto n não for 0
    while (scanf("%d", &n) && n != 0) {
        // Imprime a resposta já calculada
        printf("%d\n", res[n]);
    }

    return 0;
}