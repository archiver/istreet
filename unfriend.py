import sys, math
from copy import deepcopy as copy

Primes=list()
Factors=list()

def sieve():
  global Primes
  n=4000000
  isPrime=[True]*n

  for i in range(3,int(math.sqrt(n))+1,2):
    if isPrime[i]:
      for j in range(i*i,n,2*i):
         isPrime[j]=False

  Primes.append(2)
  for i in range(3,n,2):
    if isPrime[i]: Primes.append(i)
  return len(Primes)

def factorize(k,p):
  global Factors
  num=k
  for p in Primes:
    if num%p==0:
      val=0
      while num%p==0:
      	val+=1
        num/=p
      Factors.append([p,val])

  if num>1:
    Factors.append([num,1])

def solve(l,k):
  global Primes, Factors
  p=sieve()
  factorize(k,p)
  LCM=copy(Factors)

  for i in range(len(LCM)): 
     LCM[i][1]=0


  for n in l:
    num=n
    for i in range(len(LCM)):
      f=LCM[i][0]
      if num%f==0:
        val=0
	while num%f==0:
	  val+=1
	  num/=f
	if LCM[i][1]<val: LCM[i][1]=val
  
  eq,neq=1,1
  for i in range(len(LCM)):
    eq*=(1+Factors[i][1])
    neq*=(1+min([LCM[i][1],Factors[i][1]]))
  print eq-neq
     
if __name__=='__main__':
  n,k=raw_input().split()
  n,k=int(n),int(k)
  l=map(lambda x:int(x), raw_input().split())
  solve(l,k)
