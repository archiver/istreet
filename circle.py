from collections import Counter

def step(l,n):
  for i in range(n):
     pr=(i-1)%n
     nx=(i+1)%n
     l[i].extend(l[pr])
     l[i].extend(l[nx])
  for t,e in enumerate(l):
    print t,sorted(Counter(e).items())
  print

if __name__=='__main__':
  n,m=6,3
  l=list()
  for i in range(n):
    l.append([i])
  for i in range(m):
    step(l,n)
