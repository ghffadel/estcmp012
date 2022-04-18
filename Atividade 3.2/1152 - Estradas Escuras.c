// Importando as bibliotecas necessárias
# include <stdio.h>
# include <stdlib.h>

// Definindo tamanho máximo do vetor
# define MAXN 200010

// Definindo a struct da aresta
typedef struct edge {
    int source, destiny, weight;
} Edge;

// Declarando variáveis
Edge edges[MAXN];
int m, n, parent[MAXN];

// Função de troca
void swap (Edge *x, Edge *y) {
    Edge aux = *x;
    *x = *y;
    *y = aux;
}

// Funções que realizam o merge sort
void merge (Edge *array, int n, int left, int mid, int right) {
  Edge temporary[n];

  for (int i = left; i <= right; i++) temporary[i] = array[i];

  int i = left, j = mid + 1, k = left;

  while (i <= mid && j <= right) {
    if (temporary[i].weight < temporary[j].weight) array[k++] = temporary[i++];
    else array[k++] = temporary[j++];
  }

  while (i <= mid) array[k++] = temporary[i++];
  while (j <= right) array[k++] = temporary[j++];
}

void merge_sort (Edge *array, int n, int left, int right) {
  if (left >= right) return;

  int mid = (left + right) / 2;

  merge_sort(array, n, left, mid);
  merge_sort(array, n, mid + 1, right);
  merge(array, n, left, mid, right);
}

// Acha o vértice pai
int find_parent (int vertex) {
    if (parent[vertex] == vertex) return vertex;
    return parent[vertex] = find_parent(parent[vertex]);
}

int main () {
    // Lê enquanto m e n não forem 0
    while (scanf("%d %d", &m, &n) && (m || n)) {
        int minimal = 0, total = 0;
        
        for (int i = 0; i < n; i++) {
            // Lendo a aresta
            scanf("%d %d %d", &edges[i].source, &edges[i].destiny, &edges[i].weight);
            // Adiciona ao somatório total dos pesos
            total += edges[i].weight;
        }
        
        // Ordenando as arestas
        merge_sort(edges, n, 0, n - 1);
        
        // Inicializando o vetor dos pais
        for (int i = 0; i < m; i++) parent[i] = i;
        
        for (int i = 0; i < n; i++) {
            // Verifica o pai dos dois vértices
            int parent_source = find_parent(edges[i].source), parent_destiny = find_parent(edges[i].destiny);
            
            // Se forem de pais diferentes, é adicionado ao somatório da árvore mínima
            if (parent_source != parent_destiny) {
                parent[parent_destiny] = parent[parent_source];
                minimal += edges[i].weight;
            }
        }
        
        // Retornando a diferença entre o total e o mínimo
        printf("%d\n", total - minimal);
    }
    
    return 0;
}