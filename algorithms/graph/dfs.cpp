#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;  // Número máximo de vértices (ajuste conforme necessário)
vector<int> adj[N];      // Lista de adjacência para armazenar o grafo
bool visited[N];         // Array para marcar os nós visitados

// Função de DFS (recursiva)
void dfs(int v) {
    visited[v] = true; // Marca o nó como visitado
    cout << v << " ";  // Processa o nó atual (imprime, mas pode ser alterado conforme necessário)

    // Percorre todos os vizinhos do nó `v`
    for (int u : adj[v]) {
        if (!visited[u]) { // Se o nó ainda não foi visitado, chama DFS recursivamente
            dfs(u);
        }
    }
}

int main() {
    int n, m;  // `n` = número de vértices, `m` = número de arestas
    cin >> n >> m;

    // Lendo as arestas do grafo
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // Adiciona `v` na lista de adjacência de `u`
        adj[v].push_back(u); // Adiciona `u` na lista de adjacência de `v` (para grafos não direcionados)
    }

    memset(visited, false, sizeof(visited)); // Inicializa o array de visitados como `false`

    dfs(1); // Inicia a DFS a partir do nó 1 (ou qualquer outro nó de interesse)

    return 0;
}

// O(N+M)