#https://codeforces.com/problemset/problem/1562/B

import math as m
def noprime(n):
    c = 0
    k = m.sqrt(n)
    j = m.floor(k)
    if (n==1):
        return n
    else:
        for i in range(2, j + 1):
            if n % i == 0:
                c = 1
                break
        return c

def fun(l,n):
    for i in str(n):
        if noprime(int(i)):
            return 1,i
    if l==2:
        if(noprime(n)):
            return l,n
    else:
        for i in str(n):
                if str(n).count(i)>1 and t :
                    return 2,i*2
        if l>2:
            if ("2" in str(n)):
                if str(n).index(str(2))==0:
                    if "5" in str(n):
                        return 2,25
                    elif "7" in str(n):
                        return 2,27
                    elif noprime(n):
                        return l,n
                elif str(n).index(str(2))>0:
                    return 2,str(n)[str(n).index(str(2))-1:str(n).index(str(2))+1]
            if "7" in str(n) and "5" in str(n) and str(n).index(str(7))<str(n).index(str(5)):
                return 2,75
            if "3" in str(n) and "5" in str(n) and str(n).index(str(3))<str(n).index(str(5)):
                return 2,35
                
trials = int(input())
for trial in range(trials):
    t = 1
    l = int(input())
    n = int(input())
    x,y = fun(l,n)
    print(x)
    print(y)