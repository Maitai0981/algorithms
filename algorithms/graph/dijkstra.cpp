#include <bits/stdc++.h>
using namespace std;

#define int long long
#define INF LLONG_MAX // Define o valor de infinito para distâncias grandes
#define PQ priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> // Fila de prioridade (min-heap)

vector<pair<int, int>> adj[100000]; // Representação do grafo (lista de adjacência)
int dist[100000]; // Array para armazenar as distâncias mínimas

// Função para executar o algoritmo de Dijkstra
void dijkstra(int source, int n) {
    // Inicializa todas as distâncias como INF
    fill(dist, dist + n, INF);
    dist[source] = 0; // Distância do nó de origem é 0
    
    PQ pq; // Fila de prioridade para armazenar os nós a serem processados
    pq.push({0, source}); // Insere o nó de origem na fila
    
    while (!pq.empty()) {
        int u = pq.top().second; // Nó com a menor distância
        int d = pq.top().first;  // Distância do nó
        pq.pop();
        
        if (d > dist[u]) continue; // Se a distância já for maior, ignora

        // Processa os vizinhos do nó u
        for (auto edge : adj[u]) {
            int v = edge.first;   // Nó vizinho
            int weight = edge.second; // Peso da aresta
            
            // Se encontrar um caminho mais curto para v, atualiza a distância
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v}); // Coloca o vizinho na fila de prioridade
            }
        }
    }
}

int32_t main() {
    int n, m; // n = número de nós, m = número de arestas
    cin >> n >> m;
    
    // Leitura do grafo (arestas)
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w}); // Aresta de u para v com peso w
        adj[v].push_back({u, w}); // Grafo não direcionado, insere também de v para u
    }
    
    int source;
    cin >> source; // Nó de origem
    
    // Executa o algoritmo de Dijkstra a partir do nó de origem
    dijkstra(source, n);
    
    // Imprime as distâncias mínimas de todos os nós a partir da origem
    for (int i = 0; i < n; i++) {
        if (dist[i] == INF)
            cout << "INF "; // Se a distância é infinita (não alcançável)
        else
            cout << dist[i] << " "; // Caso contrário, imprime a distância
    }
    cout << endl;
    
    return 0;
}
