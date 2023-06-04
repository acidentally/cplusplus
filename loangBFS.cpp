#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second
#define vi vector<int>
#define vvi vector< vector<int> >
#define endl '\n'
#define fr(i,a,b) for(int i = a; i < b; i++) 
#define f(i,a) for(int i = 0; i < a; i++)


int a[100][100] = {};
bool check[100][100] = {};
int area, maxArea = 0;
int n, m;
void DFS(int i, int j) {
	if(check[i][j]) return;
	else {
		area++;
		check[i][j] = true;
		if(i + 1 < n && a[i + 1][j] == 0) DFS(i + 1, j);
		if(i - 1 >= 0 && a[i - 1][j] == 0) DFS(i - 1, j);
		if(j + 1 < m && a[i][j + 1] == 0) DFS(i, j + 1);
		if(j - 1 >= 0 && a[i][j - 1] == 0) DFS(i, j - 1);
	}
	return;
}

signed main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(NULL); cout.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	int d = 0, maxArea = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if(!check[i][j] && a[i][j] == 0) {
				area = 0;
				d++;
				DFS(i, j);
				maxArea = max(maxArea, area);
			}
		}
	}
	cout << d << endl << maxArea;
}