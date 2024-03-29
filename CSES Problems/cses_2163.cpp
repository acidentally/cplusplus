/*
Good luck for those who are trying your best
May the most glorious victory come
File name: cses_2163.cpp
Code by : acident / lckintrovert
Created since : 31/08/2023 ~~ 12:27:12
Literally the worst cp-er ever
*/
#include <bits/stdc++.h>
using namespace std;
 
#define int                 long long
#define uint                unsigned long long
#define dub                 double
#define fi                  first
#define se                  second
#define vvi                 vector< vector<int> >
#define endl                '\n'
#define pb                  emplace_back
#define pf                  push_front
#define all(a)              a.begin(), a.end()
#define mp                  make_pair
#define YES                 cout << "YES\n";
#define NO                  cout << "NO\n";
#define ins                 insert
#define coutdub(x)          cout << fixed << setprecision(x)
 
typedef vector<int>         vi;
typedef pair<int, int>      pi;
typedef pair<int, pi>       pii;
 
int const maxn      =       2e5 + 10; 
int n, k, N;
int BIT[maxn] = {};

void upd(int id) {
	int p = id;
	while(p <= N) {
		BIT[p]--; 
		p += p & (-p);
	}
}
int query(int id) {
	int res = 0, p = id;
	while(p > 0) {
		res += BIT[p];
		p -= p & (-p);
	}
	return res;
}
int find(int u) {
	int l = 1, r = N;
	int mid, cur;
	while(l < r) {
		mid = (l + r) >> 1;
		cur = query(mid);
		if(cur >= u) r = mid;
		else l = mid + 1;
	}
	return l;
}
void solve() {
	cin >> n >> k;
	N = n;
	k--;
	for (int i = 1; i <= n; i++) {
		BIT[i] = i & -i;
	}
	int ans = k + 2, k_ = 1;
	n++;
	while (n > 0) {
		n--;
		if(n == 0) return;
		k_ = (k_ + k + n) % n + 1;
		ans = find(k_);
		cout << ans << ' ';
		upd(ans);
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}