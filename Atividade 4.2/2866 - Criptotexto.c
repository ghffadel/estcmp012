// Declaração de bibliotecas
# include <ctype.h>
# include <stdio.h>
# include <string.h>

// Tamanho máximo da mensagem
# define MAXSIZE 101

// Declaração de variáveis
char coded[MAXSIZE], decoded[MAXSIZE];
int c;

int main () {
    // Lê a quantidade de casos de teste
    scanf("%d", &c);
    
    while (c--) {
        // Tamanho da mensagem decodificada
        int size = 0;
        
        // Lê a mensagem codificada
        scanf("%s", coded);
        
        for (int i = 0; i < strlen(coded); i++) {
            // Adiciona na mensagem decodificada se a letra for minúscula
            if (islower(coded[i])) {
                decoded[size++] = coded[i];
            }
        }
        
        // Imprime a mensagem decodificada na ordem reversa
        for (int i = size - 1; i >= 0; i--) {
            printf("%c", decoded[i]);
        }
        
        printf("\n");
    }
    
    return 0;
}