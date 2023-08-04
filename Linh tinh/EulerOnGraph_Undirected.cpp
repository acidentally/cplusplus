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
bool a[maxn][maxn] = {};
int n, m, u, v, deg[maxn] = {}, cnt = 0;
deque<int> ans;
vi p;
void init() {
	p.resize(n + 1);
	for(int i = 0; i <= n; i++) {
		p[i] = i;
	}
}
int find(int k) {
	if(k != p[k]) p[k] = find(p[k]);
	return p[k];
}
void connect(int a, int b) {
	a = find(a); 
	b = find(b);
	if(a != b) {
		p[a] = b;
	}
}
void DFS(int k) {
	if(cnt == m) return;
	cnt++;
	ans.push_back(k);
	deg[k] -= 2;
	int maxi = 0, nextDFS = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i][k] && deg[i] >= maxi) {
			maxi = deg[i];
			nextDFS = i;
		}
	}
	a[nextDFS][k] = a[k][nextDFS] = 0;
	DFS(nextDFS);
}
void solve() {
	cin >> n >> m;
	bool check2[n + 1] = {};
	init();
	for(int i = 0; i < m; i++) {
		cin >> u >> v;
		check2[u] = check2[v] = 1;
		deg[u]++;
		deg[v]++;
		a[u][v] = a[v][u] = 1;
		connect(u, v);
	}
	unordered_map<int, bool> mp1;
	for(int i = 1; i <= n; i++) {
		if(check2[i]) mp1[find(i)] = 1;
	}
	if(mp1.size() >= 2) {
		// cout << mp1.size() << endl;
		cout << "IMPOSSIBLE";
		exit(0);
	}
	int maxi = 0, startDFS = 0;
	for(int i = 1; i <= n; i++) {
		if(deg[i] & 1) {
			cout << "IMPOSSIBLE";
			exit(0);
		}
		if(deg[i] > maxi) {
			maxi = deg[i];
			startDFS = i;
		}
	}
	DFS(startDFS);
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
	// while(ans.front() != 1) {
	// 	ans.push_back(ans.front());
	// 	ans.pop_front();
	// }
	while(!ans.empty()) {
		cout << ans.front() << ' ';
		ans.pop_front();
	}
	cout << 1;
} 