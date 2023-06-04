#include<iostream>
#include<algorithm>
#include<cstdio>
#define fr(a,b,c) for (a=b;a<=c;a++)
#define maxn 1000000
using namespace std;

int f[maxn+10];

void etf()
{
   int i,j;
   fr(i,1,maxn) f[i]=i/(i%2?1:2);
   fr(i,3,maxn)
     if (f[i]==i)
       for (int j=i;j<=maxn;j+=i)
         f[j]=f[j]*(i-1)/i;
}

int main()
{

   etf();
   int test,n;
   cin >> test;
   while (test--) scanf("%d",&n), printf("%d\n",f[n]);
   return 0;
}
// 1 2 3 4 5 6 7 8 9 10
// 1 1 3 2 4 3 7 4 9 5
// 1 1 2 2 4 2 7 4 6 5
// 1 1 2 3 4 2 7 3 6 5

