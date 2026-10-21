#include<iostream>
#include<cstring>
#include<vector>
#include<unordered_set>
#include<algorithm>
#include<fstream>
#define ll long long
#define fr(z, zz, zzz) for(int z = zz; z <= zzz; z++)
#define frr(z, zz, zzz) for(int z = zz; z >= zzz; z--)
#define st first
#define nd second
#define pii pair<int, int>
#define pll pair<long long, long long>
#define IOS ios_base::sync_with_stdio(0);   cin.tie(0);     cout.tie(0);
#define Mask(i) (1ll << (i))
#define Bit(x, i) (((x) >> (i)) & 1)
using namespace std;
const int N = 1E3 + 5;

int T, n, m;
int b[N][N];
vector<pii> a[N];
fstream f, g;

void Case_1() {
    int res[N] = {0};
    fr(i, 1, m) {
        for(pii x: a[i]) {
            ++res[i];
            ++res[x.st];
        }
    }
    fr(i, 1, n)
        g << res[i] << " ";
}

void Case_2() {
   g << n << "\n";
   fr(i, 1, m) {
        for(pii x: a[i]) {
            b[i][x.st] = x.nd;
            b[x.st][i] = x.nd;
        }
    }
    fr(i, 1, n)
        fr(j, 1, n) {
            if (i == j)
                b[i][j] = 0;
            else if (b[i][j] == 0 && i != j)
                b[i][j] = 10000;
        }
    fr(i, 1, n) {
        fr(j, 1, n)
            g << b[i][j] << " ";
        g << "\n";
    }
}
int main() {
    IOS
    f.open("DT.INP", ios::in);
    g.open("DT.OUT", ios::out);
    f >> T >> n >> m;
    fr(i, 1, m) {
        int x, y, z;
        f >> x >> y >> z;
        a[x].push_back({y, z});
    }
    if (T == 1)
        Case_1();
    else
        Case_2();
    f.close();
    g.close();
}