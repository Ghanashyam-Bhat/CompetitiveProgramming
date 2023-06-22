"""def fun(lm,n,c,x):
    if len(lm)==0:
        return x 
    else :
        lm[0]+=1
        c+=1
        if lm[0]==n:
            x+= 1
            lm[0]=0
        lm = list(filter(lambda x:x>c,lm))
        return fun(lm,n,c,x)

trials = int(input())
for trial in range(trials):
    n,m = input().split()
    n,m = int(n),int(m)
    lm = list(input().split())
    lm = list(map(int,lm))
    lm.sort(reverse=True)
    print(fun(lm,n,0,0))"""

"""
def fun(lm,n,c,x):
    if len(lm)==0:
        return x 
    else :
        c-=min(lm)
        lm.pop()
        x+=1
        lm = list(filter(lambda x:x<c,lm))
        return fun(lm,n,c,x)

trials = int(input())
for trial in range(trials):
    n,m = input().split()
    n,m = int(n),int(m)
    lm = list(input().split())
    lm = list(map(int,lm))
    lm = list(map(lambda x:n-x,lm))
    lm.sort(reverse=True)
    print(fun(lm,n,n,0))
    """

def fun(lm,m):
    c = 0
    x = 0
    z = 0
    while (x+z)<=m:
        k = c
        c+=lm[m-1-x]
        for i in list(filter(lambda x: x<=c and x>k,lm)):
            z+=lm.count(c)
        x += 1
    return x

trials = int(input())
for trial in range(trials):
    n,m = input().split()
    n,m = int(n),int(m)
    lm = list(input().split())
    lm = list(map(int,lm))
    lm = list(map(lambda x:n-x,lm))
    lm.sort(reverse=True)
    print(fun(lm,m))
    