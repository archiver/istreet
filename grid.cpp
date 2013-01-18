#include <stdio.h>

#define N 11
#define D 101
#define M 301
#define PRIME 1000000007

int ipos[N];
int limit[N];

struct tuple
{
  int pos[N][D];
} state[M];

int solve(int n, int m)
{
  int i,j,k;
  for(i=0;i<n;++i) 
   for(j=1;j<=limit[i];++j)
     state[0].pos[i][j]=1; //initialization

 for(k=1;k<=m;++k)
 {
   for(i=0;i<n;++i)
   {
     for(
   }
 }
  return 0;
}

int main()
{
  int n,m,i,t;
  scanf("%d",&t);
  while(t--)
  {
    scanf("%d %d",&n,&m);
    for(i=0;i<n;++i) scanf("%d",&ipos[i]);
    for(i=0;i<n;++i) scanf("%d",&limit[i]);
  }
  return 0;
}
