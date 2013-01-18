#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef unsigned long long ull;
#define N 1001

int ants[N],diff[N];

int main()
{
  ull n;
  int i=0,cnt=0,val=0,start=0;

  scanf("%llu",&n);

  ull res=((n*n)/2)*200000LLU;

  for(i=0;i<n;++i) scanf("%d",&ants[i]);
  sort(ants,ants+n);

  for(i=0;i<n-1;++i) diff[i]=(ants[i+1]-ants[i]);

  i=0; vii v;
  while(i<n-1)
  {
    val=1;start=i;
    while(i<n-1 && diff[i]==1) { val+=1; i+=1;}
    if(val!=1) v.push_back(ii(ants[start],val));
    else i+=1;
  }
  
  if(!v.empty())
  {
    ii right = *v.rbegin(), left=*v.begin();
    //last is part of a series
    if((right.first+right.second==ants[n-1]+1))
    {
      if((ants[n-1]+1)%1000==ants[0])
      {
	if(left.first==ants[0]) //first is part of series
	{
	  v[0].second=(left.second+right.second);
	  v.erase(v.begin()+v.size());
	}
	else //first is not part of series
	  v[v.size()-1].second+=1;
      }
    }
    //last is not part of a series
    else if((ants[n-1]+1)%1000==ants[0])
    {
      if(v[0].first==ants[0]) //first is part of a series
	v[0].second+=1;
      else //first is not part of a series
	v.push_back(ii(ants[n-1],2));
    }
  }
  else //no consequtive in liner scan so look at endpoints
  {
    if((ants[n-1]+1)%1000==ants[0])
      v.push_back(ii(ants[n-1],2));
  }

  for(i=0;i<v.size();++i)
    res+=2*((v[i].second)/2);

  printf("%llu\n",res);
  return 0;
}
