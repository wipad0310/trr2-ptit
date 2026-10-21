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

int n, T;
int a[N][N];
fstream f, g;

void Case_1() {
    int res[N] = {0};
    fr(i, 1, n)
        fr(j, 1, n) {
            if (j > i) {
                if (a[i][j] != 0 && a[i][j] != 10000) {
                    ++res[i];
                    ++res[j];
                }
            }
        }
        fr(i, 1, n)
            g << res[i] << " ";
}

void Case_2() {
   vector<pair<pii, int>> res;
    fr(i, 1, n)
        fr(j, 1, n) {
            if (j > i) {
                if (a[i][j] != 0 && a[i][j] != 10000) {
                    res.push_back({{i, j}, a[i][j]});
                }
            }
        }
    g << n << " " << res.size() << "\n";
    for(pair<pii, int> x: res)
        g << x.st.st << " " << x.st.nd << " " << x.nd << "\n";
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