// Importando as bibliotecas necessárias
# include <stdio.h>
# include <stdlib.h>

// Definindo a função de mínimo
# define min(x, y) (x) < (y) ? (x) : (y)
// Definindo o tamanho de máximo de N
# define MAXN 10010

// Declarando as variáveis utilizadas
int a, b, caso_de_teste_atual = 1, contador_atual = 1, converter, m, n, posicao_pilha, quantidade, t;
int contador_vertice[MAXN], pilha[MAXN], posicao_direcionado[MAXN], posicao_nao_direcionado[MAXN], visitado[MAXN];
int direcionado[MAXN][MAXN], nao_direcionado[MAXN][MAXN], restrito[MAXN][MAXN];
int dfs_low1[MAXN], dfs_num1[MAXN], dfs_number;
int dfs_low2[MAXN], dfs_num2[MAXN], dfs_parent[MAXN];

// Função Tarjan para encontrar componentes fortes
void tarjan (int u) {
    if (quantidade) return;
    
    dfs_low1[u] = dfs_num1[u] = dfs_number++;
    pilha[posicao_pilha++] = u;
    
    for (int i = 0; i < posicao_direcionado[u]; i++) {
        int v = direcionado[u][i];
        
        if (dfs_num1[v] == -1) tarjan(v);
        if (quantidade) return;
        if (visitado[v] != caso_de_teste_atual) dfs_low1[u] = min(dfs_low1[u], dfs_low1[v]);
    }
    
    if (dfs_low1[u] == dfs_num1[u]) {
        int contagem = 0;
        
        while (posicao_pilha > 0) {
            int topo = pilha[--posicao_pilha];
            visitado[topo] = caso_de_teste_atual;
            
            if (contador_vertice[topo] != contador_atual) contagem++;
            
            contador_vertice[topo] = contador_atual;
            
            if (topo == u) break;
        }
        
        if (contagem == n) quantidade = 1;
        
        contador_atual++;
    }
}

// Verifica a quantidade de pontes no grafo
void verifica_pontes (int u) {
    dfs_low2[u] = dfs_num2[u] = dfs_number++;
    
    if (quantidade == n) return;
    
    for (int i = 0; i < posicao_nao_direcionado[u]; i++) {
        int v = nao_direcionado[u][i];
        
        if (dfs_num2[v] == -1) {
            quantidade++;
            dfs_parent[v] = u;
            
            verifica_pontes(v);
            
            if (dfs_low2[v] > dfs_num2[u]) {
                if (restrito[u][v] == caso_de_teste_atual) {
                    converter = 1;
                }
            }
            
            dfs_low2[u] = min(dfs_low2[u], dfs_low2[v]);
        }
        
        else if (dfs_parent[u] != v) {
            dfs_low2[u] = min(dfs_low2[u], dfs_num2[v]);
        }
    }
}

int main () {
    // Lê n e m enquanto não for EOF
    while (scanf("%d %d", &n, &m) != EOF) {
        // Resetando as variáveis
        dfs_number = posicao_pilha = quantidade = 0;
        
        for (int i = 0; i < n; i++) {
            dfs_num1[i] = dfs_num2[i] = -1;
            posicao_direcionado[i] = posicao_nao_direcionado[i] = 0;
        }
        
        // Leitura dos dados e estruturação dos grafos
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &a, &b, &t); a--; b--;
            
            if (i == 0) continue;
            
            direcionado[a][posicao_direcionado[a]++] = b;
            nao_direcionado[a][posicao_nao_direcionado[a]++] = b;
            nao_direcionado[b][posicao_nao_direcionado[b]++] = a;
            
            if (t == 2) direcionado[b][posicao_direcionado[b]++] = a;
            else restrito[a][b] = restrito[b][a] = caso_de_teste_atual;
        }
        
        tarjan(0);
        
        // Imprimindo o resultado
        if (quantidade == 1) printf("-\n");
        
        else {
            dfs_number = quantidade = 0;
            
            verifica_pontes(0);
            
            if (quantidade != n - 1) printf("*\n");
            else if (converter) printf("2\n");
            else printf("1\n");
        }
        
        caso_de_teste_atual++;
        contador_atual++;
        converter = 0;
    }
    
    return 0;
}