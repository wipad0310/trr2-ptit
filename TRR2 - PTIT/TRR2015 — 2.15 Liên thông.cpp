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

int n, cnt = 0, r_cnt = 0;
vector<int> a[N], aT[N], c[N];
bool check[N], is_connected = 1;
stack<int> st;

void OpenFile(const string &name) {
    f.open(name + ".INP", ios::in);
    g.open(name + ".OUT", ios::out);
}

void CloseFile() {
    f.close();
    g.close();
}


void DFS(int u) {
    for(int v: c[u]) {
        if (!check[v]) {
            check[v] = 1;
            DFS(v);
        }
    }
}

void DFS_1(int u) {
    for(int v: a[u]) {
        if (!check[v]) {
            ++cnt;
            check[v] = 1;
            DFS_1(v);
        }
    }
}

void DFS_2(int u) {
    for(int v: aT[u]) {
        if (!check[v]) {
            ++r_cnt;
            check[v] = 1;
            DFS_2(v);
        }
    }
}

bool Check_UCC() {
    int res = 0;
    memset(check, 0, sizeof(check));
    fr(i, 1, n)
        if (!check[i]) {
            check[i] = 1;
            ++res;
            if (res > 1)
                return false;
            DFS(i);
        }
    if (res != 1)
        return false;
    return true;
}

short Check_SCC() {
    if (n == 1)
        return 1;
    int x;
    cnt = 0, r_cnt = 0;
    fr(i, 1, n) 
        if (a[i].size() != 0) {
            x = i;
            break;
        }
    memset(check, 0 ,sizeof(check));
    DFS_1(x);
    memset(check, 0, sizeof(check));
    DFS_2(x);
    if (cnt == r_cnt)
        return 1;
    else
        return 2;
    return 4;
}

int main() {
    IOS
    OpenFile("TK");
    f >> n;
    fr(i, 1, n)
        fr(j, 1, n) {
            int x;
            f >> x;
            if (x == 1) {
                a[i].pb(j);
                aT[j].pb(i);
                c[i].pb(j);
                c[j].pb(i);

            }
        }
    if (!Check_UCC())
        g << "0";
    else
        g << Check_SCC();

}