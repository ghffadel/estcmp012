// Importando as bibliotecas necessárias
# include <climits>
# include <cstdio>
# include <map>
# include <queue>
# include <string>
# include <vector>

using namespace std;

// Definindo o número máximo de caracteres
# define MAXSIZE 60

// Declarando variáveis
char common[MAXSIZE], finish[MAXSIZE], language1[MAXSIZE], language2[MAXSIZE], start[MAXSIZE];
int m;
map<string, int> dist;
map<string, vector<pair<string, string>>> graph;

// Definição da função Dijkstra para encontrar o menor caminho
int dijkstra (string source, string destiny) {
    priority_queue<pair<int, pair<string, string>>, vector<pair<int, pair<string, string>>>, greater<pair<int, pair<string, string>>>> priority;
    
    dist[source] = 0;
    priority.push({0, {source, " "}});
    
    while (!priority.empty()) {
        auto [u, x] = priority.top().second;
        priority.pop();
        
        if (u == destiny) break;
        
        for (auto [v, w]: graph[u]) {
            if (w[0] != x[0] && dist[v] > dist[u] + w.size()) {
                dist[v] = dist[u] + w.size();
                priority.push({dist[v], {v, w}});
            }
        }
    }
    
    return dist[destiny];
}

int main () {
    // Lê m enquanto m não for 0
    while (scanf("%d", &m) && m) {
        scanf("%s %s", start, finish);
        dist[start] = dist[finish] = INT_MAX;
        
        for (int i = 0; i < m; i++) {
            scanf("%s %s %s", language1, language2, common);
            // Estruturando o grafo
            dist[language1] = dist[language2] = INT_MAX;
            graph[language1].push_back({language2, common});
            graph[language2].push_back({language1, common});
        }
        
        // Imprimindo o resultado
        int answer = dijkstra(finish, start);
        if (answer == INT_MAX) printf("impossivel\n");
        else printf("%d\n", answer);
        
        // Resetando as estruturas
        dist.clear();
        graph.clear();
    }
    
    return 0;
}