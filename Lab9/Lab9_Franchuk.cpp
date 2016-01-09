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

const int MaxN= 100*1000;
const int inf= 1000*1000*1000;
pii polygon[MaxN+10];
pii tr[MaxN+10];

dbl dist(int i, int j)
{
    return sqrt(sqr(polygon[i].first-polygon[j].first) + sqr(polygon[i].second-polygon[j].second));
}

vector<vi> getMinTr(int l, int r, dbl& ans)
{
    vector<vi> res;
    if (r-l<2) {ans= inf; return res;}
    if (r-l==2)
    {
        ans= dist(l,r);
        vi v;
        v.pb(l); v.pb(l+1); v.pb(r);
        res.pb(v);
        return res;
    }

    dbl left_= inf;
    dbl right_= inf;
    ans= inf;
    vector<vi> vL,vR,vLa, vRa;
    for (int i= l+2; i<=r-2; i++)
    {
        vL= getMinTr(l,i,left_);
        vR= getMinTr(i,r,right_);
        if (left_+right_<ans)
        {
            ans= left_+right_;
            vLa= vL;
            vRa= vR;
        }
    }

    pii tmp= polygon[r+1];
    polygon[r+1]= polygon[l];
    for (int i= l+3; i<=r-1; i++)
    {
        vL= getMinTr(l,i,left_);
        vR= getMinTr(i,r+1,right_);
        if (left_+right_<ans)
        {
            ans= left_+right_;
            vLa= vL;
            vRa= vR;
        }
    }
    polygon[r+1]= tmp;

    for (int i= 0; i<vLa.size(); i++)
        res.pb(vLa[i]);
    for (int i= 0; i<vRa.size(); i++)
        res.pb(vRa[i]);
    return res;
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

    for (int i= 0; i<n; i++)
    {
        int x,y;
        cin>>x>>y;
        polygon[i]= mp(x,y);
    }


    return 0;
}
