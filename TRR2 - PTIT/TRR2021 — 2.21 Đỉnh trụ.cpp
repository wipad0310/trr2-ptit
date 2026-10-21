#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

const int N = 105;
int n;
int a[N][N];
bool visited[N];

void DFS(int u, int removed_node) {
    visited[u] = true;
    for (int v = 1; v <= n; ++v) {
        if (a[u][v] && !visited[v] && v != removed_node) {
            DFS(v, removed_node);
        }
    }
}

int countComponents(int removed_node) {
    for (int i = 1; i <= n; ++i) visited[i] = false;
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (i == removed_node) continue;
        if (!visited[i]) {
            ++cnt;
            DFS(i, removed_node);
        }
    }
    return cnt;
}

int main() {
    ifstream fin("TK.INP");
    ofstream fout("TK.OUT");

    fin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            fin >> a[i][j];
        }
    }
    int baseComponents = countComponents(-1);
    vector<int> cut_vertices;

    for (int i = 1; i <= n; ++i) {
        if (countComponents(i) > baseComponents) {
            cut_vertices.push_back(i);
        }
    }

    fout << cut_vertices.size() << "\n";
    for (int u : cut_vertices) {
        fout << u << " ";
    }
    fout << "\n";

    fin.close();
    fout.close();
    return 0;
}