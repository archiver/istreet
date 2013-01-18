import sys

n=input()
strs=set()
for i in range(n):
  s=raw_input()
  for j in range(len(s)):
    for k in range(j,len(s)):
      strs.add(s[j:k+1])

lex=sorted(list(strs))
length=len(lex)
q=input()
for i in range(q):
  k=input()
  if k>length:
    print "INVALID"
  else:
    print lex[k-1]
