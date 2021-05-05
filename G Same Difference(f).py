#https://codeforces.com/contest/1520/problem/D
#By Ghanashyam Bhat ~ the.giga.byte
trials  = int(input())
for trial in range(trials):
    n = int(input())
    l = list(range(1,n+1))
    x = list(input().split(" "))
    x = list(map(int,x))
    r = list(zip(l,x))
    f = []
    for i in r:
        if i[0]==i[1]:
            f.append(i[0])
    k = len(f)
    ans = k*(k-1)/2
    print(int(ans))