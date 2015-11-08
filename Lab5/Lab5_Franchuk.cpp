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
const int MaxN= 50;
int p[MaxN+10];
int c[MaxN+10];
bool pr[MaxN+10];


int generatePerm(int n)
{
    int kol= 1;
    for (int i= 1; i<=n; i++)
    {
        p[i]= i; c[i]= 1; pr[i]= 1;
    }
    c[n]= 0;
    for (int i= 1; i<=n; i++)
        cout<<p[i]<<" ";
    cout<<endl;
    {
        int i= 1;
        while (i<n)
        {
            i= 1;
            int x= 0;
            while (c[i]== n-i+1)
            {
                pr[i]^= 1;
                c[i]= 1;
                if (pr[i]) x++;
                i++;
            }
             if (i<n)
             {
                 int k;
                 if (pr[i]) k= c[i]+x;
                 else k= n-i+1 - c[i]+x;
                 swap(p[k],p[k+1]);
                 for (int i= 1; i<=n; i++)
                    cout<<p[i]<<" ";
                 cout<<endl;
                 c[i]++;
                 kol++;
             }
        }
    }

    return kol;
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

    int n;
    cin>>n;
    int kol= generatePerm(n);
    cout<<endl<<endl<<kol<<endl;
    return 0;
}
