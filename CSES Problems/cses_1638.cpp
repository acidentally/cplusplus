/*
Good luck for those who are trying your best
May the most glorious victory come
File name: cses_1638.cpp
Code by : acident / lckintrovert
Created since : 23/08/2023 ~~ 17:22:19
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
#define coutdub(x) cout << fixed << setprecision(x)

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
int const mod = 1e9 + 7;
int const maxn = 1e3 + 10;
int const INF = 1e18;

int n;
bool a[maxn][maxn] = {};
int dp[maxn][maxn] = {};
char x;
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> x;
            if (x == '*')
                a[i][j] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[1][i])
            break;
        dp[1][i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i][1])
            break;
        dp[i][1] = 1;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 2; j <= n; j++)
        {
            if (a[i][j])
                continue;
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
        }
    }
    cout << dp[n][n] % mod;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    // File?
    solve();
}

/*A place to scribble thoughts

*/