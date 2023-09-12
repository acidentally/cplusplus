/*
Good luck for those who are trying your best
May the most glorious victory come
File name: 1867B.cpp
Code by : acident / lckintrovert
Created since : 11/09/2023 ~~ 21:42:26
Literally the worst cp-er ever
*/
#include <bits/stdc++.h>
using namespace std;
 
#define int                 long long
#define uint                unsigned long long
#define dub                 double
#define fi                  first
#define se                  second
#define endl                '\n'
#define pb                  push_back
#define pf                  push_front
#define eb                  emplace_back
#define ins                 insert
#define mp                  make_pair
#define all(a)              a.begin(), a.end()
#define YES                 cout << "YES\n"
#define NO                  cout << "NO\n"
#define coutdub(x)          cout << fixed << setprecision(x)
#define cerrdub(x)          cerr << fixed << setprecision(x)
 
//#define _USE_MATH_DEFINES // If meth .__.
 
template<class T1, class T2> void maximize(T1& a, T2 b) {a = max(a, b);}
template<class T1, class T2> void minimize(T1& a, T2 b) {a = min(a, b);}
template<class T1> T1 abs(T1 a) {return max(a, -a);}
 
typedef vector<int>         vi;
typedef vector<vi>          vvi;
typedef pair<int, int>      pi;
typedef pair<int, pi>       pii;
int const mod       =       1e9 + 7;
int const maxn      =       1e5 + 100;
int const INF       =       1e18;
 
int n;
bool a[maxn] = {}, check[maxn] = {};
char x;
void solve() {
    cin >> n;
    memset(check, 0, n + 10);
    for(int i = 1; i <= n; i++) {
        cin >> x;
        if(x == '1') a[i] = 1;
        else a[i] = 0;
    }
    int cntDiff = 0, cntSame; 
    for(int l = 1; (l << 1) <= n; l++) {
        if(a[l] != a[n - l + 1]) cntDiff++;
    }
    cntSame = (n >> 1) - cntDiff;

    for(int i = 0; i <= n; i++) {
        if(i < cntDiff) {cout << 0; continue;}
        //sau khi đổi cntDiff lần thì xâu đã trở thành palindrome
        //khi đó còn i - cntDiff lần đổi và chỉ đổi được nhiều nhất n - cntDiff lần cho cntSame cặp
        int left = i - cntDiff;
        if((left % 2) <= (n % 2) && (left >> 1) <= cntSame) cout << 1;
        else cout << 0;
    } cout << endl;
    //101011
    //1****1
    
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    int tc; cin >> tc;
    while(tc--)
    solve();
}

/*A place to scribble thoughts

*/