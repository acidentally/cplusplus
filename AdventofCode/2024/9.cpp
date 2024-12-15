/*
Good luck for those who are trying your best
May the most glorious victory come
File name: 9.cpp
Code by : acident / lckintrovert
Created since : 15/12/2024 ~~ 18:38:36
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
const int maxn      =        1e5 + 10;
const int INF       =        1e18;

struct node {
    node *next, *pre;
    int val, length;
    node(): val(-1), length(0), next(nullptr), pre(nullptr) {}
    node(int val_, int length_): val(val_), length(length_), next(nullptr), pre(nullptr) {}
};

string s;
inline void solve() {
    cin >> s;
    node *StartNode = new node(0, s[0] - '0');
    node *pre = StartNode;
    bool swi = 0;
    for(int i = 1, val = 1; i < s.size(); i++) {
        int length = s[i] - '0';
        node *cur;
        if(swi) { // Is a number
            cur = new node(val++, length);
        } else { // Is not a number
            cur = new node(-1, length);
        }

        pre -> next = cur;
        cur -> pre = pre;
        pre = cur;
        swi = !swi;
    }
    node *EndNode = pre;


    for(node *FileBlock = EndNode; FileBlock != nullptr; FileBlock = FileBlock -> pre) 
    {
        if(FileBlock -> val == -1) 
        { // Check if the current block is a valued block
            continue;
        } 
        
        for(node *FreeSpace = StartNode; FreeSpace != FileBlock; FreeSpace = FreeSpace -> next) 
        { // Check if the current space is an empty block
            if(FreeSpace -> val != -1) continue;
            else if(FileBlock -> length > FreeSpace -> length) continue;
            else
            {
                int excessLength = (FreeSpace -> length) - (FileBlock -> length);
                int val = FileBlock -> val;

                node *insNode = new node(val, FileBlock -> length);
                node *beforeFreeSpace = FreeSpace -> pre;
                node *afterFreeSpace = FreeSpace -> next;

                insNode -> next = afterFreeSpace;
                afterFreeSpace -> pre = insNode;

                insNode -> pre = beforeFreeSpace;
                beforeFreeSpace -> next = insNode;    

                if(excessLength != 0) 
                {
                    node *additionalNode = new node(-1, excessLength);
                    insNode -> next = additionalNode;
                    additionalNode -> pre = insNode;

                    additionalNode -> next = afterFreeSpace;
                    afterFreeSpace -> pre = additionalNode;
                }

                FileBlock -> val = -1;
                break;
            }
        } 
    }

    int curIdx = 0, ans = 0;
    for(node *Block = StartNode; Block != nullptr; Block = Block -> next)
    {
        if(Block -> val == -1) {}
        else 
        {
            int val = Block -> val;
            int len = Block -> length;
            ans += (2 * curIdx + len - 1) * len * val / 2;
        }

        curIdx += Block -> length;
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