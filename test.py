from random import randint

n,p=5,13
l=list()
for i in range(n):
  l.append(randint(0,p-1))
cnt=0

def check(pos,cur):
  global l,cnt,n,p
  if pos==n:
    for a,b in zip(cur,l):
      if a>b: 
        cnt+=1 
	break
    return

  for i in range(p):
    cur[pos]=i
    check(pos+1,cur)

check(0,[0]*n)
prod=1
for e in l:
  prod*=(1+e)
print cnt==p**n-prod
