#include <stdio.h>
#include <string.h>
#include <utility>
using namespace std;

typedef pair<int,int> ii;
#define N 100

ii vals[N+1][N+1];
ii buf[N];
ii temp[3][3];
char s[N+1];

ii minimum(ii left, ii right)
{
  int l=left.first,r=right.first;
  int lbit=left.second,rbit=right.second;
  
  int mlen=N+1;
  int i,j,k,bitrep=0;

  for(i=0;i<3;++i)
  {
    for(j=0;j<3;++j)
    {
      temp[i][j]=ii(0,0);
      if((lbit&(1<<i)) && (rbit&(1<<j)))
      {
        if(i==j) //when i & j are equal
	{
	  temp[i][j].first=l+r;
	  temp[i][j].second=(1<<i);
	  if(mlen>(l+r)) mlen=l+r;
	  continue;
	}

        if ((l&1) && (r&1)) //odd-odd case
	{
	  temp[i][j].first=1;
	  temp[i][j].second=7-(1<<i)-(1<<j);
	  if(mlen>1) mlen=1;
	}
	else if((!(l&1)) && (!(r&1))) //even-even case
	{
	    temp[i][j].first=2;
	    temp[i][j].second=((1<<i)|(1<<j));
	    if(mlen>2) mlen=2;
	}
	else //even-odd case
	{
	  temp[i][j].first=1;
	  temp[i][j].second=(1<<(l&1?i:j));
	  if(mlen>1) mlen=1;
	}
      }
    }
  }
  
  for(i=0;i<3;++i)
    for(j=0;j<3;++j)
      if(temp[i][j].first==mlen)
        bitrep|=temp[i][j].second;

  return ii(mlen,bitrep);
}

int solve(int n)
{
  //i-> string position; j-> length of substring
  int i,j,k;

  for(i=0;i<n;++i)
    vals[i][1]=ii(1,1<<(s[i]-'a'));
  
  int mlen,mbit,t,cnt;
  for(j=1;j<n;++j)
  {
    for(i=0;i+j<n;++i)
    {
      mlen=N+1;
      for(k=1,cnt=0; i+k<n && k<=j;++k,++cnt)
      {
         buf[cnt]=minimum(vals[i][k],vals[i+k][j-k+1]);
	 if(buf[cnt].first<mlen) mlen=buf[cnt].first;
      }

      mbit=0;
      for(t=0;t<cnt;++t)
         if(buf[t].first==mlen)
	   mbit|=buf[t].second;

      vals[i][j+1]=ii(mlen,mbit);
    }
  }

  return vals[0][n].first;
}

int main()
{
  int t,n;
  
  scanf("%d",&t);
  while(t--)
  {
    scanf("%s",s);
    n=strlen(s);
    printf("%d\n",solve(n));
  }
  return 0;
}
