/*
Good luck for those who are trying your best
May the most glorious victory come
File name: LCS.cpp
Code by : acident / lckintrovert
Created since : 23/08/2023 ~~ 17:37:49
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
int const maxn      =       1e3 + 10;
int const INF       =       1e18;
 
string A, B;
int dp[maxn][maxn] = {};
void solve() {
    cin >> A >> B;
    //  a b c d e
    //a
    //c 
    //e
    if(A.size() > B.size()) swap(A, B);
    int szA = A.size(), szB = B.size();
    A = '#' + A;
    B = '#' + B;
    for(int i = 1; i <= szA; i++) {
        for(int j = 1; j <= szB; j++) {
            // dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            if(A[i] == B[j]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cerr << szA << endl;
    cerr << dp[szA][szB];
    cout << szB - dp[szA][szB];
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}

/*A place to scribble thoughts

*/