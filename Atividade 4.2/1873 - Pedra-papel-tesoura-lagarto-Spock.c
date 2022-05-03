// Declaração de bibliotecas
# include <stdbool.h>
# include <stdio.h>
# include <string.h>

// Tamanho máximo da string
# define MAXSIZE 10

// Declaração de variáveis
char rajesh[MAXSIZE], sheldon[MAXSIZE];
int c;

// Retorna se a string self consegue derrotar a string other.
bool defeat (char self[], char other[]) {
    // A função strcmp retorna 0 se as strings forem iguais
    if (strcmp(self, "pedra") == 0) {
        return strcmp(other, "lagarto") == 0 || strcmp(other, "tesoura") == 0;
    }
    
    else if (strcmp(self, "papel") == 0) {
        return strcmp(other, "pedra") == 0 || strcmp(other, "spock") == 0;
    }
    
    else if (strcmp(self, "tesoura") == 0) {
        return strcmp(other, "papel") == 0 || strcmp(other, "lagarto") == 0;
    }
    
    else if (strcmp(self, "lagarto") == 0) {
        return strcmp(other, "spock") == 0 || strcmp(other, "papel") == 0;
    }
    
    else if (strcmp(self, "spock") == 0) {
        return strcmp(other, "tesoura") == 0 || strcmp(other, "pedra") == 0;
    }
}

int main () {
    // Quantidade de casos de teste
    scanf("%d", &c);
    
    while (c--) {
        // Lê as escolhas de cada jogador
        scanf("%s %s", rajesh, sheldon);
        
        // Imprime o vencedor
        if (strcmp(rajesh, sheldon) == 0) {
            printf("empate\n");
        }
        
        else if (defeat(rajesh, sheldon)) {
            printf("rajesh\n");
        }
        
        else {
            printf("sheldon\n");
        }
    }
    
    return 0;
}