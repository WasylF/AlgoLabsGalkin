//solution by Wsl_F
#include <bits/stdc++.h>


using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")


typedef long long LL;
typedef unsigned long long uLL;
typedef double dbl;
typedef vector<int> vi;
typedef vector<LL> vL;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef pair<LL,LL> pLL;

#define mp(x,y)  make_pair((x),(y))
#define pb(x)  push_back(x)
#define sqr(x) ((x)*(x))

pii getMinMax(int a[], int n)
{
    if (n==1) return mp(a[0],a[0]);
    pii ans;
    pii l= getMinMax(a,n/2);
    pii r= getMinMax(a+n/2,n-n/2);
    ans.first= min(l.first,r.first);
    ans.second= max(l.second,r.second);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
// LL a[110];
// memset(a,0,sizeof(a));

//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//cout<<fixed;
//cout<<setprecision(9);
    int a[10]= {1, 2,3,4,5,6,7,20,-20,0};
    pii r= getMinMax(a,10);
    cout<<r.first<<" "<<r.second<<endl;

    return 0;
}
