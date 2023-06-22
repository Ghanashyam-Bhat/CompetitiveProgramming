#https://codeforces.com/problemset/problem/1499/B
def removal(s):
    l = list(s)
    ls = l.copy()
    ls.sort()
    c = l.copy()
    lsr = l.copy()
    lsr.sort(reverse=True)
    if l == ls:
        print("YES")
        return 0
    lz = list(zip(l,ls))
    l1 = list(map(lambda x:min(x),lz))
    l0 = list(map(lambda x:max(x),lz))
    a = []
    for i in range(len(l)):
        if l[i]=="1" and l1[i]=="0":
            a.append(i+1)
    f = 1
    for i in a:
        c.pop(i-f)
        f += 1
    u = c.copy()
    u.sort()
    v = 0
    for i in range(1,len(a)): 
            if a[i]-a[i-1]==1:
                v+=1
    if v > 0:
        a = []
        for i in range(len(l)):
            if l[i]=="0" and l0[i]=="1":
                a.append(i+1)
        for i in a:
            c.pop(i-f)
            f += 1
        u = c.copy()
        u.sort()
        for i in range(1,len(a)): 
                if a[i]-a[i-1]==1:
                    print("NO")
                    return 0
        if c==u:
            print("YES")
            return 0
    if c==u:
        print("YES")
        return 0
    a = []
    for i in range(len(l)):
            if l[i]=="0" and l0[i]=="1":
                a.append(i+1)
    for i in range(len(l)):
        if l[i]=="1" and l1[i]=="0":
            a.append(i+1)
    a.sort()
    if l == lsr and "1" in l and "0" in l and len(a)<=2:
        print("YES")
        return 0
    elif len(a) > 2:
        for i in range(1,len(a)): #10100
            if a[i]-a[i-1]==1:
                print("NO")
                return 0
    if a[-1] <= len(l):
        print("YES")
    else:
        print("NO")
t = int(input())
for i in range(t):
    s = input()
    removal(s)