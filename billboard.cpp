#include <stdio.h>
#define N 100001
typedef unsigned long long ull;
int arr[N];
ull sum[N];
ull buf[N];

inline int max(int a, int b) { return a>b?a:b; }


void init(int n, int k)
{
  int i;
  sum[0]=0;
  for(i=0;i<k;++i)
    sum[0]+=arr[i];

  for(i=1;i<n;++i)
  {
    sum[i]=sum[i-1]-arr[i-1];
    if(i+k-1<n) sum[i]+=arr[i+k-1];
  }
}



int solve(int n, int k)
{
  int i;
  init(n,k);
  buf[n-1]=arr[n-1];
  for(i=n-2;i>=n-k; --i)
    buf[i]=buf[i+1]+arr[i];

  for(;i>=0;--i)
  {
    buf[i]=1;
    buf[i]=max(buf[i+k+1]+sum[i],buf[i+1]);
  }
}

int main()
{
  int n,k,i;
  scanf("%d %d",&n,&k);
  for(i=0;i<n;++i) scanf("%d",&arr[i]);
  printf("%d\n",solve(n,k));
  return 0;
}
