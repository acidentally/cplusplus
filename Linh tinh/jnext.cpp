#inclued <bits/stdc++.h>
using namespace std;

int main() {
	int tc; cin >> tc;
	int n;
	while(tc--) {
		cin >> n;
		int digits[n];
		int posGreater = 0;
		for(int i = 0; i < n; i++) {
			cin >> digits[i];
			if(i > 1 && digits[i] > digits[i - 1]) {
				posGreater = i;
			}
		}
		
	}
}

// 9998888888765454565432457654321 
// 99988888887654545654324 5 7654321
