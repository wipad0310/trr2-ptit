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
    f.open("CK.INP", ios::in);
    g.open("CK.OUT", ios::out);
}

void CloseFile() {
    f.close();
    g.close();
}

struct edge {
    int first, second, val;
    bool operator<(const edge &other) const {
        return val < other.val;
    }
};
int n, m, sum = 0;
int par[N], sz[N];
vector<edge> a;
vector<edge> res;

void MakeSet() {
    fr(i, 1, n) {
        par[i] = i;
        sz[i] = 1;
    }
}

int Find(int x) {
    if (par[x] == x)
        return x;
    return par[x] = Find(par[x]);
}

void Union(edge x) {
    int a = x.st,
        b = x.nd,
        v = x.val;
    a = Find(a);
    b = Find(b);
    if (a == b)
        return;
    sum += v;
    res.pb(x);
    if (sz[a] < sz[b])
        swap(a, b);
    sz[a] += sz[b];
    par[b] = a; 
}

int main() {
    IOS
    OpenFile();
    f >> n >> m;
    MakeSet();
    fr(i, 1, m) {
        int x, y, z;
        f >> x >> y >> z;
        a.pb({x, y, z});
    }
    stable_sort(all(a));
    for(edge i: a) 
        Union(i);
    if (res.size() != n - 1) {
        g << 0;
        CloseFile();
        return 0;
    }
    g << sum << "\n";
    for(edge x: res)
        g << min(x.st, x.nd) << " " << max(x.st, x.nd) << " " << x.val << "\n";
    CloseFile();
    return 0;
}