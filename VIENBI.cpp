#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base:: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int A, B, C; cin >> A >> B >> C;
	if((B + C) % 2) cout << "NO";
	else cout << "YES";
}