#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N]; // Lista de adjacência
bool visited[N];    // Array para controlar os nós visitados

// Função de BFS (iterativa)
void bfs(int start) {
    queue<int> q; // Fila para processar os nós na ordem correta
    q.push(start);
    visited[start] = true; // Marca o nó inicial como visitado

    while (!q.empty()) {
        int v = q.front(); // Pega o primeiro nó da fila
        q.pop();           // Remove o nó da fila
        cout << v << " ";  // Processa o nó atual (imprime, mas pode ser alterado)

        // Percorre todos os vizinhos do nó `v`
        for (int u : adj[v]) {
            if (!visited[u]) {  // Se o nó ainda não foi visitado
                visited[u] = true; // Marca como visitado
                q.push(u); // Adiciona o nó na fila para ser processado depois
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    // Lendo as arestas do grafo
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(visited, false, sizeof(visited)); // Inicializa os visitados como `false`

    bfs(1); // Inicia a BFS a partir do nó 1

    return 0;
}

// O(N+M)
