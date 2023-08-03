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
int const maxn 		= 	1e5 + 10;
int const INF 		= 	LLONG_MAX;

struct node {
	node* child[2];
	node() {
		child[0] = child[1] = NULL;
	}
} *root;
struct Trie {
	Trie() {
		root = new node();
	}
	void add(int x) {
		node *cur = root;
		for(int i = 29; i >= 0; i--) {
			bool c = (x >> i) & 1;
			if(cur -> child[c] == NULL) cur -> child[c] = new node();
			cur = cur -> child[c];
		}
	}
	//Lấy hai thằng từ 2 nhánh khác nhau nhưng có giá trị xor nhỏ nhất
	int branch(node* l, node* r, int depth) {
		if(depth < 0) return 0; //<------------- Đã vượt quá độ sâu của cây Trie
		if(l == NULL || r == NULL) return INF; //Tại nút không có rẽ nhánh, return ULLONG_MAX

		if((l -> child[0] && r -> child[0]) ||
		   (l -> child[1] && r -> child[1])) { //<---- cả l r đều có chung bit thì ta lấy gtnn của hai hàm
			return min(branch(l -> child[0], r -> child[0], depth - 1),
					   branch(l -> child[1], r -> child[1], depth - 1));
		}
		return min(branch(l -> child[1], r -> child[0], depth - 1),
				   branch(l -> child[0], r -> child[1], depth - 1)) + (1 << depth); //<--- Không thì chịu :))
	}
	//Lấy giá trị xor của cây con với đỉnh tại node cur đang xét
	int ans(node* cur, int depth) {
		if(cur == NULL) return 0;
		int couting = ans(cur -> child[0], depth - 1) + 
		 			  ans(cur -> child[1], depth - 1); 
		if(cur -> child[0] == NULL || cur -> child[1] == NULL) {
			return couting;
		}
		return couting + branch(cur -> child[0], cur -> child[1], depth - 1) + (1 << depth);
		//+ 1 << depth vì rẽ sang hai nhánh sẽ khiến 1 ^ 0 = 1 tại độ sâu depth nên dời sang
		//depth bit
	}

} mainTrie;
int n, x;
void solve() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> x;
		mainTrie.add(x);
	}
	cout << mainTrie.ans(root, 29);
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
 	solve();
}