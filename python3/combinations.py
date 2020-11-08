def factorise(m):
	ans=[]
	p=2
	while(m!=1):
		if(m%p!=0):
			p+=1
			continue 
		e=0
		while(m%p==0):
			m //=p
			e+=1
		ans.append([p,e])
		p+=1
	return ans 

def mulmod(a,b,c):
	res= a*b 
	if(res >=c):
		res %=c 
	return res 

def mod_inverse(a,n):
	N=n 
	xx=0
	yy=1
	y=0
	x=1 
	while(n>0):
		q=a//n
		t=n 
		n = a % n
		a = t
		t = xx
		xx = x - q * xx
		x = t
		t = yy
		yy = y - q * yy
		y = t
	x %= N
	x += N
	x %= N
	return x

def expo(a,b):
	x=1 
	y=a 
	while(b>0):
		if(b&1):
			x=x*y 
		y=y*y 
		b >>= 1
	return x 

def power(a,b,c):
	x=1 
	y=a 
	while(b>0):
		if(b&1):
			x=mulmod(x,y,c)
		y=mulmod(y,y,c)
		b >>=1
	return x 

def init(p,pk):
	fact=[]
	fact.append(1)
	for i in range(1,pk):
		red=i 
		if(red%p==0):
			red=1 
		fact.append(mulmod(fact[i-1],red,pk))
	return fact 

def fact_mod(n,p,pk,fact):
	res=1
	while(n>0):
		times=n//pk 
		res= mulmod(res,power(fact[pk-1],times,pk),pk)
		res= mulmod(res,fact[n%pk],pk)
		n//=p
	return res 

def count_fact(n,p):
	ans=0
	while(n>0):
		ans +=n//p 
		n //=p 
	return ans 

def ncr_pk(n,r,p,e):
	if (r> n or r<0):
		return 0
	if(r==0 or n==r):
		return 1
	_e = count_fact(n,p) -count_fact(r,p) -count_fact(n-r,p)
	assert(_e >=0)
	if(_e >=e):
		return 0
	pk=expo(p,e)
	fact= init(p,pk)
	

