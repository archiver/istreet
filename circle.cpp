#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

void step(vvi &c, int n)
{
  int i=0,prev,next;
  for(i=0;i<n;++i)
  {
    prev=(n+(i-1)%n)%n;
    next=(n+(i+1)%n)%n;
    vi t(c[prev].size()+c[next].size()+c[i].size());
    copy(c[i].begin(),c[i].end(),t.begin());
    copy(c[prev].begin(),c[prev].end(),t.begin()+c[i].size());
    copy(c[next].begin(),c[next].end(),t.begin()+c[i].size()+c[prev].size());
    sort(t.begin(),t.end());
    c[i]=t;
  }
  for(i=0;i<n;++i)
  {
    for(vi::iterator it=c[i].begin();it!=c[i].end();++it)
      printf("%d ",*it);
    printf("\n");
  }
  printf("\n\n");
}


int main()
{
  int n=6,m=2,i;
  vvi c(n);
  for(i=0;i<n;++i) c[i].push_back(i);  
  for(i=0;i<m;++i) step(c,n);
  return 0;
}
