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

template<class T1> bool minimize(T1 &a, T1 b) {if(b < a){a = b; return true;} else return false;}
template<class T1> bool maximize(T1 &a, T1 b) {if(b > a){a = b; return true;} else return false;}

typedef vector<int> vi;
typedef pair<int, int> pi;
const int mod = 1e9 + 7;
const int INF = 1e15;
const int maxn = 1e5 + 10;
vi ans;
void init() {
    ans.pb(0); ans.pb(1); ans.pb(3); ans.pb(5); ans.pb(7); ans.pb(9);
    ans.pb(33); ans.pb(99); ans.pb(313); ans.pb(585); ans.pb(717);
    ans.pb(7447); ans.pb(9009); ans.pb(15351); ans.pb(32223);
    ans.pb(39993); ans.pb(53235); ans.pb(53835); ans.pb(73737);
    ans.pb(585585); ans.pb(1758571); ans.pb(1934391);
    ans.pb(1979791); ans.pb(3129213); ans.pb(5071705);
    ans.pb(5259525); ans.pb(5841485); ans.pb(13500531);
    ans.pb(719848917); ans.pb(910373019); ans.pb(939474939);
}
string bin(int k) {
    if(k == 0) return "0";
    string s = "";
    while(k) {
        s = (char)((k & 1) + '0') + s;
        k >>= 1;
    }
    return s;
}
int n;
void solve(void) {
    cin >> n;
    init();
    for(int i = 0; i < ans.size(); i++) {
        if(ans[i] > n) break;
        cout << ans[i] << ' ' << bin(ans[i]) << endl;
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("DBDOIXUNG.INP", "r", stdin);
    freopen("DBDOIXUNG.OUT", "w", stdout);
    solve();
}
