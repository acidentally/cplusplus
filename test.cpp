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

struct trieNode {
	bool End;
	trieNode* c[26];
	trieNode() {
		for(int i = 0; i < 26; i++) {
			c[26] = nullptr;
		}
		End = 0;
	}
	trieNode* rootNode;
	void addString(string s) {
		trieNode* ptr = rootNode;
		int cur;
		for(int i = 0; i < s.size(); i++) {
			cur = s[i] - 'A';
			if(ptr -> c[cur] == NULL) {
				ptr -> c[cur] = new trieNode();
			}
			ptr = ptr -> c[cur];
		}
		ptr -> End = 1;
	}

	trieNode* find(string s) {
		trieNode* ptr = rootNode;
		for(int i = 0; i < s.size(); i++) {
			if(ptr -> c[s[i] - 'A'] == NULL) return ptr;
			else ptr = ptr -> c[s[i] - 'A'];
		}
		return ptr;
	}
};

int n;
string s;
void solve() {
	cin >> n;
	while(n--) {
		cin >> s;
		addString(s);
	}
	cin >> s;
	trieNode* ptr = find(s);
	bool check[26] = {};
	for(int i = 0; i < 26; i++) {
		if(ptr -> c[i]) check[i] = 1;
	}
	for(int i = 0; i < 26; i++) {
		cout << check[i] << ' ';
	}
}
signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solve();
}