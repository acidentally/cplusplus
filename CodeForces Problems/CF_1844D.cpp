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
int const maxn = 1e6 + 10;
int n;
bool cnt[maxn] = {};
char a[maxn] = {};
void solve() {
	cin >> n;
	vi div;
	for(int i = 1; i * i <= n; i++) {
		if(n % i == 0) {
			div.push_back(i);
			if(i * i != n) div.push_back(n/i);
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < div.size(); j++) {
			if(i - div[j] >= 1) {
				cnt[a[i - div[j]]] = 1;
			}
		}
		for(char x = 'a'; x <= 'z'; x++) {
			if(!cnt[x]) {
				a[i] = char(x);
				break;
			}
		}
		for(int j = 0; j < div.size(); j++) {
			if(i - div[j] >= 1) {
				cnt[a[i - div[j]]] = 0;
			}
		}
	}
	for(int i = 1; i <= n; i++) cout << a[i];
	cout << endl;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while(t--)
	solve();
}