/*
Good luck for those who are trying your best
May the most glorious victory come

File name: BDuongHe_stones.cpp
Code by : acident / lckintrovert
Created since : 2023-08-04 ~~ 08:16:18
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
int const INF = LLONG_MAX;

int n, q, x, u, v;
int sum[maxn] = {};
priority_queue<int, vi, greater<int>> qu;
vi a(1, 0);
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        qu.push(x);
        sum[i] = x + sum[i - 1];
    }
    while (!qu.empty())
    {
        a.pb(qu.top());
        qu.pop();
    }
    for (int i = 1; i <= n; i++)
        a[i] += a[i - 1];
    cin >> q;
    while (q--)
    {
        cin >> x >> u >> v;
        if (x == 1)
            cout << sum[v] - sum[u - 1];
        else
            cout << a[v] - a[u - 1];
        cout << endl;
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("stones.inp", "r", stdin);
    // freopen("stones.out", "w", stdout);
    solve();
}
