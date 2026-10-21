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
const int N = 1E2 + 5;

int T, n, m;
int a[N][N];
int b[N][2] = {0};
vector<pii> res;
fstream f, g;

void Case_1() {
    fr(i, 1, n)
        fr(j, 1, n) {
            if (a[i][j] == 1) {
                ++b[i][1];
                ++b[j][0];
            }
        }
    fr(i, 1, n)
        g << b[i][0] << " " << b[i][1] << "\n";
}

void Case_2() {
    fr(i, 1, n)
        fr(j, 1, n) {
            if (a[i][j] == 1)
                res.push_back({i, j});
        }
    g << n << " " << res.size() << "\n";
    for(pii x: res)
        g << x.st << " " << x.nd << "\n";
}
int main() {
    IOS
    f.open("DT.INP", ios::in);
    g.open("DT.OUT", ios::out);
    f >> T >> n;
    fr(i, 1, n)
        fr(j, 1, n)
            f >> a[i][j];
    if (T == 1)
        Case_1();
    else
        Case_2();
    f.close();
    g.close();
}