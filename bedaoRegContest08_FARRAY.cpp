/*Good luck for those who are trying your best
May the most glorious victory come*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define vi vector<int>
#define vvi vector< vector<int> >
#define endl '\n'


int const rvMod = 985416512;
int const mod = 1058375681;

int sqr(int a) {
	return a * a;
}
int sqrmod(int n) {
	if(n == 0) return 1;
	if(n == 1) return 2;
	if(n % 2 == 0) return sqr(sqrmod(n/2)) % mod;
	else return 2 * sqr(sqrmod(n/2)) % mod;
}
int f(int n) {
	if(n % 2 == 0) {
		return (sqrmod(n) - 1) * rvMod % mod;
	} else return (sqrmod(n) + 1) * rvMod % mod;	
}

int n, q, t, l, r, k;
int const maxn  = 1e5 + 5;
int FenTree[4*maxn], a[maxn + 5];

void updatePoint(int u, int val) {
	int idx = u;
	while(u <= n) {
		FenTree[idx] += 
	}
}

void buildFenTree(int id, int l, int r) {

}
void solve() {
	cin >> n >> q;
	buildFenTree(1, 1, n);

	for(int i = 0; i < q; i++) {
		cin >> type;
		if(type == 1) {
			cin >> l >> r >> k;
		}
		else {
			cin >> l >> r;
			cout << get();
		}
	}

}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}