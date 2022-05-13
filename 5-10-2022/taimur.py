#https://codeforces.com/contest/1676
trials = int(input())
for trial in range(trials):
    n,m = tuple(map(int,list(input().split())))
    s = list(map(int,list(input().split())))
    s.sort(reverse=True)
    x = []
    for i in range(m):
        x.append(int(input()))
 
    ch = max(x)+1
    for j in range(m):
        c = 0
        t = 0
        if x[j]<ch:
            for i in s:
                t += i 
                c += 1 
                if t>=x[j]:
                    print(c)
                    break
            else:
                print(-1)
                ch = x[j]
        else:
            print(-1)

