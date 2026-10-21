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

int n;
bool check[N];
vector<int> a[N], aT[N], b[N];

void OpenFile() {
    f.open("TK.INP", ios::in);
    g.open("TK.OUT", ios::out);
}

void CloseFile() {
    f.close();
    g.close();
}

void BFS(int i, vector<int> d[], int &cnt) {
    check[i] = 1;
    cnt = 1;
    queue<int> q;
    q.push(i);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v: d[u]) {
            if (!check[v]) {
                check[v] = 1;
                ++cnt;
                q.push(v);
            }
        }
    }
}

bool Check_SCC() {
    int cnt = 0, r_cnt = 0;
    memset(check, 0, sizeof(check));
    BFS(1, a, cnt);
    memset(check, 0, sizeof(check));
    BFS(1, aT, r_cnt);
    if (cnt == r_cnt)
        return true;
    return false;
}

bool Check_WCC() {
    memset(check, 0, sizeof(check));
    int cnt = 0, trash = 0;
    fr(i, 1, n) {
        if (!check[i]) {
            ++cnt;
            if (cnt > 1)
                return false;
            BFS(i, b, trash);
        }
    }
    if (cnt != 1)
        return false;
    return true;
}

int main() {
    IOS
    OpenFile();
    f >> n;
    fr(i, 1, n)
        fr(j, 1, n) {
            int x;
            f >> x;
            if (x == 1) {
                a[i].pb(j);
                aT[j].pb(i);
                b[i].pb(j);
                b[j].pb(i);
            }
        }
    if (Check_SCC())
        g << "1";
    else {
        if (Check_WCC)
            g << 2;
        else
            g << 0;
    }
    CloseFile();
}