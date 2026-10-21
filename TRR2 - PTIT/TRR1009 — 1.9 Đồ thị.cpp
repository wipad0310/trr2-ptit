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
        int m;
        cin >> m;
        fr(j, 1, m) {
            int x;
            cin >> x;
        }
        cout << m << " ";
    }

}


void Case_2() {
    int cnt = 0;
    int a[N][N];
    vector<pii> res;
    fr(i, 1, n) {
        int t;
        cin >> t;
        fr(j, 1, t) {
            int x;
            cin >> x;
            if (i < x) {
                a[i][++cnt] = 1;
                a[x][cnt] = 1;
            }
        }
    }
    cout << n << " " << cnt << "\n";
    fr(i, 1, n) {
        fr(j, 1, cnt)
            cout << a[i][j] << " ";
        cout << "\n";
    }
    
}
int main() {
    IOS
    f.open("DT.INP", ios::in);
    g.open("DT.OUT", ios::out);
    cin >> T >> n;
    if (T == 1)
        Case_1();
    else
        Case_2();
    f.close();
    g.close();
}