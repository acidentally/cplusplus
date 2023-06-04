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

int n;

struct node {
	int level;
	node* down[4];
};

node* createNode(int a) {
	node* Node = new node;
	Node -> level = a;
	for(int i = 1; i <= 3; i++) {
		Node -> down[i] = NULL;
	}
	return Node;
}
void AddNode(string s) {

}
string s, number;
void solve() {
	cin >> n;
	node* rootNode = createNode(0);
	for(int i = 0; i < n; i++) {
		cin >> s;
		getline(cin, number);
		AddNode(number);
		mapp[number] = s;
	}
	
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	int tc; cin >> tc;
	while(tc--) {
		solve();
	}
}