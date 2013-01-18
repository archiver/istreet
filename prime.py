
def number(n,p):
   coef=list()
   num=n
   while n:
     coef.append(n%p)
     n/=p
   prod=1
   for e in coef:
     prod*=(1+e)
   print (num+1)-prod

t=input()
for i in range(t):
  n,p=raw_input().split()
  number(int(n),int(p))
