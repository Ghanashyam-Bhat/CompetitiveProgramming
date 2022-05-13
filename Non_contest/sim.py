#https://codeforces.com/problemset/problem/1670/A
def is_sorted_p(l):
    prev  = l[0]
    for i in l:
        if abs(i)<abs(prev):
            return 0
    else:
        return 1

def is_sorted_rev(l,x):
    if x==0:
        return 1
    prev  = l[0]
    for i in l:
        if abs(i)>abs(prev):
            return 0
    else:
        return 1

def is_sorted(l):
    prev  = l[0]
    for i in l:
        if i<prev:
            return 0
    else:
        return 
        
def is_same(l):
    prev  = l[0]
    for i in l:
        if abs(i)!=abs(prev):
            return 0
    else:
        return 1

trials = int(input())
for trial in range(trials):
    n = int(input())
    l = list(map(int,list(input().split())))
    n_count = 0
    p_count = 0
    prev = n-1
    if is_same(l) or is_sorted(l):
        print("YES")
    else:
        """for i in range(n):
            if abs(l[prev])<abs(l[i]):
                break;
            prev = i
        if prev==n-1:"""
        for i in range(n-1,-1,-1):
            if abs(l[prev])<abs(l[i]):
                break;
            prev = i

        
        for i in l[:prev]:
            if i>0:
                p_count+=1
        for i in l[prev:]:
            if i<0:
                n_count+=1
        
        """print(is_sorted_p(l[prev:]))
        print(prev)
        print(n_count)
        print(p_count)"""
        
        if is_sorted_p(l[prev:]) and is_sorted_rev(l[:prev],prev) and (0<=(n_count-p_count)<=1 ):
            print("YES")
        else:
            print("NO")