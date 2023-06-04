#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin >> t;
	int n;

	while(t--) {
		cin >> n;
		int a[n][n];
		int count = 1;
		if(n % 2 == 0) {
			for(int i = 0; i < n; i++) {
				if(i % 2 == 0) {
					for(int j = 0; j < n; j += 2) {
						a[i][j] = count;
						a[i][j + 1] = n * n - count + 1;
						count++;
					}
				}

				else {
					for(int j = n - 1; j >= 0; j -= 2) {
						a[i][j] = count;
						a[i][j - 1] = n * n - count + 1;
						count++;
					}
				}
			}
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					cout << a[i][j] << " ";
				}
				cout << endl;
			}
		}

		else {
			for(int i = 0; i < n; i++) {
				if(i % 2 == 0) {
					for(int j = 0; j < n; j += 2) {
						a[i][j] = count;
						if(j  + 1 < n) {
							a[i][j + 1] = n * n - count + 1;
							count++;
						}
					}
				}

				else {
					for(int j = n - 1; j >= 0; j -= 2) {
						a[i][j] = n * n - count + 1;
						count++;
						if(j - 1 >= 0) { 
							a[i][j - 1] = count;

					}
				}
			}
		}
		for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					cout << a[i][j] << " ";
				}
				cout << endl;
			}
		}
	}
}