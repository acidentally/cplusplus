#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()
#define dub long double
#define ins insert

template<class T1> bool maximize(T1 &a, T1 b) {if(b > a) {a = b; return 1;} return false;}
template<class T1> bool minimize(T1 &a, T1 b) {if(b < a) {a = b; return 1;} return false;}
const int maxn = 1e5;
const int mod = 1e9 + 7;

typedef pair<int, int> pi;
typedef vector<int> vi;

int m, k, u, v;
int col[maxn + 10] = {}, row[maxn + 10] = {};
int diagDown[maxn << 1 + 10] = {}, diagUp[maxn << 1 + 10] = {};
void solve() {
    cin >> m >> k;
    for(int i = 1; i <= m; i++) {
        cin >> u >> v;
        if(++row[u] == k) {
            cout << i;
            return;
        }
        if(++col[v] == k) {
            cout << i;
            return;
        }
        if(++diagUp[u + v - 1] == k) {
            cout << i;
            return;
        }
        if(++diagDown[v - u + maxn] == k) {
            cout  << i;
            return;
        }
    }
    cout << -1;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("ROBOT.INP", "r", stdin);
    freopen("ROBOT.OUT", "w", stdout);

    solve();
}

/*
TEST CASE 1:
4 3
1 2
3 4
3 2
4 5
---> 4

TEST CASE 2:
7 4
3 1
2 2
4 1
3 2
2 3
1 4
1 3
---> 6
*/
