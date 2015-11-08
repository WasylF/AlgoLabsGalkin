//solution by Wsl_F
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <bitset>
#include <numeric>
#include <cassert>
#include <time.h>
#include <ctime>
#include <memory.h>
#include <complex>
#include <utility>
#include <climits>
#include <cctype>
#include <x86intrin.h>



using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")


typedef long long LL;
typedef unsigned long long uLL;
typedef double dbl;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;

#define mp(x,y)  make_pair((x),(y))
#define pb(x)  push_back(x)


vector<vector<pii> > a;

int main()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0);
 // LL a[110];
 // memset(a,0,sizeof(a));

 //freopen("input.txt","r",stdin);
 //freopen("output.txt","w",stdout);
 //srand(__rdtsc());

 int n,m;
 int from,to;
 int u,v,c;

 cin>>n>>m;
 cin>>from>>to;

 a.resize(n+1);
 for (int i=0; i<m; i++)
 {
     cin>>u>>v>>c;
     a[u].pb(mp(v,c));
     a[v].pb(mp(u,c));
 }


 const int inf= INT_MAX/2;
 vi d(n+1,inf);
 d[from]= 0;
 vi parent(n+1,-1);

 priority_queue<pii, vector<pii>, greater<pii> > pq;

 pq.push(mp(0,from));

 while (!pq.empty() && pq.top().first!=inf)
 {
     u= pq.top().second; c= pq.top().first; pq.pop();
     if (d[u]<c) continue;
     for (int i=0; i<a[u].size(); i++)
     {
         if (d[a[u][i].first]>c+a[u][i].second)
         {
             d[a[u][i].first]= c+a[u][i].second;
             pq.push(mp(d[a[u][i].first],a[u][i].first));
             parent[a[u][i].first]= u;
         }
     }
 }


 if (d[to]==inf)
 {
     cout<<-1<<endl;
     return 0;
 }

 cout<<d[to]<<endl;
 d.clear();

 while (to!=-1)
 {
     d.pb(to);
     to= parent[to];
 }

 for (int i=d.size()-1; i>=0; i--)
    cout<<d[i]<<" ";
 cout<<endl;

 return 0;
}


