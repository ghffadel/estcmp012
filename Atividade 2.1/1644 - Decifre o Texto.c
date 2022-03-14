# include <stdio.h>
# include <stdlib.h>

// Constante do tamanho máximo do vetor (maior valor de N)
# define MAXN 81

// Define uma struct de matriz
typedef struct {
    int m[MAXN][MAXN];
} Matriz;

// Declara as variáveis utilizadas
char cifrado[MAXN], original[MAXN];
int m, n, p[MAXN];

// Retorna uma matriz zerada
Matriz zerar () {
    Matriz matriz;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz.m[i][j] = 0;
        }
    }

    return matriz;
}

// Retorna uma matriz identidade
Matriz identidade () {
    Matriz matriz;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz.m[i][j] = (i == j);
        }
    }

    return matriz;
}

// Retorna a multiplicação entre duas matrizes
Matriz multiplicacao (Matriz a, Matriz b) {
    Matriz resultado = zerar();

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < n; k++) {
            if (a.m[i][k] != 0) {
                for (int j = 0; j < n; j++) {
                    if (b.m[k][j] != 0) {
                        resultado.m[i][j] += a.m[i][k] * b.m[k][j]; 
                    }
                }
            }
        }
    }

    return resultado;
}

// Implementação de uma exponenciação binária de uma matriz
Matriz exponenciacao (Matriz base, int expoente) {
    Matriz auxiliar = base, resultado = identidade();

    while (expoente) {
        if (expoente & 1) {
            resultado = multiplicacao(resultado, auxiliar);
        }

        auxiliar = multiplicacao(auxiliar, auxiliar);
        expoente >>= 1;
    }

    return resultado;
}

int main () {
    // Continua lendo enquanto n e m não forem 0
    while (scanf("%d %d", &n, &m) && n != 0 && m != 0) {
        Matriz base = zerar(), resultado;
        
        // Leitura dos dados
        for (int i = 0; i < n; i++) {
            scanf("%d", &p[i]);
        }

        getchar();
        gets(cifrado);

        // Preenchimento da matriz base
        for (int i = 0; i < n; i++) {
            base.m[i][p[i] - 1] = 1;
        }

        resultado = exponenciacao(base, m);
        
        // Geração da mensagem original
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                if (resultado.m[i][j] != 0) {
                    original[j] = cifrado[i];
                }
            }
        }

        original[n] = '\0';

        printf("%s\n", original);
    }

    return 0;
}