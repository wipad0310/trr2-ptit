#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#include<fstream>
#define ll long long
#define fr(z, zz, zzz) for(int z = zz; z <= zzz; z++)
#define frr(z, zz, zzz) for(int z = zz; z >= zzz; z--)
#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define TurnOnBit(i, x) ((x) | (1ll << (i)))
#define CheckBit(i, x) (((x) >> (i)) & 1)
#define IOS ios_base::sync_with_stdio(0);   cin.tie(0);     cout.tie(0);
using namespace std;
const int N = 1E2 + 5;
const ll MOD = 1E9 + 7;
const ll oo = 1E18 + 2;
fstream f, g;

int n, cnt = 0, ans = 0;
bool check[N];
vector<int> a[N];
vector<pii> b, res;

void OpenFile() {
    f.open("TK.INP", ios::in);
    g.open("TK.OUT", ios::out);
}

void CloseFile() {
    f.close();
    g.close();
}

void DFS(int u, int l, int r) {
    check[u] = 1;
    for(int v: a[u]) {
        if ((l == u && r == v) || (l == v && r == u))
            continue;
        if (!check[v])
            DFS(v, l, r);
    }
}

void CheckCP() {
    fr(i, 1, n) {
        if (!check[i]) {
            ++cnt;
            DFS(i, 0, 0);
        }
    }
}

int main() {
    IOS
    OpenFile();
    f >> n;
    fr(i, 1, n)
        fr(j, 1, n) {
            int x;
            f >> x;
            if (x) {
                b.pb({i, j});
                a[i].pb(j);
            }
        }
    CheckCP();
    
    for(pii x: b) {
        if (x.st > x.nd)
            continue;
        int num = 0;
        memset(check, 0, sizeof(check));
        fr(i, 1, n) {
            if (!check[i]) {
                ++num;
                DFS(i, x.st, x.nd);
            }
        }
        if (num > cnt)
            res.pb({x.st, x.nd});
    }
    g << res.size() << "\n";
    for(pii x: res)
        g << x.st << " " << x.nd << "\n";
    CloseFile();
}