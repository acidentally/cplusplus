/*
Good luck for those who are trying your best
May the most glorious victory come
File name: AovRandomizer.cpp
Code by : acident / lckintrovert
Created since : 22/02/2024 ~~ 20:23:20
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

// char dodon[30][30] = {"Mina", "Baldum", "Gildur", "Skud", "Arum", "Grakk", "Maloch", "Taara", "Toro", "Ormarr", "Y'bneth", "Xeniel", "Wiro", "Cresht", "Arduin", "Lumburr", "Omega", "Max", "Dextra", "Roxie", "Ata", "Chaugnar", "Thane", "TeeMee"};
// char dausi[50][30] = {"Butterfly", "Yena", "Veres", "Trieu Van", "Zuka", "Airi", "Skud", "Amily", "Lu Bo", "Omen", "Maloch", "Florentino", "Taara", "Richter", "Qi", "Superman", "Astrid", "Volkath","Ryoma", "Wiro", "Errol", "Arduin", "Tachi", "Allain", "Rourke", "Zephys", "Yan", "Wonder Woman", "Dextra", "Roxie", "Arthur", "Kil'Groth", "Bijan"};
// char satthu[30][30] = {"Butterfly", "Liliana", "Nakroth", "Zuka", "Airi", "Ngo Khong", "Zill", "Zata", "Raz", "Quillen", "Murad", "Paine", "Qi", "Kriknak", "Astrid", "Volkath", "Ryoma", "Aoi", "Enzo", "Sinestrea", "Keera", "Zephys", "Yan", "Kaine", "The Flash", "Bright"};
// char phapsu[30][30] = {"Veera", "Krixi", "Mganga", "Kahlii", "Dieu Thuyen", "Azzen'Ka", "Aleister", "Natalya", "Jinna", "Ilumia", "Preyta", "Raz", "Lauriel", "Ignis", "Zill", "Tulen", "Liliana", "The Flash", "Marja", "D'arcy", "Ishar", "Dirak", "Zata", "Lorion", "Iggy", "Annette", "Sephera"};
// char xathu[30][30] = {"Valhein", "Violet", "Yorn", "Fennik", "Slimz", "Joker", "Tel'Annas", "Moren", "Lindis", "Wisp", "Elsu", "Hayate", "Capheny", "Celica", "Eland'orr", "Laville", "Thorne", "Bright", "Erin"};
// char trothu[30][30] = {"Alice", "Chaugnar", "Helen", "TeeMee", "Xeniel", "Annette", "Sephera", "Rouie", "Krizzix", "Zip", "Mina", "Baldum", "Gildur", "Arum", "Grakk", "Toro", "Ishar", "Aya", "Cresht", "Lumburr", "Omega", "Ming"};
int choice, lang;
void interface_vnm() {
    printf("RANDOM TUONG LIEN QUAN / AOV HEROES RANDOM");
    printf("\n----------------------------------------------");
    printf("\nChon vi tri: ");
    printf("\n1. Do don");
    printf("\n2. Dau si");
    printf("\n3. Sat thu");
    printf("\n4. Phap su");
    printf("\n5. Xa thu");
    printf("\n6. Tro thu");
    printf("\n0. Ket thuc chuong trinh");
    printf("\nLua chon cua ban: ");
    scanf("%d", &choice);
}
void interface_eng() {
    printf("RANDOM TUONG LIEN QUAN / AOV HEROES RANDOM");
    printf("\n----------------------------------------------");
    printf("\nChoose a position: ");
    printf("\n1. Tank");
    printf("\n2. Warrior");
    printf("\n3. Assassin");
    printf("\n4. Mage");
    printf("\n5. Marksman");
    printf("\n6. Support");
    printf("\n0. End program");
    printf("\nYour choice: ");
    scanf("%d", &choice);
}
void Lang() {
    printf("\nChon ngon ngu / Choose a language:");
    printf("\n1. Tieng Viet / Vietnamese");
    printf("\n2. Tieng Anh / English");
    printf("\nLua chon cua ban / Your choice: ");
    scanf("%d", &lang);
    if(lang == 1) {interface_vnm(); return;}
    else if(lang == 2) {interface_eng(); return;}
    else {
        printf("Gia tri khong ton tai. Hay chon lai! / Invalid value. Please choose again!");
        Lang();
    }
}

signed main() {
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    // init();
    printf("RANDOM TUONG LIEN QUAN / AOV HEROES RANDOM");
    printf("\n----------------------------------------------");
    Lang();

}

/*A place to scribble thoughts

*/