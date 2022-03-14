# include <stdio.h>
# include <stdlib.h>

// Definição de uma struct para o time
typedef struct {
    int mandante, visitante;
} time;

int main () {
    int n;
    time t1, t2;

    // Quantidade de casos de teste
    scanf("%d", &n);

    // Loop dos casos de teste
    while (n--) {
        scanf("%d x %d", &t1.mandante, &t2.visitante);
        scanf("%d x %d", &t2.mandante, &t1.visitante);

        // Verifica primeiro o placar agregado
        if (t1.mandante + t1.visitante > t2.mandante + t2.visitante) printf("Time 1\n");
        else if (t1.mandante + t1.visitante < t2.mandante + t2.visitante) printf("Time 2\n");
        // Depois verifica a vantagem dos gols fora de casa
        else {
            if (t1.visitante > t2.visitante) printf("Time 1\n");
            else if (t1.visitante < t2.visitante) printf("Time 2\n");
            else printf("Penaltis\n");
        }
    }

    return 0;
}