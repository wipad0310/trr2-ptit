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
    f.open("TK.INP", ios::in);
    g.open("TK.OUT", ios::out);
}

void CloseFile() {
    f.close();
    g.close();
}

int n;
vector<int> a[N], aT[N], una[N];
bool check[N];

void BFS(vector<int> a[], int &cnt) {
    queue<int> q;
    check[1] = 1;
    q.push(1);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(const int &v: a[u]) {
            if (!check[v]) {
                check[v] = 1;
                ++cnt;
                q.push(v);
            }
        }
    }
}

bool Check_SCC() {
    int cnt = 1, r_cnt = 1;
    memset(check, 0, sizeof(check));
    BFS(a, cnt);
    memset(check, 0, sizeof(check));
    BFS(aT, r_cnt);
    if (cnt == r_cnt && cnt == n)
        return true;
    return false;
}

bool Check_CC() {
    int cnt = 1;
    memset(check, 0, sizeof(check));
    BFS(una, cnt);
    if (cnt == n)
        return true;
    return false;
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
                a[i].pb(j);
                aT[j].pb(i);
                una[i].pb(j);
                una[j].pb(i);
            }
        }
    if (Check_SCC())
        g << 1;
    else if (Check_CC())
        g << 2;
    else
        g << 0;
    CloseFile();
}

