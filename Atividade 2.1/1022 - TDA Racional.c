# include <stdio.h>
# include <stdlib.h>

// Definição de uma struct para a fração
typedef struct {
    // Numerador e denominador
    int num, den;
} fracao;

// Função que retorna a soma de duas frações
fracao soma (fracao x, fracao y) {
    fracao res;
    res.num = x.num * y.den + y.num * x.den;
    res.den = x.den * y.den;
    return res;
}

// Função que retorna a diferença de duas frações
fracao subtracao (fracao x, fracao y) {
    fracao res;
    res.num = x.num * y.den - y.num * x.den;
    res.den = x.den * y.den;
    return res;
}

// Função que retorna a multiplicação de duas frações
fracao multiplicacao (fracao x, fracao y) {
    fracao res;
    res.num = x.num * y.num;
    res.den = x.den * y.den;
    return res;
}

// Função que retorna a divisão de duas frações
fracao divisao (fracao x, fracao y) {
    fracao res;
    res.num = x.num * y.den;
    res.den = y.num * x.den;
    return res;
}

// Função que calcula recursivamente o máximo divisor comum
int mdc (int x, int y) {
    // Se um número for negativo, transformá-lo em positivo
    if (x < 0) x *= -1;
    if (y < 0) y *= -1;
    if (y == 0) return x;
    return mdc(y, x % y);
}

int main () {
    char op;
    fracao x, y;
    int n;

    // Quantidade de casos de teste
    scanf("%d", &n);

    // Loop dos casos de teste
    while (n--) {
        fracao res;
        scanf("%d / %d %c %d / %d", &x.num, &x.den, &op, &y.num, &y.den);

        // Verifica a operação escolhido e armazena na variável de resposta
        switch (op)
        {
            case '+':
                res = soma(x, y);
                break;
            
            case '-':
                res = subtracao(x, y);
                break;

            case '*':
                res = multiplicacao(x, y);
                break;

            case '/':
                res = divisao(x, y);
                break;
        }

        // Verifica o mdc entre o numerador e o denominador
        int max_div_comum = mdc(res.num, res.den);

        // Imprime a fração inicial e a simplificada
        printf("%d/%d = %d/%d\n", res.num, res.den, res.num / max_div_comum, res.den / max_div_comum);
    }

    return 0;
}