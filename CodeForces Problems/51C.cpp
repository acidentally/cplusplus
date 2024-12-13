/*
Good luck for those who are trying your best
May the most glorious victory come
File name: 51C.cpp
Code by : acident / lckintrovert
Created since : 29/11/2024 ~~ 13:50:37
Literally the worst cp-er ever
*/
#include <bits/stdc++.h>
using namespace std;

#define int                  long long
#define uint                 unsigned long long
#define dub                  double
#define fi                   first
#define se                   second
#define endl                 '\n'
#define pb                   push_back
#define pf                   push_front
#define eb                   emplace_back
#define ins                  insert
#define mp                   make_pair
#define all(a)               a.begin(), a.end()
#define YES                  cout << "YES\n"
#define NO                   cout << "NO\n"
#define coutdub(x)           cout << fixed << setprecision(x)
#define cerrdub(x)           cerr << fixed << setprecision(x)

//#define _USE_MATH_DEFINES // If meth .__.

template<class T1, class T2> bool maximize(T1& a, T2 b) {if(b > a) {a = b; return 1;} return 0;}
template<class T1, class T2> bool minimize(T1& a, T2 b) {if(b < a) {a = b; return 1;} return 0;}
template<class T1> T1 abs(T1 a) {return max(a, -a);}

typedef pair<int, int>       pi;
typedef pair<int, pi>        pii;
typedef vector<int>          vi;
typedef vector<vi>           vvi;
typedef vector<pi>           vp;
const int mod       =        1e9 + 7;
const int maxn      =        2e5 + 10;
const int INF       =        1e18;

int n, a[maxn] = {};
set<int> st;
inline void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] <<= 1;
        st.insert(a[i]);
    }
    sort(a, a + n);
    int l = a[0], r = a[n - 1];

    if(st.size() <= 3) {
        cout << 0 << endl;
        int cnt = 0;
        for(auto s : st) {
            coutdub(5) << dub(s / 2.0) << ' ';
            cnt++;
        }

        while(cnt < 3) {
            coutdub(5) << dub(*st.begin()) / 4.0 << ' ';
            cnt++;
        }

        return;
    }

    while (l != r) {
        int mid = (l + r) >> 1;
        int segment = 1, cur = a[0];
        // cerr << l << ' ' << r << endl;
        for (int i = 0; i < n; i++) {
            if(a[i] > cur + mid) {
                cur = a[i];
                segment++;
            }
        }

        if (segment < 3) r = mid - 1;
        else if (segment > 3) l = mid + 1;
        else r = mid;
    }
    int temp_l = 0;
    int cur = a[0], cnt = 0;
    for (int i = 1; i < n; i++) {
        if(a[i] > cur + l) {
            maximize(temp_l, a[i - 1] - cur);
            cur = a[i];
        }
    }
    maximize(temp_l, a[n - 1] - cur);
    coutdub(5) << dub(temp_l) / 4.0 << endl;

    cur = a[0], cnt = a[0], l = temp_l, cnt = 0;
    for(int i = 1; i < n; i++) {
        if(a[i] > cur + l) {
            coutdub(5) << dub(a[i - 1] + cur) / 4.0 << ' ';
            cnt++;
            cur = a[i];
        }
    }
    while(cnt < 3) {
        coutdub(5) << dub(a[n - 1] + cur) / 4.0 << ' ';
        cnt++;
    }

}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}

/*A place to scribble thoughts

*/