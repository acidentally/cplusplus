#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define vi vector<int>
#define vvi vector< vector<int> >
#define endl '\n'

struct node {
	int value;
	node *letters[2];
};

node* createNode() {
	node *p = new node;
	p -> value = 0;
	for(int i = 0; i < 2; i++) {
		p -> letters[i] = NULL;
	}
	return p;
}

void addNode(int k, node *root) {
	node* p = root;
	for(int i = 8; i >= 0; i--) {
		bool val = k & (1 << i);
		if(p -> letters[val] == NULL) {
			p -> letters[val] = createNode();
		}
		p = p -> letters[val];
	}
	p -> value = k;
}
int query(node* root, int prexor) {
	node* p = root;
	for(int i = 8; i >= 0; i--) {
		bool val = prexor & (1 << i);
		if(p -> letters[1 - val] != NULL) {
			p = p -> letters[1 - val];
		}
		else if(p -> letters[val] != NULL){
			p = p -> letters[val];
		}
	}
	return prexor ^ (p -> value);
}
int n, x;
void solve() {
	cin >> n;
	vi a;
	node *rootMain = createNode();
	int prexor = 0;
	addNode(0, rootMain);
	for(int i = 0; i < n; i++) {
		cin >> x;
		prexor ^= x;
		a.push_back(prexor);
		addNode(prexor, rootMain);
	}
	int maxi = 0;
	for(int i = 0; i < n; i++) {
		int val = 0;
		maxi = max(maxi, query(rootMain, a[i]));
	}
	cout << maxi << endl;
}
signed main() {
	ios_base:: sync_with_stdio(0); cin.tie(NULL);
	int tc; cin >> tc;
	while(tc--) {
		solve();
	}
}