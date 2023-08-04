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
int n, m, u, v, low[maxn] = {}, ids[maxn] = {}, id = 1, cnt = 1;
vi a[maxn];
bool vis[maxn] = {}, onStack[maxn] = {};
stack<int> st;
string trash = "Thanh phan ";
bool found = 0;
void couting(stack<int> s) {
	while(!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
}
void DFS(int k) {
	ids[k] = low[k] = id++;
	vis[k] = true;
	st.push(k);
	onStack[k] = true;
	for(int i = 0; i < a[k].size(); i++) {
		int temp = a[k][i];
		if(!vis[temp]) {
			DFS(temp);
		}
		if(onStack[temp]) {
			low[k] = min(low[temp], low[k]);
		}
	}

	if(ids[k] == low[k]) {
		cout << trash << cnt++ << " : ";
		while(!st.empty() && st.top() != k) {
			cout << st.top() << ' ';
			onStack[st.top()] = false;
			st.pop();
		}
		cout << st.top() << endl;
		st.pop();
	}
}
void solve() {
	cin >> n >> m;
	while(m--) {
		cin >> u >> v;
		a[u].push_back(v);
	}
	for(int i = 1; i <= n; i++) {
		if(!vis[i]) DFS(i);
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}