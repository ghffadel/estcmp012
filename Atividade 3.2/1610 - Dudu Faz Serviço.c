// Importando as bibliotecas necessárias
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

// Definindo constantes
# define NOT_VISITED 0
# define VISITED 1
# define FINISHED 2
# define MAXN 10010

typedef struct node *link;

// Definindo a struct do Nó
struct node {
    int vertex;
    link next;
};

typedef struct graph *Graph;

// Definindo a struct do Grafo
struct graph {
    int vertices_count;
    int edges_count;
    link *adjacency_list;
};

// Declarando variáveis
bool has_cycle;
Graph graph;
int a, b, m, n, t, visited[MAXN];

// Inicializando um novo nó
link create_node (int vertex, link next) {
    link node = malloc(sizeof(struct node));
    
    node->vertex = vertex;
    node->next = next;
    
    return node;
}

// Inicializando um novo grafo
Graph init (int vertices_count) {
    Graph graph = malloc(sizeof *graph);
    
    graph->vertices_count = vertices_count;
    graph->edges_count = 0;
    graph->adjacency_list = malloc(vertices_count * sizeof(link));
    
    for (int i = 0; i < vertices_count; i++) {
        graph->adjacency_list[i] = NULL;
    }
    
    return graph;
}

// Adicionando uma aresta no grafo
void add_edge (Graph graph, int source, int destiny) {
    // Verificando se o vértice destino já está presente nas adjacências da origem
    for (link edge = graph->adjacency_list[source]; edge != NULL; edge = edge->next) {
        if (edge->vertex == destiny) return;
    }
    
    // Adicionando o vértice destino
    graph->adjacency_list[source] = create_node(destiny, graph->adjacency_list[source]);
    graph->edges_count++;
}

// Realizando uma busca em profundidade
void depth_first_search (int vertex) {
    // O vértice é marcado como visitado
    visited[vertex] = VISITED;
    
    // Para de executar se encontrar um ciclo
    if (has_cycle) return;
    
    // Verifica nas adjacências do vértice atual
    for (link edge = graph->adjacency_list[vertex]; edge != NULL; edge = edge->next) {
        // Interrompe a execução se um vértice adjacente já tiver sido visitado na mesma passsada
        if (visited[edge->vertex] == VISITED) {
            has_cycle = true;
            return;
        }
        
        // Se não foi visitado, a busca em profundidade continua
        else if (!visited[edge->vertex]) depth_first_search(edge->vertex);
    }
    
    // Final da passada
    visited[vertex] = FINISHED;
}

int main () {
    // Quantidade de casos de testes
    scanf("%d", &t);
    
    while (t--) {
		// Lendo n e m
        scanf("%d %d", &n, &m);
        
        // Inicializando as variáveis
        graph = init(n);
        has_cycle = false;
        for (int i = 0; i < n; i++) visited[i] = NOT_VISITED;
        
        while (m--) {
			// Lendo os dois vértices e adicionando uma aresta no grafo
            scanf("%d %d", &a, &b);
            add_edge(graph, --a, --b);
        }
        
        // Realiza a busca em profundidade dos componentes
        for (int i = 0; i < n; i++) {
            if (!visited[i]) depth_first_search(i);
            if (has_cycle) break;
        }
        
        // Imprime a mensagem
        printf("%s\n", has_cycle ? "SIM" : "NAO");
    }
    
    return 0;
}