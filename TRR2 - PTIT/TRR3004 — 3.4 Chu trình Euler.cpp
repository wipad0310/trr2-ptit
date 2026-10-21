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

int T, n, st, en = 0;
vector<int> a[N], res;
int in[N], out[N], par[N], sz[N];
bool mark[N][N];


void Hierholzer(int u) {
    for(int v: a[u]) {
        if (!mark[u][v]) {
            mark[u][v] = 1;
            par[v] = u;
            Hierholzer(v);
        }
    }
    res.pb(u);
}

bool Check_Euler() {
    fr(i, 1, n)
        if (in[i] != out[i])
            return false;
    return true;
}

void MakeSet() {
    fr(i, 1, n) {
        par[i] = i;
        sz[i] = 1;
    }
}

int Find(int x) {
    if (x == par[x])
        return x;
    return par[x] = Find(par[x]);
}

void DSU(int a, int b) {
    a = Find(a);
    b = Find(b);
    if (a == b)
        return;
    if (sz[a] < sz[b])
        swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
}

bool Check_Half_Euler() {
    MakeSet();
    fr(i, 1, n)
        for(int x: a[i])
            DSU(i, x);
    fr(i, 2, n)
        if (par[i] != par[1])
            return false;
    return true;
}

void Case_1() {
    if (Check_Euler())
        g << 1;
    else if (Check_Half_Euler())
        g << 2;
    else
        g << 0;
}

void Case_2() {
    Hierholzer(st);
    reverse(all(res));
    for(int x: res)
        g << x << " ";
}

int main() {
    IOS
    OpenFile();
    f >> T >> n;
    if (T == 2)
        f >> st;
    fr(i, 1, n)
        fr(j, 1, n) {
            int x;
            f >> x;
            if (x) {
                ++out[i];
                ++in[j];
                a[i].pb(j);
            }
        }
    if (T == 1)
        Case_1();
    else
        Case_2();
    CloseFile();
}