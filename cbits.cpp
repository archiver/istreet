#include <stdio.h>
#include <string.h>

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define N 100001
#define sz(c) (c).size()

char number[N];
char func[11];

string add(string &a,string &b, int &csz, int n)
{
   string res;
   csz=n;

   char carry=0,sum=0;
   for(int i=0;i<n;++i)
   {
     sum=a[i]-'0'+b[i]-'0'+carry;
     if(sum==2)
     {
       sum=0;
       carry=1;
     }
     else carry=0;
     res.push_back(sum+'0');
   }
   if(carry) 
   {
     res.insert(res.begin(),'1');
     csz+=1;
   }

   return res;
}

void incr(string &c, int &csz, int pos)
{
   int carry=1,sum=0;
   int i;
   for(i=pos;i<csz;++i)
   {
     sum=c[i]-'0'+carry;
     if(sum==2)
     {
       sum=0;
       carry=1;
       c[i]='0';
     }
     else
     {
       c[i]=sum+'0';
       carry=0;
       break;
     }
   }
   if(i==csz && carry==1)
   {
     csz+=1;
     c.push_back('1');
   }
}

void decr(string &c, int &csz, int pos)
{
  int cover=1,diff=0;
  int i;
  for(i=pos;i<csz;++i)
  {
    diff=c[i]-'0'-cover;
    if(diff<0)
    {
      diff+=2;
      cover=1;
      c[i]=diff+'0';
    }
    else
    {
      c[i]=diff+'0';
      cover=0;
      break;
    }
  }
  if(i==csz-1 && cover==0) csz-=1;
}


int main()
{
  int n,q;
  string a,b,c;

  scanf("%d %d",&n,&q);
  scanf("%s",number); a=string(number);
  scanf("%s",number); b=string(number);
  reverse(a.begin(),a.end());
  reverse(b.begin(),b.end());

  int csz;
  c=add(a,b,csz,n); //initial addition

  int idx; 
  int val;
  
  for(int i=0;i<q;++i)
  {
    scanf("%s %d",func,&idx);
    if(!strcmp(func,"get_c"))
    {
      if(idx>=csz) printf("0");
      else printf("%c",c[idx]);
    }
    else
    {
      scanf("%d",&val);
      if(!strcmp(func,"set_a"))
      {
	if(val!=a[idx]-'0')
	{
	  if(val==1) incr(c,csz,idx);
	  if(val==0) decr(c,csz,idx);
	}
        a[idx]=val+'0';
      }
      else if(!strcmp(func,"set_b"))
      {
	if(val!=b[idx]-'0')
	{
	  if(val==1) incr(c,csz,idx);
	  if(val==0) decr(c,csz,idx);
	}
        b[idx]=val+'0';
      }
    }
  }
  printf("\n");
  return 0;
}
