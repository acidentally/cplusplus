#include <bits/stdc++.h>
using namespace std;

struct node {
	node* numbers[11];
	node() {
		for(int i = 0; i <= 10; i++) {
			numbers[i] = NULL;
		}
	}
};

void insertVecc(vector<int> vec, node* root) {
	node* ptr = root;
	for(int i = 0; i < vec.size(); i++) {
		if(ptr -> numbers[vec[i]] == NULL) {
			ptr -> numbers[vec[i]] = new node;
		}
		ptr = ptr -> numbers[vec[i]];
	}
}

int res(vector<int> vec, node* root) {
	node* p = root;
	for(int i = 0; i < vec.size(); i++) {
		if(p -> numbers[vec[i]] == NULL) {
			return i - 1;
		}
		p = p -> numbers[vec[i]];
	}
	return vec.size() - 1;
}

int main() {
	ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	int n, m;

	vector< vector<int> > mainPermuations;
	vector<int> temp;
	vector<int> perms;
	int cinTemp;


	while(tc--) {
		cin >> n >> m;	
		node* rootMain = new node;
		mainPermuations = vector < vector <int> > ();
		
		for(int i = 1; i <= n; i++) {
		
			temp = vector<int>(m + 1, 0);
			perms = vector<int>();
			perms.push_back(0);
			
			for(int j = 1; j <= m; j++) {
				cin >> cinTemp;
				temp[cinTemp] = j;
				perms.push_back(cinTemp);
			}
			
			mainPermuations.push_back(perms);
			insertVecc(temp, rootMain);
		
		}
		
		for(int i = 0; i < n; i++) {
			cout << res(mainPermuations[i], rootMain) << ' ';
			// for(auto& k : mainPermuations[i]) {
			// 	cout << k << ' ';
			// }
			// cout << '\n';
		}
		cout << '\n';
	}
}


// abcde
// abcdf
// abdfe
// a -> b -> c -> d -> e 
//                  -> f
//        -> d -> f ->