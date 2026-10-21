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

int n, T, m;
fstream f, g;

void Case_1() {
    vector<int> a[N];
    fr(i, 1, m) {
        int x, y;
        f >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    fr(i, 1, n)
        g << a[i].size() << " ";

}


void Case_2() {
    int a[N][N];    
    fr(i, 1, m) {
        int x, y;
        f >> x >> y;
        a[x][i] = 1;
        a[y][i] = 1;
    }
    g << n << " " << m << "\n";
    fr(i, 1, n) {
        fr(j, 1, m)
            g << a[i][j] << ' ';
        g << "\n";
    }   
    
}
int main() {
    IOS
    f.open("DT.INP", ios::in);
    g.open("DT.OUT", ios::out);
    f >> T >> n >> m;
    if (T == 1)
        Case_1();
    else
        Case_2();
    f.close();
    g.close();
}