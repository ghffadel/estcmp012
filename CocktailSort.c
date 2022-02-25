# include <locale.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

# define MAXN 100000

int desordenado[MAXN];
int ordenado_crescente[MAXN];
int ordenado_decrescente[MAXN];
int ordenado_metade_crescente[MAXN];
int ordenado_metade_decrescente[MAXN];

void troca (int *x, int *y) {
  *x ^= *y;
  *y ^= *x;
  *x ^= *y;
}

// A função recebe o vetor e o seu tamanho como parâmetros
void cocktail_sort (int *vetor, int n) {
  // Variável que indica se o vetor já está ordenado
  int ordenado = 0;

  // Executa enquanto não estiver ordenado
  while (!ordenado) {
    // Supondo que o vetor já esteja ordenado
    ordenado = 1;

    // Verificação da esquerda pra direita até o penúltimo elemento
    for (int i = 0; i < n - 1; i++) {
      // Se o número for maior que o próximo
      if (vetor[i] > vetor[i + 1]) {
        // Eles trocam de posição
        troca(&vetor[i], &vetor[i + 1]);
        // Indica que o vetor não está ordenado
        ordenado = 0;
      }
    }

    // Se não houver nenhuma troca, o vetor já está ordenado e a execução se encerra
    if (ordenado) break;

    // Supondo que o vetor já esteja ordenado
    ordenado = 1;

    // Verificação da direita pra esquerda até o segundo elemento
    for (int i = n - 1; i > 0; i--) {
      // Se o número for menor que o anterior
      if (vetor[i] < vetor[i - 1]) {
        // Eles trocam de posição
        troca(&vetor[i], &vetor[i - 1]);
        // Indica que o vetor não está ordenado
        ordenado = 0;
      }
    }
  }
}

void verifica_tempo (int *vetor) {
  clock_t t = clock();
  cocktail_sort(vetor, MAXN);
  t = clock() - t;
  double tempo = (double) t / CLOCKS_PER_SEC;
  printf("Tempo: %.3lf segundos\n\n", tempo);
}

int main () {
  srand(time(NULL));
  
  for (int i = 0; i < MAXN; i++) {
    desordenado[i] = rand();
  }
  
  for (int i = 0; i < MAXN; i++) {
    ordenado_crescente[i] = i;
    ordenado_decrescente[i] = MAXN - i - 1;
    
    if (i < MAXN / 2) {
      ordenado_metade_crescente[i] = i;
      ordenado_metade_decrescente[i] = MAXN - i - 1;
    }

    else {
      ordenado_metade_crescente[i] = MAXN - i - 1;
      ordenado_metade_decrescente[i] = i;
    }
  }

  printf("Desordenado\n");
  verifica_tempo(desordenado);

  printf("Ordenando crescente\n");
  verifica_tempo(ordenado_crescente);

  printf("Ordenando decrescente\n");
  verifica_tempo(ordenado_decrescente);

  printf("Ordenando metade crescente\n");
  verifica_tempo(ordenado_metade_crescente);

  printf("Ordenando metade decrescente\n");
  verifica_tempo(ordenado_metade_decrescente);
  
  return 0;
}