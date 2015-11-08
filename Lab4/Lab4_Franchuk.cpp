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

vi eulerCicle;

bool euler(int v)
{
  stack<int> s;
  s.push(v);
  while (!s.empty())
  {
    v= s.top();
    if (g[v].size()==0)
    {
        eulerCicle.pb(v);
        s.pop();
    }
    else
    {
        int u= g[v][g[v].size()-1];
        s.push(u);
        g[v].pop_back();
        for (auto cur= g[u].begin(); cur!=g[u].end(); cur++)
            if (*cur==v)
        {
            g[u].erase(cur);
            break;
        }
    }
  }

  return eulerCicle[eulerCicle.size()-1]==eulerCicle[0];
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
    bool f= euler(1);

    if (f)
    {
    cout<<"size: "<<eulerCicle.size()<<endl;
    for (int i= 0; i<eulerCicle.size(); i++)
        cout<<eulerCicle[i]<<" ";
    cout<<endl;
    }
    else
    {
        cout<<"Euler cycle doesn't exist!"<<endl;
    }

    return 0;
}
