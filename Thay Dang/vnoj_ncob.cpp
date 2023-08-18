/*
Good luck for those who are trying your best
May the most glorious victory come
File name: vnoj_ncob.cpp
Code by : acident / lckintrovert
Created since : 18/08/2023 ~~ 15:35:54
Literally the worst cp-er ever
*/
#include <bits/stdc++.h>
using namespace std;
 
#define int                 long long
#define uint                unsigned long long
#define dub                 double
#define fi                  first
#define se                  second
#define vvi                 vector< vector<int> >
#define endl                '\n'
#define pb                  emplace_back
#define pf                  push_front
#define all(a)              a.begin(), a.end()
#define mp                  make_pair
#define YES                 cout << "YES\n";
#define NO                  cout << "NO\n";
#define ins                 insert
 
typedef vector<int>         vi;
typedef pair<int, int>      pi;
typedef pair<int, pi>       pii;
int const mod       =       1e9 + 7;
int const maxn      =       1e5 + 10;
int const INF       =       1e18;
 
int x, y;
int compute(int n) {
    //2 * (n - 1) - floor((n - 1) * r);
    int ans = (n - 1) << 1;
    double n_ = (double) n - 1;
    n_ = n_ * (1.0 + sqrt(5)) / 2.0;
    n = (int)n_;
    return ans - n;
}
void solve() {
    while(cin >> x) {
        cin >> y;
        if(x == y && y == 0) return;
        if(x == 1 && y == 1) {
            cout << 'S' << endl;
            continue;
        }
        int mini = min(x, y), maxi = max(x, y);
        x = mini; y = maxi;
        int ans = compute(y + 1);
        if(x <= y - ans) cout << 'T';
        else cout << 'S';
        cout << endl;
    }
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
    // cout << compute(50);
    // cout << (1.0 + sqrt(5))/2.0;
}