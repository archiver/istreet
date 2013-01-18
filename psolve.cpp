#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef vector<int> vi;
typedef map<int,vi> mvi;

#define pb push_back
#define N 1000

int arr[N];
int mval[N], mind[N];
mvi g;

inline int abs(int a) { return a>0?a:-a; }

void init(int n, int k)
{
    int i,j;
    g.clear();
    for(i=0;i<n;++i)
    {
	vi t;
	for(j=i+1;j<n;++j)
	    if(abs(arr[j]-arr[i])>=k) t.pb(j);
	g[i]=t;
    }
    for(i=0;i<g[15].size();++i)
    {
      printf("%d ",g[15][i]);
    }
    printf("\n%d %d %d\n",arr[15],arr[23],arr[24]);
}

int solve()
{
    if(g.empty()) return 0;

    map<int,vi>::iterator it;
    map<int,vi>::reverse_iterator rit;

    int i,j;
    for(it=g.begin();it!=g.end();++it)
    {
	i=it->first;
	mval[i]=1;
	mind[i]=i;
    }

    int mvalue=0,mindex=0;
    for(rit=g.rbegin();rit!=g.rend();++rit)
    {
	i=rit->first;
	mvalue=0;
	mindex=i;
	for(j=0;j<g[i].size();++j)
	{
	    if((g.find(g[i][j])!=g.end()) && mval[g[i][j]]>mvalue)
	    {  
		mvalue=mval[g[i][j]]; 
		mindex=g[i][j]; 
	    }
	}
	mval[i]=1+mvalue;
	mind[i]=mindex;
    }

    int start=g.begin()->first, value=mval[start];
    it=g.begin();++it;
    for(;it!=g.end();++it)
    {
	i=it->first;
	if(value<mval[i]) 
	{
	    value=mval[i];
	    start=i;
	}
    }

    i=start;
    int pi=-1;
    while(true)
    {
	g.erase(g.find(i));
	printf("%d ",i);
	pi=i;
	i=mind[i];
	if(pi==i) break;
    }
    printf("\n");
    return 1+solve();
}

int main()
{
    int t,n,k,i;
    scanf("%d",&t);
    while(t--)
    {
	scanf("%d %d",&n,&k);
	for(i=0;i<n;++i) scanf("%d",&arr[i]);
	init(n,k);
	printf("%d\n\n",solve());
    }
    return 0;
}
