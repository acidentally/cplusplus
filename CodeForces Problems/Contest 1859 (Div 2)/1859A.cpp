/*
Good luck for those who are trying your best
May the most glorious victory come
File name: 1859B.cpp
Code by : acident / lckintrovert
Created since : 12/08/2023 ~~ 21:36:03
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
int const maxn = 200;
int const INF = 1e18;

int n;
int a[maxn] = {};
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for (int i = n - 1; i >= 1; i--)
    {
        if (a[i] < a[i + 1])
        {
            cout << i << ' ' << n - i << endl;
            for (int j = 1; j <= i; j++)
            {
                cout << a[j] << ' ';
            }
            cout << endl;
            for (int j = i + 1; j <= n; j++)
            {
                cout << a[j] << ' ';
            }
            cout << endl;
            return;
        }
    }
    cout << -1 << endl;
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