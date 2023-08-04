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

int const maxn = 1e5 + 10;
int n, m, u, v, temp;
vi a[maxn];
deque<int> dq;
bool found = false;
bool vis[maxn] = {}, alrDFS[maxn] = {};

void DFS(int idx, int par) {
	vis[idx] = 1;
	for(int i = 0; i < a[idx].size(); i++) {
		// if(a[idx][i] == par) continue;
		temp = a[idx][i];
		if(!alrDFS[temp] && vis[temp]) {
			cout << "YES" << endl;
			found = true;
			dq.push_back(temp);
		}
		else if(!vis[temp]) {
			DFS(temp, idx);
		}
		if(found) {
			if(idx == dq.back()) {
				cout << idx << ' ';
				while(!dq.empty()) {
					cout << dq.front() << ' ';
					dq.pop_front();
				}
				exit(0);
			}
			else {
				dq.push_front(idx);
				return;
			}	
		}
	}
	alrDFS[idx] = 1;
}
void solve() {
	cin >> n >> m;
	while(m--) {
		cin >> u >> v;
		a[u].push_back(v);
	}
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) DFS(i, -1);
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
	if(!found) cout << "NO" << endl;
}