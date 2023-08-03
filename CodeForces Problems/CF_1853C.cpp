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
#define fi				first
#define se 				second
#define vvi 			vector< vector<int> >
#define endl 			'\n'
#define pb 				push_back
#define pf 				push_front
#define all(a) 			a.begin(), a.end()
#define mp 				make_pair
#define YES 			cout<<"YES\n";
#define NO 				cout<<"NO\n";
#define space   		' '
#define ins 			insert
typedef vector<int> 	vi;
typedef pair<int, int> 	pi;
int const mod 		= 	1e9 + 7;
int const maxn 		= 	2e5 + 10;
int const INF 		= 	LLONG_MAX;

int n, k;
int a[maxn] = {};
int find(int i) {
	int l = 1, r = n;
	while(l < r) {
		int mid = l + r >> 1;
		if(a[mid] == i) return mid;
		if(a[mid] < i) l = mid + 1;
		else r = mid;
	}
	return l;
}
int calc(int num) {
	int idx = find(num);
	int days = 0, diff = num - a[idx];
	while(idx != 1) {
		if(diff % idx == 0) {
			return -1;
		}
		days += diff / idx + 1;
		num -= (diff + idx) / idx * idx;
		idx = find(num);
		diff = num - a[idx];
		cerr << idx << ' ' << num << endl;
	}
	cerr << endl << endl;
	return days;
}
void solve() {
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	if(a[1] != 1) {
		cout << 1 << endl;
		return;
	}
	uint l = 1, r = k * n;
	cout << find(3) << endl;
	// while(l < r) {
	// 	int mid = l + r >> 1;	
	// 	cerr << mid << ' ' << "TRASH" << endl;
	// 	int ans = calc(mid);
	// 	if(ans == -1) {
	// 		r += 2;
	// 	}
	// 	if(ans == k) {
	// 		cout << mid << endl;
	// 		return;
	// 	} else if(ans > k) {
	// 		r = mid - 1;
	// 	} else l = mid + 1;
	// }
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while(t--) solve();
}


1 2 3 4 5 ... n
0 : n : nhỏ thứ n:
idx lớn nhất : a[idx] < n
1 : n : ((((n - idx))))
idx2 lớnn hất : a[idx2] < n - idx
2 : n - idx - idx2

1 2 3 4 5
10