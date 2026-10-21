
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

int n, T;
fstream f, g;

void Case_1() {
    vector<int> a[N];
    fr(i, 1, n) {
        fr(j, 1, n) {
            int x;
            f >> x;
            if (x == 1)
            a[i].push_back(j);
        }
    }
    fr(i, 1, n) {
        g << a[i].size() << " ";
    }
}


void Case_2() {
    int check[N][N];
    vector<int> a[N];
    fr(i, 1, n) 
        fr(j, 1, n) {
            int x;
            f >> x;
            if (x == 1) {
                a[i].push_back(j);
            }
        }
    g << n << "\n";
    fr(i, 1, n) {
        g << a[i].size() << " ";
        for(int x: a[i])
            g << x << " ";
        g << "\n";
    }

}
int main() {
    IOS
    f.open("DT.INP", ios::in);
    g.open("DT.OUT", ios::out);
    f >> T >> n;
    if (T == 1)
        Case_1();
    else
        Case_2();
    f.close();
    g.close();
}