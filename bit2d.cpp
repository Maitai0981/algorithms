#include <bits/stdc++.h>
using namespace std;

const int N = 1005; // Tamanho máximo da matriz
int bit[N][N]; // BIT 2D armazenando as somas parciais
int n, m; // Dimensões da matriz

// Atualiza a posição (x, y) adicionando 'val'
void update(int x, int y, int val) {
    for (int i = x; i <= n; i += (i & -i)) {
        for (int j = y; j <= m; j += (j & -j)) {
            bit[i][j] += val; // Propaga a atualização para os nós superiores
        }
    }
}

// Retorna a soma da submatriz de (1,1) até (x,y)
int query(int x, int y) {
    int sum = 0;
    for (int i = x; i > 0; i -= (i & -i)) {
        for (int j = y; j > 0; j -= (j & -j)) {
            sum += bit[i][j]; // Acumula as contribuições das células responsáveis
        }
    }
    return sum;
}

// Retorna a soma da submatriz (x1, y1) → (x2, y2)
int sum(int x1, int y1, int x2, int y2) {
    return query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
}

int main() {
    cin >> n >> m; // Lê as dimensões da matriz

    int q;
    cin >> q; // Número de operações

    while (q--) {
        int op;
        cin >> op; // Tipo de operação (1 = update, 2 = sum)

        if (op == 1) { // Atualizar valor
            int x, y, val;
            cin >> x >> y >> val;
            update(x, y, val);
        } else if (op == 2) { // Consultar soma de uma submatriz
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            cout << sum(x1, y1, x2, y2) << endl;
        }
    }

    return 0;
}
