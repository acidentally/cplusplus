/*
Good luck for those who are trying your best
May the most glorious victory come
File name: 1860D.cpp
Code by : acident / lckintrovert
Created since : 24/08/2023 ~~ 22:24:47
Literally the worst cp-er ever
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define uint unsigned long long
#define dub double
#define fi first
#define se second
#define vvi vector<vector<int>>
#define endl '\n'
#define pb emplace_back
#define pf push_front
#define all(a) a.begin(), a.end()
#define mp make_pair
#define YES cout << "YES\n";
#define NO cout << "NO\n";
#define ins insert

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
int const mod = 1e9 + 7;
int const maxn = 1e5 + 10;
int const INF = 1e18;

int n;
void solve()
{
    cin >> n;
    int k = (int)sqrt(n << 1);
    cout << k << ' ';
    int d = k * (k - 1) >> 1;
    while (d < n) {
        d += k;
        k++;
    }
    while (d > n) {
        k--;
        d -= k;
    }
    cout << k << ' ';
    cout << n + k - d << endl;
    // k^2 - k - 2n = 0;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    // File?
    int tc;
    cin >> tc;
    while (tc--)
        solve();
}