#include<iostream>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<fstream>
#include<unordered_set>
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
const int N =  1E2 + 4;
const ll MOD = 1E9 + 7;
const int oo = 1E9 + 2;
fstream f, g;
int n;
vector<int> a[N];
int par[N], sz[N];
unordered_set<int> se;
void Makeset() {
	fr(i, 1, n) {
		par[i] = i;
		sz[i] = 1;
	}
}

int Find(int x) {
	if (par[x] == x)
		return x;
	return par[x] = Find(par[x]);
}

void Union_Set(int a, int b) {
	a = Find(a);
	b = Find(b);
	if (a == b)
		return;
	if (sz[a] < sz[b])
		swap(a, b);
	par[b] = a;
	sz[a] += sz[b];
}

int main() {
	IOS
	f.open("TK.INP", ios::in);
    g.open("TK.OUT", ios::out);
    f >> n;
    Makeset();
    fr(i, 1, n)
    	fr(j, 1, n) {
    		int x;
    		f >> x;
    		if (x == 1 && i < j)
    			Union_Set(i, j);
    	}
    fr(i, 1, n)
    	se.insert(par[i]);
    g << se.size() << "\n";
    fr(i, 1, n) {
    	if (par[i])
    		g << i << " ";
    	else {
    		continue;
    	}
    	fr(j, 1, n) {
    		if (i == j)
    			continue;
    		if (par[i] != 0 && par[i] == par[j]) {
    			g << j << " ";
    			par[j] = 0;
    		}
    	}
    	g << "\n";
    }
	f.close();
    g.close();
}