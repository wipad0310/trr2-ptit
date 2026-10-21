#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<fstream>
#define ll long long
#define fr(z, zz, zzz) for(int z = zz; z <= zzz; z++)
#define frr(z, zz, zzz) for(int z = zz; z >= zzz; z--)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define st first
#define nd second
#define pii pair<int, int>
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int N =  1E3 + 4;
const ll MOD = 1E9 + 7;
const int oo = 1E9 + 2;

fstream f, g;
int T, n, m;
int in[N], out[N];
vector<pair<pii, int>> a;
int res[N][N];
void Case_1() {
	for(pair<pii, int> x: a) {
		++in[x.st.nd];
		++out[x.st.st];
	}
	fr(i, 1, n)
		g << in[i] << " " << out[i] << "\n";
}

void Case_2() {
	for(pair<pii, int> x: a) {
		res[x.st.st][x.st.nd] = x.nd;
	}
	fr(i, 1, n)
		fr(j, 1, m) {
			if (res[i][j] == 0 && i != j)
				res[i][j] = 10000;
		}
	g << n << "\n";
	fr(i, 1, n) {
		fr(j, 1, n)
			g << res[i][j] << " ";
		g << "\n";
	}

}

int main() {
	IOS
	f.open("DT.INP", ios::in);
    g.open("DT.OUT", ios::out);
	f >> T;
	f >> n >> m;
	fr(i, 1, m) {
		int x, y, z;
		f >> x >> y >> z;
		a.pb({{x, y}, z});
	}
	if (T == 1)
		Case_1();
	else
		Case_2();
	f.close();
    g.close();
}