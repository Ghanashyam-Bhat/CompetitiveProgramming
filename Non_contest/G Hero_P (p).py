#https://codeforces.com/problemset/problem/1561/C
trial = int(input())
for t in range(trial):
    c = list()
    line2=list()
    nc = int(input())
    for i in range(nc):
        line2 = list(input().split())
        line2 = list(map(int ,line2))
        c.append(line2[1:])
    for i in range(len(c)):
        for j in range(len(c[i])):
            c[i][j]-=j
    c.sort(key= lambda x:max(x))
    sub = len(c[0])
    for i in range(1,len(c)):
        c[i]=list(map(lambda x:x-sub,c[i]))
        sub += len(c[i])
    m = max(c[0])
    for i in range(1,len(c)):
        if m<max(c[i]):
            m = max(c[i])
    print(m+1)