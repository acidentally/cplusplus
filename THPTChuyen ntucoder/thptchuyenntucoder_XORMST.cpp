/*
Good luck for those who are trying your best
May the most glorious victory come
Code by : acident / lckintrovert
Literally the worst cp-er ever
*/

#include <bits/stdc++.h>
using namespace std;

#define int             long long
#define uint             unsigned long long
#define fi                first
#define se                 second
#define vvi             vector< vector<int> >
#define endl             '\n'
#define pb                 push_back
#define pf                 push_front
#define all(a)             a.begin(), a.end()
#define mp                 make_pair
#define YES             cout<<"YES\n";
#define NO                 cout<<"NO\n";
#define space           ' '
#define ins             insert
typedef vector<int>     vi;
typedef pair<int, int>     pi;
int const mod         =     1e9 + 7;
int const maxn         =     2e5 + 10;
int const INF         =     LLONG_MAX;

struct DSU {
    vi p;
    DSU() : p(maxn) {}
    DSU createDSU(int l) {
        DSU tem;
        // iota(tem.p.begin() + 1, tem.p.begin() + l + 1, 1);
        for(int i = 0; i <= l; i++) {
            tem.p[i] = i;
        }
        return tem;
    }
    int find(int v) {
        if(v == p[v]) return v;
        return p[v] = find(p[v]);
    }
    void make(int i) {
        p[i] = i;
    }
    void connect(int u, int v) {
        u = find(u); v = find(v);
        if(u < v) swap(u, v);
        p[u] = v;
    } //<---------- DSU datatstructure that performs the necessary info
} dsu1;            //<---------- for the MST

struct Trie{
    struct Node{
        int child[2];
        int exist;
        int id, cnt, val;
    } nodes[15*maxn];

    int cur;
    Trie() : cur(0) {
        memset(nodes[0].child, -1, sizeof(nodes[cur].child));
        nodes[0].exist = nodes[0].id = 0;
        nodes[0].val = -1;
    };

    int new_node() {
        cur++;
        memset(nodes[cur].child, -1, sizeof(nodes[cur].child));
        nodes[cur].exist = nodes[cur].id = 0;
        return cur;
    }

    void add_number(int x, int id) {
        int pos = 0;
        for (int i = 30; i >= 0; i--) {
            int c = (x >> i) & 1;
            if (nodes[pos].child[c] == -1) nodes[pos].child[c] = new_node();
            pos = nodes[pos].child[c];
            nodes[pos].cnt++;
        }
        nodes[pos].exist++;
        nodes[pos].id = id;
        nodes[pos].val = x;
    }

    void delete_number(int x) {
        if (find_number(x) == false) return;
        int pos = 0;
        for (int i = 30; i >= 0; i--) {
            int c = (x >> i) & 1;

            int tmp = nodes[pos].child[c];
            nodes[tmp].cnt--;
            if (nodes[tmp].cnt == 0) {
                nodes[pos].child[c] = -1;
                return;
            }

            pos = tmp;
        }
        nodes[pos].exist--;
    }

    bool find_number(int x) {
        int pos = 0;
        for (int i = 30; i >= 0; i--) {
            int c = (x & (1 << i) ? 1 : 0);
            if (nodes[pos].child[c] == -1) return false;
            pos = nodes[pos].child[c];
        }
        return (nodes[pos].exist != 0);
    }

    pi findxor(int x) {
        int pos = 0;
        for(int i = 30; i >= 0; i--) {
            if(nodes[pos].exist) {
                return {(x ^ nodes[pos].val), nodes[pos].id};
            }
            int c = ((x >> i) & 1);

            if(nodes[pos].child[c] != -1) {
                pos = nodes[pos].child[c];
            }
            else {
                pos = nodes[pos].child[1 - c];
            }
        }
        return {(x ^ nodes[pos].val), nodes[pos].id};
    }
} xortrie;

int n;
int A[maxn] = {};
void solve() {
    cin >> n;
    dsu1 = dsu1.createDSU(n);
    for(int i = 1; i <= n; i++) {
        cin >> A[i];
        xortrie.add_number(A[i], i);
    }
    int ans = 0;
    while(1) {
        vi a[maxn] = {};
        bool check[maxn] = {};
        int tplt = n;
        for(int i = 1; i <= n; i++) {
            int temp = dsu1.find(i);

            a[temp].pb(i);
            if(check[temp]) tplt--;
            check[temp] = true;
        } 

        if(tplt == 1) break;
        //~~ Kiểm tra xem đồ thị hiện giờ có phải là cây hay chưa ~~ //
        bool check2[maxn] = {};
        for(int i = 1; i <= n; i++) {
            if(a[i].empty() || check2[i]) continue; 
            //Nếu không có dsu có gốc tại i, ta xét tiếp
            for(int j = 0; j < a[i].size(); j++) {
                check2[a[i][j]];
                xortrie.delete_number( A[a[i][j]] );
            } //Lần lượt xóa mọi số trong dsu gốc i khỏi trie

            pi cur = mp(INF, 0ll);
            pi instant;
            for(int k = 0; k < a[i].size(); k++) {
                instant = xortrie.findxor(A[a[i][k]]); 
                //Tìm mọi giá trị xor để tìm gtrí xor nhỏ nhất
                //không có trong gốc dsu;
                if(instant.fi < cur.fi) {
                    cur = instant;
                }
            }

            if(cur.fi != 0 && dsu1.find(i) != dsu1.find(cur.se)) {
                dsu1.connect(i, cur.se);
                ans += cur.fi;
            }
            //Cập nhật ans và nối dsu lại hai thành phần
         
            for(int j = 0; j < a[i].size(); j++) {
                xortrie.add_number(A[a[i][j]], a[i][j]);
            }
            //Thêm lại các phần tử vào trie;
        }
    }
    cout << ans;
}
signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    solve();
}