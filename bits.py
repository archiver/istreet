import sys

class cbits():

	def __init__(self,n,a,b):
	  self.mod=True
	  self.a=list(a)
	  self.b=list(b)
	  self.c=''
          self.n=n

	def compute(self):
	  self.c=bin(int(''.join(self.a),2)+int(''.join(self.b),2))[2:]

	def set_a(self,idx):
	  self.a[self.n-int(idx[0])-1]=idx[1]
	  self.mod=True

	def set_b(self,idx):
	  self.b[self.n-int(idx[0])-1]=idx[1]
	  self.mod=True

	def get_c(self,idx):
	  if self.mod:
	     self.mod=False
	     self.compute()
	  print self.c[self.n-1-int(idx[0])],


if __name__=='__main__':
  s=sys.stdin
  n,k=s.readline().strip().split()
  a=s.readline().strip()
  b=s.readline().strip()
  res=cbits(int(n),a,b)
  for i in range(int(k)):
    line=s.readline().strip().split()
    line
    getattr(res,line[0])(line[1:])
  print
