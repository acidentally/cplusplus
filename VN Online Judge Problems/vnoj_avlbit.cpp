/*
Good luck for those who are trying your best
May the most glorious victory come
Code by : acident / lckintrovert
Literally the worst cp-er ever
*/

#include <bits/stdc++.h>
using namespace std;

#define int 			long long
#define uint 			unsigned long long
#define dub 			double
#define fi				first
#define se 				second
#define vvi 			vector< vector<int> >
#define endl 			'\n'
#define pb 				emplace_back
#define pf 				push_front
#define all(a) 			a.begin(), a.end()
#define mp 				make_pair
#define YES 			cout<<"YES\n";
#define NO 				cout<<"NO\n";
#define ins 			insert

typedef vector<int> 	vi;
typedef pair<int, int> 	pi;
typedef pair<int, pi> 	pii;
int const mod 		= 	1e9 + 7;

int const maxn 		= 	1e5; 
int const INF 		= 	LLONG_MAX;

struct node {
	int l, r, val, maxi , mini  = 0;
	node() {
		l = 0, r = 0, val = 0, maxi = 0, mini = 0;
	}
};

int n, q;
int a[maxn] = {};
node st[4 * maxn] = {};
void build(int id, int l, int r) {
	if(l == r) {
		st[id].val = a[l];
		st[id].l = st[id].r = l;
		st[id].maxi = st[id].mini = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(id << 1, l, mid);
	build((id << 1) | 1, mid + 1, r);
	int k = __gcd(st[id << 1].val, st[(id << 1) | 1].val);
	// cerr << k << endl;

	st[id].l = st[id << 1].l;
	st[id].r = st[id << 1 | 1].r;
	st[id].val = __gcd(k, abs(a[st[id].r] - a[st[id]. l]));
	st[id].maxi = max(st[id << 1].maxi, st[id << 1 | 1].maxi);
	st[id].mini = min(st[id << 1].mini, st[id << 1 | 1].mini);
}
pii get(int id, int l, int r, int u, int v) {
	if(v < l || u > r) return mp(0, mp(0, INF));
	else if(u <= l && r <= v) {
		return mp(st[id].val, mp(st[id].maxi, st[id].mini));
	}
	int mid = l + r >> 1;
	pii get1 = get(id << 1, l, mid, u, v);
	pii get2 = get(id << 1 | 1, mid + 1, r, u, v);
	int k = __gcd(get1.fi, get2.fi);
	k = __gcd(k, st[id << 1].r);
	k = __gcd(k, st[id << 1 | 1].l);
	return mp(k, mp(max(get1.se.fi, get2.se.fi), min(get1.se.se, get2.se.se)));
}
void solve() {
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	build(1, 1, n);
	int u, v;
	while(q--) {
		cin >> u >> v;
		if(v - u <= 1) {
			YES 
			continue;
		}
		pii ans = get(1, 1, n, u, v);
		int maxi = ans.se.fi, mini = ans.se.se, k = ans.fi;
		if(maxi == mini) NO
		else if(maxi - mini == k * (v - u)) YES
		else NO
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
 	solve();
}