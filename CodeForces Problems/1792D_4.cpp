#include <bits/stdc++.h>
using namespace std;
int findPos(int i, vector<long long> vec) {
	for(int j = 0; j < vec.size(); j++) {
		if(vec[j] == i) return j;
	}
}

int main() {
	ios_base:: sync_with_stdio(0); cin.tie(NULL); cout.tie(0);
	long long tc; cin >> tc;
	while(tc--) {
		set<vector<long long>> avail;
		vector<vector<long long>> save;
		vector<long long> temp;
		long long lmao;

		long long n, m; cin >> n >> m;
		for(int i = 0; i < n; i++) {
			vector<long long> permutations(m, -1);
			temp = vector<long long> ();
			for(long long where = 0; where < m; where++) {
				cin >> lmao;
				permutations[lmao - 1] = where;
				temp.push_back(lmao - 1);
			}
			for(int j = m - 1; j >= 0; j--) {
				avail.insert(permutations);
				permutations[j] = -1;
			}
			avail.insert(permutations);
			save.push_back(temp);
		}

		for(long long i = 0; i < n; i++) {
			for(long long j = m; j > 0; j--) {
				if(avail.count(save[i]) != 0) {
					cout << j;
					if(i < n - 1) cout << ' ';
					break;
				}
				if(j == 1) cout << 0 << ' ';
				else {
					save[i][j - 1] = -1;
				}
			}
		}
		if(tc > 0) cout << '\n';
	}
	return 0;
}