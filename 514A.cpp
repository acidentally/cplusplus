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
	string s; cin >> s;
	fr(i, 0, s.size()) {
		if(i == 0 && s[i] == '9') continue;
		if(s[i] > '4') s[i] = ('9' - s[i]) + '0';
	}
	cout << s;
}