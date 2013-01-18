#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<int,int> ii; 
typedef long long ll;
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(),(c).end() 
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())

void solve(vector<ll> &nlst, set<ll> &nset, int N, int K)
{
  int pairs=0;
  for(int i=0;i<N;++i)
  {
    if(present(nset,nlst[i]+K)) pairs+=1;
  }
  cout<<pairs<<endl;
}

int main()
{ 
  int N,K;
  cin>>N>>K;
  vector<ll> nlst;
  set<ll> nset;
  nlst.resize(N);
  for(int i=0;i<N;++i)
  {
    cin>>nlst[i];
    nset.insert(nlst[i]);
  }
  solve(nlst,nset,N,K);

  return 0;
}
