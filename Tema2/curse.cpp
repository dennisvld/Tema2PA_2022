#include <bits/stdc++.h>
using namespace std;

ifstream fin("curse.in");
ofstream fout("curse.out");

const int DIM = 1e5 + 5;

int N, M, A;
int mat[DIM][22];
vector<int> adj[DIM];

void dfs(int node, bool used[], vector<int> &topsort) {
    used[node] = true;

    for (int neigh : adj[node]) {
        if (!used[neigh]) {
            dfs(neigh, used, topsort);
        }
    }

    topsort.push_back(node);
}

vector<int> solveDfs() {
    vector<int> topsort;
    // grad intern
    int grad[M + 1];
    bool used[M + 1];
    memset(used, false, sizeof(used));
    memset(grad, 0, sizeof(grad));
    for (int node = 1; node <= M; node++)
        for (int neigh : adj[node])
            grad[neigh]++;

    for (int node = 1; node <= M; node++) {
        if (grad[node] == 0) {
            dfs(node, used, topsort);
        }
    }

    reverse(topsort.begin(), topsort.end());
    return topsort;
}

int main() {
    fin >> N >> M >> A;
    for (int i = 1; i <= A; i++) {
        for (int j = 1; j <= N; j++) {
            fin >> mat[i][j];
        }
    }

    for (int i = 1; i < A; i++) {
        for (int j = 1; j <= N; j++) {
            if (mat[i][j] != mat[i + 1][j]) {
                adj[ mat[i][j] ].push_back(mat[i + 1][j]);
                break;
            }
        }
    }

    vector<int> topsort = solveDfs();
    for (int i = 0; i < M; i++)
        fout << topsort[i] << " ";
    return 0;
}
