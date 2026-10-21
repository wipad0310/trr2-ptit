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
vector<pii> res;
void Case_1() {
	f >> n;
	fr(i, 1, n) {
		f >> m;
		fr(j, 1, m) {
			int x;
			f >> x;
			++in[x];
			++out[i];
		}
	}
	fr(i, 1, n)
		g << in[i] << " " << out[i] << "\n";
}

void Case_2() {
	f >> n;
	fr(i, 1, n) {
		int k;
		f >> k;
		fr(j, 1, k) {
			int x;
			f >> x;
			res.pb({i, x});
		}
	}
	g << n << " " << res.size() << "\n";
	for(pii x: res)
		g << x.st << " " << x.nd << "\n";
}

int main() {
	IOS
	f.open("DT.INP", ios::in);
    g.open("DT.OUT", ios::out);
	f >> T;
	if (T == 1)
		Case_1();
	else
		Case_2();
	f.close();
    g.close();
}