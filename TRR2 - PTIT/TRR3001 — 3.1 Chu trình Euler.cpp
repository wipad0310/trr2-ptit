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
const int N = 1E2 + 5;
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
bool check[N], mark[N][N];


void DFS(int u) {
    check[u] = 1;
    for(int v: a[u]) {
        if (!check[v]) {
            
            DFS(v);

        }
    }
}
bool CheckCP() {
    int cnt = 0;
    fr(i, 1, n) {
        if (a[i].size() == 0)
            continue;
        if (!check[i]) {
            ++cnt;
            DFS(i);
            if (cnt > 1)
                break;
        }
    }
    return cnt == 1;
}
void Case_1() {
    memset(check, 0, sizeof(check));
    int odd = 0;
    if (!CheckCP()) {
        g << "0";
        return;
    }
    fr(i, 1, n) {
        if (a[i].size() &1)
            ++odd;
        if (odd > 2)
            break;
    }
    
    if (odd == 0) {
        g << 1;
    }
    else if (odd == 2)
        g << 2;
    else {
        g << 0;
    }
}


void Hier_Holzer(int u) {
    for(int v: a[u]) {
        if (!mark[u][v]) {
            mark[u][v] = 1;
            mark[v][u] = 1;
            Hier_Holzer(v);
        }   
    }
    res.pb(u);
}

void Case_2() {
    memset(mark, 0, sizeof(mark));
    Hier_Holzer(st);
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
            if (x)
                a[i].pb(j);
        }
    if (T == 1)
        Case_1();
    else
        Case_2();
    CloseFile();
}