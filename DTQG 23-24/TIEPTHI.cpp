#include <bits/stdc++.h>
using namespace std;

#define int long long
#define dub long double
#define fi first
#define se second
#define pb push_back
#define ins insert
#define endl '\n'
#define mp make_pair

typedef vector<int> vi;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;
const int INF = 1e15;
const int maxn = 1e5 + 10;

template<class T1> bool minimize(T1 &a, T1 b) {if(b < a){a = b; return true;} else return false;}
template<class T1> bool maximize(T1 &a, T1 b) {if(b > a){a = b; return true;} else return false;}

int n, u, v;
vector<pi> a;
map<int, int> m, m2;
void solve(void) {
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> u >> v;
        m[u] += 1; m[v] -= 1;
    }
    int cur = 0, pre = 0;
    pi ans = mp(0, 0);
    map<int, int>::iterator ptr = m.begin();
    while(ptr != m.end()) {
        cur += ptr -> se;
        a.pb(mp(pre, ptr -> fi));
        pre = ptr -> fi;
        m2[ptr -> fi] = cur;
        ptr++;
    }
    ptr = m2.begin();
    while(ptr != m2.end()) {
        if(maximize(ans.fi, ptr -> se)) ans.se = ptr -> fi;
        ptr++;
    }

    cout << ans.fi << endl;
    for(int i = 0; i < a.size(); i++) {
        if(a[i].fi == ans.se) {
            cout << a[i].fi << ' ' << a[i].se; return;
        }
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("TIEPTHI.INP", "r", stdin);
    freopen("TIEPTHI.OUT", "w", stdout);
    solve();
}


