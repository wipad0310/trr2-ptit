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

int n, s, res = 0;
vector<pii> a[N];
vector<pair<pii, int>> li;
bool check[N];
void Prim(int i) {
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> q;
    q.push({0, {-1, i}});
    while(!q.empty()) {
        int u = q.top().nd.nd; 
        int par = q.top().nd.st;
        int curr_val = q.top().st;
        
        q.pop();
        if (check[u])
            continue;
        check[u] = 1;
        res += curr_val;
        if (par != -1)
            li.pb({{par, u}, curr_val});
        for(pii x: a[u]) {
            int v = x.nd,
                val = x.st;
            if (!check[v]) {
                q.push({val, {u, v}});
            }
        }
    }
}

int main() {
    IOS
    OpenFile();
    f >> n >> s;
    fr(i, 1, n)    
        fr(j, 1, n) {
            int x;
            f >> x;
            if (x != 0 && x != 10000)
                a[i].pb({x, j});
        }
    Prim(s);
    if (li.size() != n - 1) {
        g << 0;
        CloseFile();
        return 0;
    }
    g << res << "\n";
    for(pair<pii, int> x: li)
    g << min(x.st.st, x.st.nd) << " " << max(x.st.st, x.st.nd) << " " << x.nd << "\n";
    CloseFile();
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