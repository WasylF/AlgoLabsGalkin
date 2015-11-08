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

const int MaxN= 1000;

int matrix[MaxN+10][MaxN+10];
vi g[MaxN+10];
int n;

void readGraph()
{
    cin>>n;
    for (int i= 1; i<= n; i++)
        for (int j= 1; j<=n; j++)
            cin>>matrix[i][j];
}

void convertToAdjacencyLists()
{
    for (int i= 0; i<= MaxN; i++)
        g[i].clear();

    for (int i= 1; i<= n; i++)
        for (int j= 1; j<= n; j++)
            if (matrix[i][j]) g[i].pb(j);
}

bool was[MaxN+10];

void dfs(int v)
{
    if (was[v]) return;
    was[v]= 1;
    cout<<v<<" ";

    for (int i= g[v].size()-1; i>= 0; i--)
        dfs(g[v][i]);
}

void bfs(int v)
{
    if (was[v]) return;
    was[v]= 1;

    queue<int> q;
    q.push(v);
    while (!q.empty())
    {
        v= q.front(); q.pop();
        cout<<v<<" ";
        for (int i= g[v].size()-1; i>= 0; i--)
            if (!was[g[v][i]])
        {
            was[g[v][i]]= 1;
            q.push(g[v][i]);
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
// LL a[110];
// memset(a,0,sizeof(a));

freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
//cout<<fixed;
//cout<<setprecision(9);

    readGraph();
    convertToAdjacencyLists();
    memset(was,0,sizeof(was));
    for (int i= 1; i<=n; i++)
        if (!was[i]) dfs(i);
    cout<<endl;

    memset(was,0,sizeof(was));
    for (int i= 1; i<=n; i++)
        if (!was[i]) bfs(i);
    cout<<endl;

    return 0;
}
