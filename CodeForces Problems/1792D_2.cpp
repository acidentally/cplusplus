#include <bits/stdc++.h>
using namespace std;

int m;

struct node {
	node* numbers[10];
	bool isEnd;
};

node* createNode() {
	node* p = new node;
	for(int i = 0; i < 10; i++) {
		p -> numbers[i] = NULL;
	}
	//p -> isEnd = false;
	return p;
}

void addNode(string& s, node* root) {
	node* p = root;
	for(int i = 0; i < s.size(); i++) {
		if(p -> numbers[s[i] - '1'] == NULL) {
			p -> numbers[s[i] - '1'] = createNode();
		}
		p = p -> numbers[s[i] - '1'];
	}
}

int maxTienTo(string& s, node* root) {
	node* p = root;
	for(int i = 0; i < s.size(); i++) {

		if(p -> numbers[s[i] - '1'] == NULL) {
			return i;
		}

	}
	return s.size();
}

int main() {
	ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	int n;
	char cinChar;
	node* rootMain = createNode();
	string tempS, tempS_2;
	vector<string> arrayOfStrings;
	int compare; int max;

	while(tc--) {

		cin >> n >> m;
		arrayOfStrings = vector<string>();
		char tempPermuHolder[m];
		
		for(int i = 0; i < n; i++) {
			tempS = "";
			for(int j = 0; j < m; j++) {
				cin >> cinChar;
				tempS += cinChar;
				tempPermuHolder[(int)cinChar - '1'] = j - '1';
			}
			tempS_2 = "";
			for(int k = 0; k < m; k++) {
				tempS_2 += tempPermuHolder[k];
			}
			addNode(tempS_2, rootMain);
			
			arrayOfStrings.push_back(tempS);

		}
		for(int i = n - 1; i > 0; i--) {
			max = 0;
			tempS = arrayOfStrings[i];
			compare = maxTienTo(tempS, rootMain);
			max = (max > compare) ? max : compare;
			cout << max << ' ';
		}
		cout << '\n';
	}
}