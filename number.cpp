#include <stdio.h>
#include <limits.h>
#include <vector>
using namespace std;

typedef vector<int> vi;
typedef unsigned long long ull;

#define N 1000001
#define P 80000
#define PRIME 1000007

unsigned int prime[(N>>5)+1];
unsigned int primes[P];

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

int solve(int n)
{
   int p = sieve();
   vi f(p,0);
   int cnt; ull d;
   for(int i=0;i<p;++i)
   {
     d=primes[i];
     while(n/d)
     {
       f[i]+=(n/d);
       d=d*primes[i];
     }
   }

   ull res=1LLU;
   for(vi::iterator it=f.begin();it!=f.end();++it)
     res=(res*(1+(*it*2)))%PRIME;
   return int(res%PRIME);
}

int main()
{
  int n;
  scanf("%d",&n);
  printf("%d\n",solve(n));
  return 0;
}
