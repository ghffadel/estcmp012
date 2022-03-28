# define vertex int

typedef struct node *link;

struct node {
    vertex v;
    link next;
};

typedef struct graph *Graph;

struct graph {
    int vertices_count;
    int edges_count;
    link *adjacency_list;
};

link create_node (vertex v, link next) {
    link node = malloc(sizeof(struct node));
    
    node->v = v;
    node->next = next;
    
    return node;
}

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

void add_edge (Graph graph, vertex u, vertex v) {
    for (link edge = graph->adjacency_list[u]; edge != NULL; edge = edge->next) {
        if (edge->v == v) {
            return;
        }
    }
    
    graph->adjacency_list[u] = create_node(v, graph->adjacency_list[u]);
    graph->edges_count++;
}