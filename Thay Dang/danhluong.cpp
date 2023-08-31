/*
Good luck for those who are trying your best
May the most glorious victory come
File name: danhluong.cpp
Code by : acident / lckintrovert
Created since : 28/08/2023 ~~ 16:29:38
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
#define coutdub(x)          cout << fixed << setprecision(x)
 
typedef vector<int>         vi;
typedef pair<int, int>      pi;
typedef pair<int, pi>       pii;
int const mod       =       1e9 + 7;
int const maxn      =       1e5 + 10;
int const INF       =       2e9 + 10;
 
int n, k, x;
vi odd, even, sumOdd, sumEven;
void solve() {
    cin >> n >> k;
    odd.pb(-INF); even.pb(-INF);
    sumOdd.pb(0); sumEven.pb(0);
    for(int i = 1; i <= n; i++) {
        cin >> x;
        if(i & 1) odd.pb(x);
        else even.pb(x);
    }
    int osz = n - (n >> 1);
    n >>= 1;
    sort(all(odd));
    sort(all(even));
    for(int i = 1; i <= osz; i++) {
        sumOdd.pb(sumOdd[i - 1] + odd[i]);
    }
    for(int i = 1; i <= n; i++) {
        sumEven.pb(sumEven[i - 1] + even[i]);
    }
    int ans = LLONG_MAX;
    for(int i = 1; i <= n; i++) { //iterate trên even
        int curHeight = even[i],
            compute = (sumEven[n] - sumEven[i]) - (n - i) * curHeight + i * curHeight - sumEven[i]; //Làm trên even
        int targetHeight = curHeight + k; //Làm trên odd
        int id = lower_bound(all(odd), targetHeight) - odd.begin();
        compute += (sumOdd[osz] - sumOdd[id] - (osz - id) * targetHeight + 
        id * targetHeight- sumOdd[id]);
        ans = min(ans, compute);
    }
    k = -k;
    for (int i = 1; i <= n; i++)
    { // iterate trên even
        int curHeight = even[i],
            compute = (sumEven[n] - sumEven[i]) - (n - i) * curHeight + i * curHeight - sumEven[i]; // Làm trên even
        int targetHeight = curHeight + k;                                                           // Làm trên odd
        int id = lower_bound(all(odd), targetHeight) - odd.begin();
        compute += (sumOdd[osz] - sumOdd[id] - (osz - id) * targetHeight +
                    id * targetHeight - sumOdd[id]);
        ans = min(ans, compute);
    }
    cout << ans;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}

/*A place to scribble thoughts

*/