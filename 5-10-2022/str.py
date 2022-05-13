trials = int(input())
for trial in range(trials):
    n,m = tuple(map(int,list(input().split())))
    s = []
    for i in range(n):
        s.append(input())
    """
    t = 0
    for i in range(m):
        x = list(map(lambda x:ord(x[i])-ord('a')+1,s))
        av = (sum(x)/n)//1
        for j in (x):
            #print(abs(j-av))
            t+= abs(j-av)
    print(s,int(t))
    """

    ma = 27*m
    for prev in range(n-1):
        pw = s[prev]
        for cur in range(prev+1,n):
            t = 0
            cw = s[cur]
            for i in range(m):
                t += abs(ord(pw[i])-ord(cw[i]))
                #print("X")
            #print("total",t)
            if t<ma:
                #print(prev,cur)
                ma = t
    
    print(ma)