# include <stdio.h>
# include <stdlib.h>

// Função que calcula recursivamente o máximo divisor comum
int mdc (int x, int y) {
    if (y == 0) return x;
    return mdc(y, x % y);
}

int main () {
    int f1, f2, n;

    // Quantidade de casos de teste
    scanf("%d", &n);

    // Loop dos casos de teste
    while (n--) {
        scanf("%d %d", &f1, &f2);
        // O tamanho máximo da filha é igual ao mdc entre as quantidades
        printf("%d\n", mdc(f1, f2));
    }
}