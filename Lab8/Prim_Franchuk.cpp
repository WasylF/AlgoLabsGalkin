//solution by Wsl_F
#include <bits/stdc++.h>



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


vector<vector<pii> > g;
bool used[100010];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
// LL a[110];
 memset(used,0,sizeof(used));

//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//srand(__rdtsc());

    int n,m;
    int from,to;
    int u,v,c;

    cin>>n>>m;

    g.resize(n+1);
    for (int i=0; i<m; i++)
    {
        cin>>u>>v>>c;
        g[u].pb(mp(v,c));
        g[v].pb(mp(u,c));
    }


    const int INF= INT_MAX/2;

    vector<int> min_e (n+1, INF), sel_e (n+1, -1);
    min_e[0] = 0;
    set < pair<int,int> > s;
    s.insert (mp (0, 1));
    for (int i=0; i<n; ++i)
    {
        if (s.empty())
        {
            cout << "Граф не зв'язний!";
            return 0;
        }
        int v = s.begin()->second;
        s.erase (s.begin());

        if (sel_e[v] != -1)
        {
             cout << v << " " << sel_e[v] << endl;
             used[v]= 1;
             used[sel_e[v]]= 1;
        }

        for (size_t j=0; j<g[v].size(); ++j)
        {
            int to = g[v][j].first,
                cost = g[v][j].second;
            if (!used[to] && cost < min_e[to])
            {
                s.erase (mp (min_e[to], to));
                min_e[to] = cost;
                sel_e[to] = v;
                s.insert (mp (min_e[to], to));
            }
        }
    }

    return 0;
}


