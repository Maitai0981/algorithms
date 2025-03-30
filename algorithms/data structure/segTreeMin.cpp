#include <bits/stdc++.h>
using namespace std;

#define int int64_t

const int mxn = 1e5 + 10;  // Definindo o tamanho máximo do array
int segtree[4 * mxn], a[mxn], n;

// Função para construir a Segment Tree
void build(int node, int start, int end) {
    if (start == end) {
        // Quando a posição é uma folha, coloca o valor do array
        segtree[node] = a[start];
    } else {
        int mid = (start + end) / 2;
        // Recursivamente construa as árvores à esquerda e direita
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        // Calcula o valor para o nó atual como o mínimo entre os filhos
        segtree[node] = min(segtree[2 * node], segtree[2 * node + 1]);
    }
}

// Função para atualizar um elemento do array na Segment Tree
void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
        // Atualiza o valor na folha
        a[idx] = val;
        segtree[node] = val;
    } else {
        int mid = (start + end) / 2;
        if (idx <= mid) {
            // Se o índice estiver na metade esquerda, atualiza o nó esquerdo
            update(2 * node, start, mid, idx, val);
        } else {
            // Se o índice estiver na metade direita, atualiza o nó direito
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        // Após a atualização, recalcula o valor do nó atual
        segtree[node] = min(segtree[2 * node], segtree[2 * node + 1]);
    }
}

// Função para consultar o mínimo no intervalo [l, r]
int query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) {
        // Intervalo fora da faixa, retorna um valor "mais infinito" para não afetar a consulta
        return LLONG_MAX;
    }
    if (l <= start && end <= r) {
        // Se o intervalo atual está dentro do intervalo consultado, retorna o valor do nó
        return segtree[node];
    }
    // Caso contrário, divide a consulta nas duas metades
    int mid = (start + end) / 2;
    int left = query(2 * node, start, mid, l, r);
    int right = query(2 * node + 1, mid + 1, end, l, r);
    // Retorna o mínimo entre as duas consultas
    return min(left, right);
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);  // Para otimizar a entrada e saída

    // Lê o tamanho do array
    cin >> n;

    // Lê os elementos do array
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Construa a Segment Tree
    build(1, 0, n - 1);

    // Lê o número de consultas
    int q;
    cin >> q;

    while (q--) {
        int tipo;
        cin >> tipo;  // Lê o tipo da consulta
        if (tipo == 1) {  // Tipo 1: Consulta o mínimo no intervalo [l, r]
            int l, r;
            cin >> l >> r;
            cout << query(1, 0, n - 1, l, r) << '\n';  // Imprime o resultado da consulta
        } else if (tipo == 2) {  // Tipo 2: Atualiza um elemento do array
            int i, novo_valor;
            cin >> i >> novo_valor;
            update(1, 0, n - 1, i, novo_valor);  // Atualiza o valor na Segment Tree
        }
    }

    return 0;
}
