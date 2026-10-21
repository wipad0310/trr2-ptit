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
int T, n, st, en, ans = 0;
vector<int> a[N];
bool check[N], flag = 0;
int par[N];

void DFS_1(int u, int cnt) {
	if (cnt > 2)
		return;
	for(int v: a[u]) {
		if (v == en && cnt + 1 == 2) {
			++ans;
			continue;
		}
		if (!check[v]) {
			check[v] = 1;
			DFS_1(v, cnt + 1);
		}
		check[v] = 0;
	}
}

void DFS_2(int u) {
	check[u] = 1;
	for(int v: a[u]) {
		if (!check[v]) {
			par[v] = u;
			if (v == en) {
				flag = 1;
				return;
			}
			DFS_2(v);
			if (flag)
				return;
		}
	}
}
void Tracking() {
	if (par[en] == 0) {
		g << 0;
		return;
	}
	vector<int> res;
	while(en != 0) {
		res.pb(en);
		en = par[en];
	}
	reverse(all(res));
	for(int x: res)
		g << x << " ";
}

void Case_1() {
	ans = 0;
	check[st] = 1;
	DFS_1(st, 0);
	g << ans;
	
}

void Case_2() {
	DFS_2(st);
	Tracking();
}

int main() {
	IOS
	f.open("TK.INP", ios::in);
    g.open("TK.OUT", ios::out);
	f >> T;
	f >> n >> st >> en;
	fr(i, 1, n)
		fr(j, 1, n) {
			int x;
			f >> x;
			if (x)
				a[i].pb(j);
		}
	if (T == 1)
		Case_1();
	else
		Case_2();
	f.close();
    g.close();
}