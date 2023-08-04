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

int n, cnt = 1, vis[200] = {};
unordered_map<string, int> mp;
string trace[100];
void put(string s, int& c) {
	mp[s] = c;
	trace[c] = s;
	c++;
}
vi a[200], couting[2];
void DFS(int k, bool x) {
    vis[k] = x;
    couting[!x].push_back(k);
    for(int i = 0; i < a[k].size(); i++) {
        if(vis[a[k][i]] == -1) {
            DFS(a[k][i], !x);
        } else if(vis[a[k][i]] == x) {
            cout << -1;
            exit(0);
        }
    }
}
void solve() {

	string s1, s2; s1 = "0";
	memset(vis, -1, sizeof(vis));
	while(s1 != "!") {
		cin >> s1;
		if(s1 == "!") break;
		if(mp[s1] == 0) put(s1, cnt);
		cin >> s2;
		if(mp[s2] == 0) put(s2, cnt);
		a[mp[s1]].push_back(mp[s2]);
		a[mp[s2]].push_back(mp[s1]);
	}
	for(int i = 1; i < cnt; i++) {
        if(vis[i] == -1 && !a[i].size()) {
            cout << -1;
            exit(0);
        }
        if(vis[i] == -1) {
            DFS(i, 1);
        }
    } 	
    set<string> ss1, ss2;
    for(auto i : couting[1]) {
    	ss1.insert(trace[i]);
    }
    for(auto i : couting[0]) {
    	ss2.insert(trace[i]);
    }
    for(auto i : ss1) cout << i << ' ';
    cout << endl;
	for(auto i : ss2) cout << i << ' ';
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}