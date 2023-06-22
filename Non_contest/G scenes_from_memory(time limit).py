#https://codeforces.com/problemset/problem/1562/B

def string(li):
    s = ""
    for x in range(len(li)):
        s+=li[x]
    return s
    
def not_prime(n):
    for i in range(2,n//2+1):
        if n%i==0:
            return 1
    return 0
    
import math as m
def noprime(n):
    c = 0
    k = m.sqrt(n)
    j = m.floor(k)
    for i in range(2, j + 1):
        if n % i == 0:
            c = 1
            break
    return c
    
trials = int(input())
#import sympy as P

for trial in range(trials):
    l = int(input())
    n = int(input())
    s = str(n)
    x = n
    for i in range(l):
        for j in range(len(s)):
            if len(s)>1:
                li = list(s)
                li.pop(len(s)-1-j)
                s = string(li)
                if noprime(int(s)):
                    x = int(s)
                    break
                else:
                    s=str(x)
    x1 = x
    s = str(n)
    x = n
    for i in range(l):
        for j in range(len(s)):
            if len(s)>1:
                li = list(s)
                li.pop(j)
                s = string(li)
                #if(P.isprime(int(s))):
                #    s=str(x)
                #else:
                #    x = int(s)
                #    break
                if noprime(int(s)):
                    x = int(s)
                    break
                else:
                    s=str(x)
    x2 = x
    if(x1>x2):
        print(len(str(x2)))
        print(x2)
    else:
        print(len(str(x1)))
        print(x1)