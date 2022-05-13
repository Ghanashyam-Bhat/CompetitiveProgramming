
#https://codeforces.com/contest/1678
trials = int(input())
for trial in range(trials):
    x = int(input())
    l = list(map(int,list(input().split())))
    t = 0
    ch = 1
    li = []
    if 0 in l:
        t += x-l.count(0)
    else:
        for i in l:
            li.append(l.count(i))
        for i in li:
            if i>1:
                t+=x 
                ch = 0
                break
        if ch:
            t+= x+1
    print(t)