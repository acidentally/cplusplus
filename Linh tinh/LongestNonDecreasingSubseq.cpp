/*
Good luck for those who are trying your best
May the most glorious victory come
File name: cses_1145_fastLCS.cpp
Code by : acident / lckintrovert
Created since : 24/08/2023 ~~ 14:29:19
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
int const maxn = 2e5 + 10;
int const INF = 1e18;

int n, x, ans = 0;
vi a;
void solve()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        int id = upper_bound(all(a), x) - a.begin() - 1;
        // for(auto s : a) cerr << s << ' ';
        // cerr << id << ' ' << endl;
        if(a.empty()) a.pb(x);
        if (id + 1 >= a.size())
            a.pb(x);
        else {
            a[id + 1] = x;
        }
    }
    // for(auto s : a) cerr << s << ' ';
    cout << a.size();
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