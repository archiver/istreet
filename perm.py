
def whowins(l,w):
  global res
  
  n=len(l)
  if l==sorted(l): return 1-w
  

  win=False
  for i in range(n):
    s=list(l)
    del s[i]
    t=tuple(s)
    if (t,1-w) not in res:
      res[(t,1-w)]=whowins(s,1-w)
    if res[(t,1-w)]==w:
      win=True
      
  if win: return w
  else: return 1-w

t=input()
for i in range(t):
  n=input()
  l=map(lambda x:int(x),raw_input().strip().split())
  res={}
  if not whowins(l,0):
    print 'Alice'
  else:
    print 'Bob'
