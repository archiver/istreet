#include <stdio.h>
#include <limits.h>

#include <vector>
#include <algorithm>
using namespace std;

#define N 4000000
#define S 1000001
typedef unsigned long long ull;
typedef vector<int> vi;

unsigned int prime[(N>>5)+1];
unsigned int primes[N];
ull nums[S];
vector<vi> f,b;

int sieve()
{
   int i,j;

   for(i=0;i<(N>>5)+1;++i) prime[i]=UINT_MAX;

   for(i=3;i*i<N;i+=2)
   {
      if(prime[i>>5] & (1<<(i&31)))
      {
	 for(j=i*i;j<N;j+=(i+i))
	    prime[j>>5]=(prime[j>>5]&(~(1<<(j&31))));
      }
   }   

   primes[0]=2;
   j=1;
   for(i=3;i<N;i+=2)
   {
     if(prime[i>>5] & (1<<(i&31)))
     {
        primes[j]=i;
	j+=1;
     }
   }
   return j;
}

void factorize(ull k, int p)
{
  ull num=k;
  f.clear();
  int cur=-1;
  for(int i=0;i<p && num>1 ;++i)
  {
    if((num%primes[i])==0)
    {
      cur+=1;
      f.push_back(vi(2,0));
      f[cur][0]=primes[i];
      while((num%primes[i])==0)
      {
        f[cur][1]+=1;
	num/=primes[i];
      }
    }
  }
  if(num>1) //one more prime number left
  {
    cur+=1;
    f.push_back(vi(2,0));
    f[cur][0]=num;
    f[cur][1]=1;
  }
}

ull solve(int n,ull k)
{
  int p = sieve();
  factorize(k,p);
  b=f; for(int i=0;i<b.size();++i) { b[i][1]=0;}

  ull num; int cnt,i,j;
  for(i=0;i<n;++i)
  {
    num=nums[i];
    for(j=0;j<b.size() && num>1;++j)
    {
      if(num%b[j][0]==0)
      {
        cnt=0;
        while(num%b[j][0]==0)
	{
	  cnt+=1;
	  num/=b[j][0];
	}
	if(b[j][1]<cnt) b[j][1]=cnt; //accumulate max powers for these primes
      }
    }
  }

  ull neq=1LLU, eq=1LLU;
  int l=f.size();
  for(i=0;i<l;++i)
  {
    eq*=(1LLU+f[i][1]);
    neq*=(1LLU+min(b[i][1],f[i][1]));
  }
  return eq-neq;
}

int main()
{
   int n; ull k;
   scanf("%d %llu",&n,&k);
   for(int i=0;i<n;++i) scanf("%llu",&nums[i]);
   printf("%llu\n",solve(n,k));
   return 0;
}
