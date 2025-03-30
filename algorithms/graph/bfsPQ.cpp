#include <bits/stdc++.h>
using namespace std;

#define PQ priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> 

const int N = 1e5 + 5;  // Número máximo de vértices
vector<pair<int, int>> adj[N];  // Lista de adjacência com pesos
bool visited[N];  // Array de visitados


void bfs(int start) {
    PQ pq;  // Fila de prioridade

    pq.push({start, 0});  // Inicializa com o nó de partida e sua prioridade
    visited[start] = true;

    while (!pq.empty()) {
        // Pega o nó com a menor prioridade
        int v = pq.top().first;
        int priority = pq.top().second;
        pq.pop();

        cout << v << " ";  // Processa o nó (imprime ou faz outra operação)

        // Percorre todos os vizinhos
        for (auto& edge : adj[v]) {
            int u = edge.first;
            int weight = edge.second;

            if (!visited[u]) {
                visited[u] = true;
                pq.push({u, priority + weight});  // Adiciona o vizinho na fila com a nova prioridade
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);  // Desativa a sincronização com o C
    cin.tie(0);  // Desativa o "tie" com o `cout`, melhorando a performance

    int n, m;
    cin >> n >> m;

    // Lendo as arestas
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});  // Para grafo não direcionado
    }

    memset(visited, false, sizeof(visited));  // Inicializa os visitados

    bfs(1);  // Começa a busca a partir do nó 1

    return 0;
}
