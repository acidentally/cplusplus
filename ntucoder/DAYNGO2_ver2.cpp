/*
Good luck for those who are trying your best
May the most glorious victory come
File name: DAYNGO2_ver2.cpp
Code by : acident / lckintrovert
Created since : 02/09/2023 ~~ 15:46:31
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
#define YES                 cout << "YES\n"
#define NO                  cout << "NO\n"
#define ins                 insert
#define coutdub(x)          cout << fixed << setprecision(x)
 
typedef vector<int>         vi;
typedef pair<int, int>      pi;
typedef pair<int, pi>       pii;
int const mod       =       1e9 + 7;
int const maxn      =       1e5 + 10;
int const INF       =       1e18;
 
int n, a[maxn] = {}, furRight[maxn] = {}, m, u, v;
string s;
char x;
stack<int> q;
queue<pi> save;
void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        x = s[i - 1];
        a[i] = a[i - 1];
        furRight[i] = n;
        if(x == '(') a[i]++;
        else a[i]--;

        while(!q.empty() && a[i] < a[q.top() - 1]) {
            furRight[q.top()] = i;
            q.pop();
        } 
        q.push(i);
    }
    while(m--) {
        cin >> u >> v;
        // cerr << furRight[u] << endl;
        if(a[u - 1] == a[v] && furRight[u] >= v) YES;
        else NO;
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