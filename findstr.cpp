#include <stdio.h>
#include <string.h>

#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

set<string> s;
char str[2001];

int main()
{
  int n,m;
  scanf("%d",&n);
  for(int i=0;i<n;++i)
  {
    scanf("%s",str);
    m=strlen(str);
    for(int j=0;j<m;++j)
      for(int k=j;k<m;++k)
        s.insert(string(str+j,str+k+1));
  }
  vector<string> v(s.begin(),s.end());
  int sz=v.size();

  int q,k;
  scanf("%d",&q);
  for(int i=0;i<q;++i)
  {
    scanf("%d",&k);
    if(k>sz) printf("INVALID\n");
    else cout<<v[k-1]<<"\n";
  }
  return 0;
}
