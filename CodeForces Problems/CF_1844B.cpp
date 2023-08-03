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
int const maxn = 2e5 + 10;
int n;
void solve() {
	cin >> n;
	if(n == 1) {
		cout << 1 << endl;
		return;
	}
	if(n == 2) {
		cout << 1 << ' ' << 2 << endl;
		return;
	}
	else if(n >= 3) {
		deque<int> q;
		q.push_back(1);
		bool check = false;
		for(int i = n; i >= 2; i--) {
			if(check) {
				q.push_back(i);
				check = !check;
			}
			else if(!check) {
				q.push_front(i);
				check = !check;
			}
		}
		while(!q.empty()) {
			cout << q.front() << ' ';
			q.pop_front();
		}
		cout << endl;
	}

}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int t; cin >> t;
	while(t--)
	solve();
}