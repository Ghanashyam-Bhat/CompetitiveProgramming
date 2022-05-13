#Not working : Runtime error
#https://codeforces.com/contest/1674
trials = int(input())
for trial in range(trials):
    x = input()
    a = list(input().split())
    a = list(map(int,a))
    b = a.copy()
    b.sort()
    c = a.copy()
    if len(a)<=1:
        print("YES")
    elif a==b:
        print("YES")
    else:
        mi = min(a)
        ma = max(a)
        while (mi in a and ma in a):
            if mi in a:
                a.remove(mi)
            if ma in a:
                a.remove(ma)
        mi = min(a)
        ma = max(a)
        a = c.copy()
        if len(a)>0 and a.pop(0)==mi:
            if len(a)>a and a.pop() == ma:
                b = a.copy()
                b.sort()
                if len(a)<=1:
                    print("YES")
                elif a==b:
                    print("Yes")
                else:
                    print("NO")
            else:
                print("NO")
        else:
            print("NO")
