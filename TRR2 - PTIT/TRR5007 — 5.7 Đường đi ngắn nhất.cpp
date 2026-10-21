#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include<iostream>
#include<tuple>
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
    f.open("BN.INP", ios::in);
    g.open("BN.OUT", ios::out);
}

void CloseFile() {
    f.close();
    g.close();
}

int T, n, s, t, m = 0;
int d[N], par[N];
tuple<int, int, int> a[N];
bool isUpdated = 0;
bool isNegative = 0;
void Bellman_Ford() {
    fr(i, 1, n - 1) {
        fr(j, 1, m) {
            int u = get<0>(a[j]),
                v = get<1>(a[j]),
                val = get<2>(a[j]);
            if (d[u] != oo && d[u] + val < d[v]) {
                d[v] = d[u] + val;
                par[v] = u;
                isUpdated = 1;
            }
        }
    if (!isUpdated)
        break;
    }    


    fr(j, 1, m) {
        int u = get<0>(a[j]),
            v = get<1>(a[j]),
            val = get<2>(a[j]);

        if (d[u] != oo && d[u] + val < d[v]) {
            isNegative = 1;
            return;
        }
    }
}

void Trace() {
    vector<int> res;
    while(t != -1) {
        res.pb(t);
        t = par[t];
    }
    reverse(all(res));
    for(const int &x: res)
        g << x << " ";  
}

int main() {
    IOS
    OpenFile();
    f >> n >> s >> t;
    fill(d, d + n + 1, oo);
    d[s] = 0;
    par[s] = -1;
    fr(i, 1, n)
        fr(j, 1, n) {
            int x;
            f >> x;
            if (x != 0 && x != 10000)
                a[++m] = {i, j, x};
        }
        Bellman_Ford();
        if (d[t] == oo)
            g << 0;
        else if (isNegative)
            g << -1;
        else {
            g << d[t] << "\n";
            Trace();
        }
    CloseFile();
}