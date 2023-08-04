/*
Good luck for those who are trying your best
May the most glorious victory come
Code by : acident / lckintrovert
Literally the worst cp-er ever
*/

#include <bits/stdc++.h>
using namespace std;

#define int 			long long
#define uint 			unsigned long long
#define fi				first
#define se 				second
#define vvi 			vector< vector<int> >
#define endl 			'\n'
#define pb 				push_back
#define pf 				push_front
#define all(a) 			a.begin(), a.end()
#define mp 				make_pair
#define YES 			cout<<"YES\n";
#define NO 				cout<<"NO\n";
#define space   		' '
#define ins 			insert
typedef vector<int> 	vi;
typedef pair<int, int> 	pi;
int const mod 		= 	1e9 + 7;
int const maxn 		= 	5e6 + 10;
int const INF 		= 	LLONG_MAX;

int a[maxn] = {}, b[maxn] = {};
struct Trie{
    struct Node{
        int child[3];
        int exist, cnt;
    } nodes[maxn];

    int cur;
    Trie() : cur(0) {
        memset(nodes[0].child, -1, sizeof(nodes[cur].child));
        nodes[0].exist = nodes[0].cnt = 0;
    };

    int new_node() {
        cur++;
        memset(nodes[cur].child, -1, sizeof(nodes[cur].child));
        nodes[cur].exist = nodes[cur].cnt = 0;
        return cur;
    }

    void add_number(int l, int r) {
        int pos = 0;
        for (int i = l; i <= r; i++) {
        	int c = a[i];
        	if(i > l) nodes[pos].exist++;
            if (nodes[pos].child[c + 1] == -1) nodes[pos].child[c + 1] = new_node();
            pos = nodes[pos].child[c + 1];
            nodes[pos].cnt++;
        }
    }

    int find_number(int l, int r) {
        int pos = 0;
        for (int i = l; i <= r; i++) {
            int c = b[l];
            if (nodes[pos].child[c + 1] == -1) return false;
            pos = nodes[pos].child[c + 1];
        }
        return nodes[pos].exist;
    }
}maintrie;
int n, m;
void solve() {
	cin >> m >> n;
	int l = 1;
	queue<pi> q;
	for(int i = 1; i <= m; i++) {
		cin >> a[i];
		if(a[i] == 0) {
			if(l <= i - 1) q.push({l, i - 1});
			l = i + 1;
		}
	}
	for(int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	while(!q.empty()) {
		int u = q.front().fi, v = q.front().se;
		q.pop();
		maintrie.add_number(u, v);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j + i <= m; j++) {
			ans += maintrie.find_number(i, j);
		}
	}
	cout << ans;
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
 	solve();
}