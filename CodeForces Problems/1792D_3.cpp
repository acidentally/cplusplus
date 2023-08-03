#include <bits/stdc++.h>
using namespace std;

struct node {
	node* numbers[10];
};

node* createNode() {
	node* ret = new node;
	for(int i = 0; i < 10; i++) {
		ret -> numbers[i] = NULL;
	}
	return ret;
}

void addNode(string& s, node* root) {
	node* p = root;
	for(int i = 0; i < s.size(); i++) {
		if(p -> numbers[s[i] - '0'] == NULL) {
			p -> numbers[s[i] - '0'] = createNode();
		}
		p = p -> numbers[s[i] - '0'];
	}
}

int maxTienTo(string& s, node* root) {
	node* p = root;
	for(int i = 0; i < s.size(); i++) {

		if(p -> numbers[s[i] - '0'] == NULL) {
			return i;
		}

	}
	return s.size();
}

int main() {
	ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	int n, m;
	node* rootMain;
	string s, tempS; char temp;
	vector<string> arrayofstring;

	while(tc--) {
		rootMain = createNode();
		cin >> n >> m;
		while(!arrayofstring.empty()) arrayofstring.pop_back();
		
		for(int i = 0; i < n; i++) {
			tempS = ""; s = "";
			for(int j = 0; j < m; j++) {
				s += '*';
			}
			for(int k = 0; k < m; k++) {

				cin >> temp;
				tempS += (char)(temp - 1);
				s[temp - '1'] = (char)(k + 48); //48 is (int) '0'; 

			}
			addNode(s, rootMain);
			arrayofstring.push_back(tempS);
		}

		for(int i = 0; i < n; i++) {
			cout << maxTienTo(arrayofstring[i], rootMain) << ' ';
		}
		cout << '\n';
	}
}