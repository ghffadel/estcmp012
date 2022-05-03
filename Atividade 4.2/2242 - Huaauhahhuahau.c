// Declaração de bibliotecas
# include <stdbool.h>
# include <stdio.h>
# include <string.h>

// Tamanho máximo da risada
# define MAXSIZE 51

// Declaração de variáveis
bool funniest = true;
char laughter[MAXSIZE], vowels[MAXSIZE];
int size;

// Verifica se a letra é uma vogal
bool is_vowel (char letter) {
    return letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u';
}

int main () {
    // Lê a string da risada
    scanf("%s", laughter);
    
    for (int i = 0; i < strlen(laughter); i++) {
        // Se a letra atual for uma vogal, adiciona na string de vogais
        if (is_vowel(laughter[i])) {
            vowels[size++] = laughter[i];
        }
    }
    
    // Verifica se a string de vogais é palíndroma
    for (int i = 0; i < size; i++) {
        if (vowels[i] != vowels[size - i - 1]) {
            funniest = false;
            break;
        }
    }
    
    // Imprime a resposta
    printf("%c\n", "NS"[funniest]);
    
    return 0;
}