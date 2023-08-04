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

int n, u;
void solve() {	
	cin >> n;
	string s = "";
	vi a;
	cin >> u; cout << 1;
	a.push_back(u);
	int i;
	for(i = 0; i < n - 1; i++) {
		cin >> u;
		if(u < a[i] && u <= a[0]) {
			s = s + '1';
			a.push_back(u);
			break;
		} else if(u < a[i] && u > a[0]) {
			s = s + '0';
			break;
		} else {
			a.push_back(u);
			s = s + '1';
		}
	}
	i += 2;
	for(int j = i; j < n; j++) {
		cin >> u;
		if(u > a[0]) {
			s = s + '0';
			continue;
		} 
		if(u >= a.back() && u <= a[0]){
			s = s + '1';
			a.push_back(u);
		} 
		else s = s + '0';
	}
	cout << s << endl;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int tc; cin >> tc;
	while(tc--)
	solve();
}