#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int S, C;
	int tc; cin >> tc;
	while(tc--) {
		cin >> S >> C;
		int sq[*(&S) + *(&C) + 1][*(&S) + *(&C) + 2] = {};
		for(int i = 1; i <= S; i++) {
			cin >> sq[1][i];
		}
		int cnt = 1;
		bool check = true;
		while(check && cnt <= S ) {
			for(int j = 1; j <= S - cnt; j++) {
				sq[cnt + 1][j] = sq[cnt][j + 1] - sq[cnt][j];
			}
			cnt++;
			check = false;
			for(int i = 1; i <= S - cnt + 1; i++) {
				if(sq[cnt][i] != 0) {
					check = true;
					break;
				}
			}
		}
		for(int i = S - cnt + 1; i < S + C - cnt + 1; i++) {
			sq[cnt][i + 1] = 0;
		}
		cnt--;
		while(cnt) {
			for(int i = S - cnt + 1; i <= S - cnt + 1 + C; i++) {
				sq[cnt][i + 1] = sq[cnt + 1][i ] + sq[cnt][i ];
			}
			cnt--;
		}

		for(int i = S + 1; i <= S + C; i++) {
			cout << sq[1][i] << ' ';
		}
		cout << endl;
	}
}

// 1 1 1 1 1 1 1 1 1 2






