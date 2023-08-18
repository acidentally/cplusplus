/*
Good luck for those who are trying your best
May the most glorious victory come
File name: ZAlgo.cpp
Code by : acident / lckintrovert
Created since : 04/08/2023 ~~ 15:34:21
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
 
int n;
bool b[100][100] = {};
void solve() {
    cin >> n;
    memset(b, 1, sizeof(b));
    for(int i = 1; i <= 100; i++) {
        b[i][i] = 0;
    }
    for(int j = 2; j <= 100; j++) {
        for(int i = j - 1; i >= 1; i--) {
            int check = 0;
            for(int k = 1; i * k <= j; k++) {
                int x = min(i, j - i * k), y = max(i, j - i * k);
                //b[x][y] mà thua thì b[i][j] thắng
                //b[x][y] thắng hết thì b{i}[j] thua
                if(b[x][y] == 0) check = 1;
            }
            b[i][j] = check;
        }
    }
    for(int i = 1; i <= 100; i++) {
        int cnt = 0;
        for(int j = 1; j <= i; j++) {
            if(b[j][i] == 0) cnt++;
        } cout << cnt << ',';
    }
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    //File?
    solve();
}