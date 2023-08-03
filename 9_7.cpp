#include <bits/stdc++.h>
using namespace std;

int n, searchFor;
vector<int> temporaryArray;

void binarySearch(int l, int r) {
	int mid = (l + r) / 2;
	if(searchFor > temporaryArray[mid]) {
		binarySearch(mid + 1, r);
	}
	else if(searchFor < temporaryArray[mid]) {
		binarySearch(l, mid - 1);
	}
	else {
		cout << mid + 1;
	}
}

int main() {

	cin >> n >> searchFor;
	int temp; 
	for(int i = 0; i < n; i++) {
		cin >> temp;
		temporaryArray.push_back(temp);
	}
	binarySearch(0, n - 1);
}