#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<stack>
#include<algorithm>
#include<fstream>
#define ll long long
#define fr(z, zz, zzz) for(int z = zz; z <= zzz; z++)
#define frr(z, zz, zzz) for(int z = zz; z >= zzz; z--)
#define all(a) (a).begin(), (a).end()
//#define st first
#define nd second
#define pii pair<int, int>
#define pb push_back
#define TurnOnBit(i, x) ((x) | (1ll << (i)))
#define CheckBit(i, x) (((x) >> (i)) & 1)
#define IOS ios_base::sync_with_stdio(0);   cin.tie(0);     cout.tie(0);
using namespace std;
const int N = 1E3 + 5;
const ll MOD = 1E9 + 7;
const ll oo = 1E18 + 2;
fstream f, g;

void OpenFile() {
    f.open("CT.INP", ios::in);
    g.open("CT.OUT", ios::out);
}

void CloseFile() {
    f.close();
    g.close();
}

int n, st, ans = 0;
int par[N];
vector<int> a[N], res;
int check[N];

void Tracing(int en) {
    res.clear();
    res.pb(st);
    while(en != 0) {
        res.pb(en);
        en = par[en];
    }
    reverse(all(res));
    for(int x: res)
        g << x << " ";
    g << "\n";
}

void DFS(int u, int cnt) {
    
    for(int v: a[u]) {
        if (cnt == n && v == st) {
            ++ans;
            Tracing(u);
        }
        if (!check[v]) {
            par[v] = u;
            check[v] = 1;
            DFS(v, cnt + 1);
            check[v] = 0;
        }
    }    
    
}

int main() {
    IOS
    OpenFile();
    f >> n >> st;
    fr(i, 1, n)
        fr(j, 1, n) {
            int x;
            f >> x;
            if (x) {
                a[i].pb(j); 
        }
    }
    check[st] = 1;
    DFS(st, 1);
    g << ans;
    CloseFile();
}