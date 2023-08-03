#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define vi vector<int>
#define vvi vector< vector <int> >
#define endl '\n'
#define fr(i, a, b) for(int i = a; i < b; i++)

signed main() {
	ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	int n, q, x;
	vi a();
	set<int> idx;
	while(tc--) {
		cin >> n >> q;
		a = vi();
		idx.clear();
		fr(i,0,n) {
			cin >> x;
			a.push_back(x);
			if(x >= 10) idx.insert(i);
		}

		fr(i,0,q) {
			cin >> x;
			if(x == 1) {
				cin >> l >> r;
				
			}
		}

	}
}