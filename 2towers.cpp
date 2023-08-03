#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int tc; cin >> tc;

	int n, m;
	string F, S;
	int countF, countS;

	while(tc--) {
		cin >> n >> m >> F >> S;
		countF = 0; countS = 0;
		for(int i = 0; i < n - 1; i++) {
			if(F[i] == F[i + 1]) {
				countF += 1;
			}	
		}
		for(int i = 0; i < m - 1; i++) {
			if(S[i] == S[i + 1]) {
				countS += 1;
			}
		}
		if(countF + countS >= 2) cout << "NO";
		else if(countF == 0 && countS == 0) cout << "YES";
		else {
			if(S[m - 1] != F[n - 1]) {
				cout << "YES";
			}
			else {
				cout << "NO";
			}
		}
		if(tc > 0) {
			cout << '\n';
		}
	}
}



(p-1)! = -1 mod p
HGGGGHH
HHGGGHH

