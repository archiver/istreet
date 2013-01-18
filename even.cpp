#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

#define pb push_back
#define N 101

typedef vector<int> vi;
typedef vector<vi> vvi;

bool visited[N];
int parity[N];
vvi g;
int n,m;

int init(int i)
{
  visited[i]=true;
  int val=1;
  for(vi::iterator it=g[i].begin();it!=g[i].end();++it)
    if(!visited[*it])
      val+=init(*it);
  parity[i]=val;
  return val;
}

int solve(int i)
{
  visited[i]=true;
  int val=0;
  for(vi::iterator it=g[i].begin();it!=g[i].end();++it)
  {
    if(!visited[*it]) 
    {
      if(parity[*it]%2==0) val+=1;
      val+=solve(*it);
    }
  }
  return val;
}

int main()
{
  int u,v;
  scanf("%d %d",&n,&m);
  for(int i=0;i<n;++i) { vi t; g.pb(t); }
  for(int i=0;i<n;++i) 
  {
    scanf("%d %d",&u,&v);
    g[u].pb(v);
    g[v].pb(u);
  }

  init(1);
  for(int i=1;i<=n;++i) visited[i]=false;
  
  int res=0;
  for(int i=1;i<=n;++i)
    res=max(res,solve(i));

  printf("%d\n",res);
  return 0;
}
