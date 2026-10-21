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
const ll oo = 1E18 + 2;
fstream f, g;
void OpenFile() {
    f.open("CK.INP", ios::in);
    g.open("CK.OUT", ios::out);
}

void CloseFile() {
    f.close();
    g.close();
}

int T, n, fst, ans = 0;
vector<int> a[N];
vector<pii> res;
bool check[N];

void DFS(int u) {
    for(int v: a[u]) {
        if (!check[v]) {
            // Luon giu thu tu u < v
            res.pb({min(u, v), max(u, v)});
            check[v] = 1;
            DFS(v);
        }
    }
}

void Case_1() {
    check[fst] = 1;
    DFS(fst);
    ans = res.size();
    if (ans != n - 1) {
        g << "0";
        return;
    }
    g << ans << "\n";
    for(pii x: res)
        g << x.st << " " << x.nd << "\n";
}

void BFS(int i) {
    queue<int> q;
    q.push(i);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int v: a[u]) {
            if (!check[v]) {
                res.pb({min(u, v), max(u, v)});
                check[v] = 1;
                q.push(v);
            }
        }
    }
}

void Case_2() {
    check[fst] = 1;
    BFS(fst);
    ans = res.size();
    if (ans != n - 1) {
        g << "0";
        return;
    }
    g << ans << "\n";
    for(pii x: res)
        g << x.st << " " << x.nd << "\n";
}


void Input() {
    f >> T;
    f >> n >> fst;
    fr(i, 1, n) 
        fr(j, 1, n) {
            int x;
            f >> x;
            if (x)
                a[i].pb(j);
        }
}

int main() {
    IOS
    OpenFile();
    Input();
    memset(check, 0, sizeof(check));
    if (T == 1)
        Case_1();
    else
        Case_2();
    CloseFile();
    return 0;
}


/*
Cây khung
Tính chất:
- Số đỉnh của cây khung = số đỉnh của đồ thị ban đầu
- Số cạnh = số đỉnh - 1
- Không tồn tại chu trình
- Liên thông với nhau
- Giữa 2 đỉnh chỉ có 1 đường đi duy nhất
- Thêm 1 cạnh tạo ra đúng 1 chu trình
*/