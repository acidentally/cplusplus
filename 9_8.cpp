#include <bits/stdc++.h>
using namespace std;

vector<int> temporaryArray;
int n;

void QuickSort(temporaryArray) {
	
}

int main() {
	int n, m; cin >> n >> m;
	int d, nam;
	for(d = 1; d <= n - 2; d++) {
		for(nam = 1; nam <= n - 2; nam++) {
			if(3 * (m - 5*d - 3*nam) == n - nam - d) {
				cout << d << ' ' << nam << ' ' << n - nam - d;
				d = n - 2;
			}
		}
	}
}