#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define vi vector<int>
#define vvi vector< vector <int> >
#define endl '\n'
#define fr(i, a, b) for(int i = a; i < b; i++)

void sumdigits(int& i) {
	int res = 0;
	string s = to_string(i);
	for(int k = 0; k < s.size(); k++) {
		res += s[k] - '0';
	}
	i = res;
}

signed main() {
	ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	int n, q, l, r, x;
	int cinTemp;
	vi a;
	set<int> idx;
	set<int>::iterator it;
	int temp;
	while(tc--) {
		cin >> n >> q;
		a = vi();
		idx.clear();
		fr(i, 0, n) {
			cin >> cinTemp;
			if(cinTemp >= 10) idx.insert(i);
			a.push_back(cinTemp);
		}
		// std::set<int>::iterator temp;
		while(q--) {
			cin >> cinTemp;
			if(cinTemp == 1) {
				cin >> l >> r;
				l--; r--;
				while(!idx.empty()) {
					it = idx.lower_bound(l);
					if(*it > r || it == idx.end()) break;
					sumdigits(a[*it]);
					l = *it + 1;
					if(a[*it] <= 9) idx.erase(it);
				}
			} else if(cinTemp == 2) {
				cin >> x; 
				cout << a[x - 1] << endl;
			}
		}
	}
}