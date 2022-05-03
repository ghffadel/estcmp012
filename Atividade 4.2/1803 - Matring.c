// Declaração de bibliotecas
# include <math.h>
# include <stdio.h>
# include <string.h>

// Quantidade máxima de colunas
# define MAXSIZE 82

// Declaração de variáveis
char matring[4][MAXSIZE];
int f, l, n;

// Pega o número que está na coluna atual
int get_number (int column) {
    int number = 0;
    
    for (int i = 0; i < 4; i++) {
        number += pow(10, 3 - i) * (matring[i][column] - '0');
    }
    
    return number;
}

int main () {
    // Lê a matring
    for (int i = 0; i < 4; i++) {
        scanf("%s", &matring[i]);
        n = strlen(matring[i]);
    }
    
    // Número que está na primeira coluna
    f = get_number(0);
    // Número que está na última coluna
    l = get_number(n - 1);
    
    for (int i = 1; i < n - 1; i++) {
        // Calcula o caracter nas colunas restantes
        printf("%c", (char) ((f * get_number(i) + l) % 257));
    }
    
    printf("\n");
    
    return 0;
}