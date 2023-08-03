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
	int n;
	int cinTemp, temp;
	while(tc--) {
		cin >> n;
		int i;
		for(i = 0; i < n; i++) {
			cin >> cinTemp;
			if(i >= 1 && cinTemp - temp >= 122) {
				cout << "YES" << endl;
				break;
			}
			temp = cinTemp;
		}
		if(i == n) cout << "NO" << endl;
	}
}