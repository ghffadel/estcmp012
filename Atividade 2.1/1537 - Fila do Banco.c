# include <stdio.h>
# include <stdlib.h>

// Muda o nome de long long
typedef long long ll;

// Constante do tamanho máximo do vetor (maior valor de N)
# define MAXN 100001
// Define o resto da divisão
# define MOD 1000000009
// Define o inverso modular de 6
# define INV 833333341

int main () {
    int n;
    ll *fat;

    // Vetor que armazena os fatoriais
    fat = malloc(MAXN * sizeof(ll));

    // Caso base
    fat[1] = 1;

    // Faz o preprocessamento dos fatoriais módulo MOD
    for (ll i = 2; i < MAXN; i++) {
        fat[i] = (fat[i - 1] * i) % MOD;
    } 

    // Continua lendo enquanto n não for 0
    while (scanf("%d", &n) && n != 0) {
        // Equivalente a (n! mod MOD) / 6
        printf("%lld\n", (fat[n] * INV) % MOD);
    }

    return 0;
}