#include <bits/stdc++.h>
using namespace std;

// Definindo int como int64_t para evitar overflow em números grandes
#define int int64_t

// Definindo o tamanho máximo para o array e a árvore de Fenwick
const int mxn = 1e5 + 10;

// Array para armazenar a Árvore de Fenwick (bit), o array original (a) e o tamanho n
int bit[mxn], a[mxn], n;

// Função para atualizar a Árvore de Fenwick (BIT) no índice i com o valor v
void upd(int i, int v) {
    // A atualização propaga o valor para os índices relevantes da BIT
    for (; i < n; i = i | (i + 1))  // A fórmula i = i | (i + 1) ajuda a localizar os índices superiores
        bit[i] = min(bit[i], v);  // Armazena o valor mínimo nos índices
}

// Função para consultar o mínimo dos elementos até o índice i
int qry(int i) {
    int ret = LLONG_MAX;  // Começamos com o maior valor possível
    for (; i >= 0; i = (i & (i + 1)) - 1)  // A fórmula i = (i & (i + 1)) - 1 ajuda a localizar os índices inferiores
        ret = min(ret, bit[i]);  // Mantém o valor mínimo encontrado
    return ret;
}

// Função para consultar o mínimo no intervalo [l, r]
int rqry(int l, int r) {
    return min(qry(r), (l > 0 ? qry(l - 1) : LLONG_MAX));  // Calcula o mínimo no intervalo
}

int32_t main() {
    // Lê o tamanho do array
    cin >> n;

    // Lê os elementos do array e inicializa a Árvore de Fenwick
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        upd(i, a[i]);  // Constrói a árvore de Fenwick com os valores iniciais
    }

    // Lê o número de consultas
    int q;
    cin >> q;

    // Processa cada consulta
    while (q--) {
        int tipo;
        cin >> tipo;  // Lê o tipo da consulta
        if (tipo == 1) {  // Tipo 1: Consulta mínimo no intervalo [l, r]
            int l, r;
            cin >> l >> r;
            cout << rqry(l, r) << '\n';  // Imprime o resultado da consulta de mínimo
        } else if (tipo == 2) {  // Tipo 2: Atualiza um elemento do array
            int i, novo_valor;
            cin >> i >> novo_valor;
            upd(i, novo_valor);  // Atualiza o valor no BIT
            a[i] = novo_valor;   // Atualiza o valor no array
        }
    }

    return 0;
}
