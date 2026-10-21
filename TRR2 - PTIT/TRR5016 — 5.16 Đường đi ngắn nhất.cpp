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
    f.open("DN.INP", ios::in);
    g.open("DN.OUT", ios::out);
}

void CloseFile() {
    f.close();
    g.close();
}

int n;
int a[N][N], par[N][N];

void FloyD() {
    fr(k, 1, n) {
        fr(u, 1, n) {
            if (u == k)
                continue;
            fr(v, 1, n) {
                if (u == v)
                    continue;
                if (a[u][v] > a[u][k] + a[k][v]) {
                    a[u][v] = a[u][k] + a[k][v];
                    par[u][v] = par[k][v];
                }
            }
        }
    }
}

void Trace() {
    int s, t, mx = 0;
    vector<int> res;
    fr(i, 1, n)
        fr(j, 1, n) {
            if (a[i][j] >= 10000)
                continue;
            if (mx < a[i][j]) {
                mx = a[i][j];
                s = i, t = j;
            }
        }
    if (mx == 0) {
        g << 0;
        return;
    }
    g << s << " " << t << " " << mx << "\n";
    res.pb(t);
    while(t != s) {
        res.pb(par[s][t]);
        t = par[s][t];
    }
    reverse(all(res));
    for(const int &x: res)
        g << x << " ";
    
}

int main() {
    IOS
    OpenFile();
    f >> n;
    fr(i, 1, n)
        fr(j, 1, n) {
            a[i][j] = oo;
            int x;
            f >> x;
            if (x != 0 && x != 10000) {
                par[i][j] = i;
                a[i][j] = x;
            }
            else
                par[i][j] = -1;
        }
        FloyD();
        Trace();
    CloseFile();
}