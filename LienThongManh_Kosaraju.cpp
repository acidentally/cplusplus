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

int const maxn = 1e4 + 10;
int n, m, u, v, temp;
int mp[maxn] = {};
vi a[maxn], revA[maxn];
stack<int> st;
bool vis[maxn] = {};
string trash = "Thanh phan ";


void DFS(int idx, stack<int>& st) {
	vis[idx] = true;
	for(int i = 0; i < a[idx].size(); i++) {
		temp = a[idx][i];
		if(!vis[temp]) {
			DFS(temp, st);
		}
	}
	st.push(idx);
}

void revDFS(int idx, vi& vec) {
	mp[idx] = idx;
	vec.push_back(idx);
	vis[idx] = 1;
	for(int i = 0; i < revA[idx].size(); i++) {
		temp = revA[idx][i];
		if(!vis[temp]) {
			revDFS(temp, vec);
		}
	}
}	


void solve() {
	cin >> n >> m;
	while(m--) {
		cin >> u >> v;
		a[u].push_back(v);
		revA[v].push_back(u);
	}
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) {
			DFS(i, st);
		}
	}
	int cnt = 1;
	vi couting;
	memset(vis, 0, sizeof(vis));
	while(!st.empty()) {
		u = st.top();
		cout << trash << cnt++ << " : ";
		couting = vi();
		st.pop();
		revDFS(u, couting);

		while(!st.empty() && vis[st.top()]) {
			mp[st.top()] = u;
			st.pop();
		}
		cout << couting.size() << ' ';
		for(auto i : couting) cout << i << ' ';
		cout << endl;
	}
	cout << "Do thi co dac: ";
	for(int i = 1; i <= n; i++) {
		cout << mp[i] << ' ';
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}