#include <bits/stdc++.h>
using namespace std;

#define int long long



signed main() {
	ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	int n; 

	set<int> firstnumber;
	while(tc--) {
		cin >> n;
		int permuations[n][n - 1];
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n - 1; j++) {
				cin >> permuations[i][j];
			}
		}
		int fi, idx;
		int temp1 = permuations[0][0];
		int temp2 = permuations[1][0];
		if(temp1 != temp2) {
			if(permuations[2][0] != temp1) {
				fi = temp2;
				idx = 0;
			} else {
				fi = temp1;
				idx = 1;
			}
		} else {
			fi = temp1;
			for(int i = 2; i < n; i++) {
				if(permuations[i][0] != temp1) {
					idx = i;
				}
			}
		}
		cout << fi << ' ';
		for(int i = 0; i < n - 1; i++) {
			cout << permuations[idx][i] << ' ';
		}
		cout << '\n';
	}
}

