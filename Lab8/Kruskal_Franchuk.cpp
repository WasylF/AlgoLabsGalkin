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
// memset(used,0,sizeof(used));

//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//srand(__rdtsc());

    int n, m;
    int numb= 0;
    cin>>n>>m;
    vector < pair < int, pair<int,int> > > g; // вага - вершина 1 - вершина 2

    for (int i= 0; i<m; i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
        g.pb(mp(c,mp(u,v)));
    }

    int cost = 0;
    vector < pair<int,int> > res;

    sort (g.begin(), g.end());
    vector<int> tree_id (n);
    for (int i=0; i<=n; ++i)
        tree_id[i] = i;
    for (int i=0; i<m; ++i)
    {
        int u = g[i].second.first;
        int v = g[i].second.second;
        int c = g[i].first;
        if (tree_id[u] != tree_id[v])
        {
            numb++;
            cost += c;
            res.push_back (make_pair (u, v));
            cout<<u<<" "<<v<<endl;
            if (numb==n-1) break;
            int old_id = tree_id[v],  new_id = tree_id[u];
            for (int j=0; j<n; ++j)
                if (tree_id[j] == old_id)
                    tree_id[j] = new_id;
        }
    }

    if (res.size()<n-1) cout<<"no MST!"<<endl;
    else cout<<"total cost: "<<cost<<endl;

    return 0;
}


