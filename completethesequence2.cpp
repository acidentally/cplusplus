#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc; cin >> tc;
	while(tc--) {
	int S, C; cin >> S >> C;

	int sq[S + C + 1][S + C + 2];
	for(int i = 1; i <= S; i++) {
		cin >> sq[1][i];
	}
	int cnt = 1;
	bool check = true;
	while(check) {
		for(int j = 1; j <= S - cnt; j++) {
			sq[cnt + 1][j] = sq[cnt][j + 1] - sq[cnt][j];
			// cout << sq[cnt + 1][j] << ' ';
		}
		cnt++;
		// cout << endl << cnt << endl;
		check = 0;
		for(int i = 1; i <= S - cnt; i++) {
			if(sq[cnt][i] != 0) {
				check = true;
				break;
			}
		}
	}
	for(int i = S - cnt + 1; i < S + C - cnt + 1; i++) {
		sq[cnt][i + 1] = 0;
	}
	//test only
	// for(int i = 1; i <= S + C - cnt + 1; i++) {
	// 	cout << sq[cnt][i] << ' ';
	// }
	// cout << endl;
	cnt--;
	while(cnt >= 1) {
		for(int i = S - cnt + 1; i <= S - cnt + 1 + C; i++) {
			sq[cnt][i] = sq[cnt + 1][i - 1] + sq[cnt][i - 1];
		}
		cnt--;
	}

	for(int i = 1; i < S + C; i++) {
		cout << sq[1][i] << ' ';
	}
}}