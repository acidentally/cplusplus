#include <bits/stdc++.h>
using namespace std;

struct node {
	bool avail;
	node *letters[26];
};

int alpha(char a) {
	return a - 'a';
}

node* createNode() {
	node *p = new node;
	for(int i = 0; i < 26; i++) {
		p -> letters[i] = NULL;
	}
	p -> avail = false;
	return p;
}

void addNode(string& s, node *root) {
	node *p = root;
	for(int i = 0; i < s.size(); i++) {
		if(p -> letters[ alpha(s[i]) ] == NULL) {
			p -> letters[ alpha(s[i]) ] = createNode();
		}
		
		p = p -> letters[ alpha(s[i]) ];
	}
}

int longestTienTo(string& s, node *root) {
	node* p = root;
	
	for(int i = 0; i < s.size(); i++) {
		if(p -> letters[ alpha(s[i]) ] == NULL) {
			return i;
		}
	
		p = p -> letters[ alpha(s[i]) ];
	}
	return s.size();
}

int main() {
	ios_base:: sync_with_stdio(0); cin.tie(NULL);
	node *rootMain = createNode();

}