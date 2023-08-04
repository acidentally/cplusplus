//http://ntucoder.net/Problem/Details/4454
#include <bits/stdc++.h>
using namespace std;


int main() {
	ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int temp, i;
	bool Squares[31623];

	while(n--) {
		cin >> temp;
		i = (int) sqrt(temp);
		if(i * i == temp) Squares[i] = true;
	}

	int j = 0;
	while(Squares[j]) {
		j++;
	}
	cout << j * j;
}


#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
}