// Importando as bibliotecas necessárias
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

// Tamanho máximo de N
# define MAXN 1010

// Declarando variáveis
bool visited[MAXN];
char line[MAXN];
int adjacency[MAXN][MAXN], answer[MAXN], count[MAXN], edge_count, n, size, vertex_count;

// Função de busca em profundidade
void depth_first_search (int vertex) {
    visited[vertex] = true;
    edge_count += count[vertex];
    vertex_count++;
    for (int i = 0; i < n; i++) if (adjacency[vertex][i] && !visited[i]) depth_first_search(i);
}

// Funções de implementação do merge sort em ordem decrescente
void merge (int *array, int n, int left, int mid, int right) {
    int temporary[n];

    for (int i = left; i <= right; i++) temporary[i] = array[i];

    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right) {
        if (temporary[i] > temporary[j]) array[k++] = temporary[i++];
        else array[k++] = temporary[j++];
    }

    while (i <= mid) array[k++] = temporary[i++];
    while (j <= right) array[k++] = temporary[j++];
}

void merge_sort (int *array, int n, int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;

    merge_sort(array, n, left, mid);
    merge_sort(array, n, mid + 1, right);
    merge(array, n, left, mid, right);
}

int main () {
	// Lendo o valor de n
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
		// Lendo a linha inteira
        scanf(" %s", line);
        
        for (int j = 0; j < n; j++) {
            // Se não for ele mesmo e estiver na mesma casa, alterar na matriz de adjacência e incrementar o número de ligações
            if (i != j && line[j] == 'S') {
                adjacency[i][j] = 1;
                count[i]++;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
		// Fará uma busca em profundidade se o vértice não tiver sido visitado
        if (!visited[i]) {
            edge_count = vertex_count = 0;
            depth_first_search(i);
            
            // Verificando se não há inconsistências
            if (vertex_count * (vertex_count - 1) != edge_count) {
                printf("-1\n");
                return 0;
            }
            
            answer[size++] = vertex_count;
        }
    }
    
    // Ordenando e imprimindo a resposta
    merge_sort(answer, size, 0, size - 1);
    
    printf("%d\n", size);
    
    for (int i = 0; i < size; i++) printf("%d%c", answer[i], " \n"[i == size - 1]);
    
    return 0;
}