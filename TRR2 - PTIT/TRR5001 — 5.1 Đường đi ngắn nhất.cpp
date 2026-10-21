#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include<iostream>
#include<utility>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<fstream>
#define ll long long
#define fr(z, zz, zzz) for(int z = zz; z <= zzz; z++)
#define frr(z, zz, zzz) for(int z = zz; z >= zzz; z--)
#define all(a) (a).begin(), (a).end()
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define TurnOnBit(i, x) ((x) | (1ll << (i)))
#define CheckBit(i, x) (((x) >> (i)) & 1)
#define IOS ios_base::sync_with_stdio(0);   cin.tie(0);     cout.tie(0);
using namespace std;
const int N = 1E3 + 5;
const ll MOD = 1E9 + 7;
const int oo = 1E9 + 2;
fstream f, g;
void OpenFile() {
    f.open("DN.INP", ios::in);
    g.open("DN.OUT", ios::out);
}

void CloseFile() {
    f.close();
    g.close();
}

int n, s, t;
int d[N], par[N];
vector<pii> a[N];
vector<int> res;

void Dijkstra(int i) {
    priority_queue<pii, vector<pii>, greater<pii>> q;
    d[i] = 0;
    par[i] = 0;
    q.push({0, i});
    while(!q.empty()) {
        int u = q.top().nd,
            dis = q.top().st;
        q.pop();
        if (d[u] < dis)
            continue;
        for(pii x: a[u]) {
            int v = x.nd,
                val = x.st;
            if (d[u] + val < d[v]) {
                d[v] = d[u] + val;
                par[v] = u;
                q.push({d[v], v});
            }
        }
    }
}

void Tracing() {
    while(t != 0) {
        res.pb(t);
        t = par[t];
    }
    reverse(all(res));
}

int main() {
    IOS
    OpenFile();
    memset(d, 0x3f, sizeof(d));
    f >> n >> s >> t;
    fr(i, 1, n)
        fr(j, 1, n) {
            int x;
            f >> x;
            if (x != 0 && x != 10000)
                a[i].pb({x, j});
        }
    Dijkstra(s);
    if (d[t] > 10000) {
        g << 0;
        CloseFile();
        return 0;
    }
    g << d[t] << "\n";
    Tracing();
    for(int x: res)
        g << x << " ";
    CloseFile();
    return 0;
}