#include <stdio.h>
#include <algorithm>
using namespace std;

#define N 100000

int c[N];
int val[N];

int solve(int n)
{
  int res=n;
  int i=0,value=0;
  while(i<n)
  {
    value=0;
    i+=1;
    while(i<n && c[i]>c[i-1])
    {
      value+=1;
      val[i]=value;
      i+=1;
    }
  }

  i=n-1;
  while(i>=0)
  {
    value=0;
    i-=1;
    while(i>=0 && c[i]>c[i+1])
    {
      value+=1;
      val[i]=max(val[i],value);
      i-=1;
    }
  }
  
  for(i=0;i<n;++i) res+=val[i];

  return res;
}

int main()
{
  int n,i;
  scanf("%d",&n);
  for(i=0;i<n;++i) scanf("%d",&c[i]);
  printf("%d\n",solve(n));
  return 0;
}
