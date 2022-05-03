// Declaração de bibliotecas
# include <ctype.h>
# include <stdbool.h>
# include <stdio.h>
# include <string.h>

// Tamanho máximo da senha
# define MAXSIZE 17 

// Declaração de variáveis
char password[MAXSIZE];
int t;

// Verifica se a letra pode ser substituída por um número
bool can_use_number (char letter) {
    return letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 's';
}

int main () {
    // Lê a quantidade de casos de teste
    scanf("%d", &t);
    
    while (t--) {
        // Produtório da quantidade total de variações
        int variations = 1;
        
        // Lê a senha
        scanf("%s", password);
        
        for (int i = 0; i < strlen(password); i++) {
            // Verifica se a letra atual pode ser substituída por um número
            if (can_use_number(tolower(password[i]))) {
                // Caso possa ser substituído, há três possibilidades (maiúsculo, minúsculo e o número)
                variations *= 3;
            }
            
            else {
                // Caso contrário, só há duas possibilidades (maiúsculo e minúsculo)
                variations *= 2;
            }
        }
        
        // Imprime o resultado
        printf("%d\n", variations);
    }
    
    return 0;
}