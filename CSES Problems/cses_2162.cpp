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

int n, temp;
void solve() {
	cin >> n;
	multiset<int> a;
	for(int i = 1; i <= n; i++) {
		a.insert(i);
	}
	multiset<int>::iterator ptr = a.begin();
	ptr++;
	while(!a.empty()) {
		if(a.size() == 1) {
			cout << *a.begin();
			break;
		}
		temp = *ptr;
		cout << temp << ' ';
		ptr++;
		a.erase(temp);
		if(ptr == a.end()) {
			ptr = a.begin();
			ptr++;
		}
		else {
			ptr++;
			if(ptr == a.end()) ptr = a.begin();
		}
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}
