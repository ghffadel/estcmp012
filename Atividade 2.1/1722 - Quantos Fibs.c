# include <stdio.h>
# include <stdlib.h>
# include <string.h>

// Função que retorna o maior número
# define max(x, y) (x) > (y) ? (x) : (y)

// Constante do tamanho máximo do vetor (maior valor de N)
# define MAX_DIGITOS 101

// Constantes para facilitar leitura
# define MENOR -1
# define IGUAL 0
# define MAIOR 1

char a[MAX_DIGITOS], b[MAX_DIGITOS], c[MAX_DIGITOS], x[MAX_DIGITOS], y[MAX_DIGITOS];

// Compara o primeiro com o segundo número
int comparar (char num1[], char num2[]) {
    int tam1 = strlen(num1), tam2 = strlen(num2);

    if (tam1 > tam2) return MAIOR;
    else if (tam1 < tam2) return MENOR;
    else {
        for (int i = 0; i < tam1; i++) {
            if (num1[i] > num2[i]) return MAIOR;
            else if (num1[i] < num2[i]) return MENOR;
        }

        return IGUAL;
    }
}

// Verifica se o número está dentro do intervalo lido na função principal
int dentro_do_intervalo (char num[]) {
    return comparar(x, num) != MAIOR && comparar(num, y) != MAIOR;
}

// Faz a soma entre dois números e armazena a resposta na variável num3
void somar (char num1[], char num2[], char num3[]) {
    int tam1 = strlen(num1), tam2 = strlen(num2), tam3 = max(tam1, tam2) + 1;
    int carrega = 0, i = tam1 - 1, j = tam2 - 1, k = tam3 - 1;

    num3[tam3] = '\0';

    while (i >= 0 || j >= 0) {
        int soma = carrega;

        if (i >= 0) soma += num1[i--] - '0';
        if (j >= 0) soma += num2[j--] - '0';

        carrega = soma / 10;
        soma %= 10;
        num3[k--] = '0' + soma;
    }

    num3[k] = '0' + carrega;

    if (num3[0] == '0') memmove(num3, num3 + 1, sizeof(char) * tam3);
}

int main () {
    // Leitura enquanto os dois números forem diferentes de zero
    while (scanf("%s %s", x, y) && x[0] != '0' || y[0] != '0') {
        int resposta = 0;

        // Primeiro número de Fibonacci
        a[0] = '1';
        a[1] = '\0';
        
        // Segundo número de Fibonacci
        b[0] = '2';
        b[1] = '\0';

        // Verifica se já estão dentro dos intervalos
        if (dentro_do_intervalo(a)) resposta++;
        if (dentro_do_intervalo(b)) resposta++;

        // Verifica a quantidade de elementos que estão dentro do intervalo [x, y]
        while (comparar(b, y) != MAIOR) {
            somar(a, b, c);
            if (dentro_do_intervalo(c)) resposta++;
            memmove(a, b, sizeof(a));
            memmove(b, c, sizeof(b));
        }

        // Imprime a resposta
        printf("%d\n", resposta);
    }

    return 0;
}