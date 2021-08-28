#https://codeforces.com/problemset/problem/1546/B

trials = int(input())
for trial in range(trials):
    a = list()
    b = list()
    n,m = input().split()
    n,m=int(n),int(m)
    check=list()
    c = list()
    ini = list()
    inii = list()
    res = list()
    res2 = list()
    final= list()
    final_b = list()
    for k in range(n):
        t = list(input())
        a.append(t)
    for k in range(n-1):
        t = list(input())
        b.append(t)
    for i in range(n):
        for j in range(i+1,n):
            inii = a[i]+a[j]
            ini = sorted(inii)
            check.append(ini)
            c.append((i,j))
    for i in b:
        for j in b:
            ini = i+j
            ini = sorted(ini)
            p = 0
            
            if ini in check and check.count(ini)==1:
                if c[check.index(ini)] not in res:
                    res.append(c[check.index(ini)])
                    x,y = c[check.index(ini)]
                    res2.append(x)
                    res2.append(y)
            elif (ini in check) and (check.count(ini)>1) and (p!=check.count(ini)):
                for l in range(len(check)):
                    if ini==check[l]:
                        p+=1
                        if c[l] not in res:
                            res.append(c[l])
                            final.append(c[l])
                            final_b.append(inii)
                            x,y = c[l]
                            res2.append(x)
                            res2.append(y)
    if len(res2)==len(set(res2)):
        v = set(range(n))-set(res2)
        print(a[list(v)[0]])
    else :
        for i in final:
            