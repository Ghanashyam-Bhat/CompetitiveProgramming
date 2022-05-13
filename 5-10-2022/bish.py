trials = int(input())
for trial in range(trials):
    n,m = tuple(map(int,list(input().split())))
    l = []
    for i in range(n):
        l.append(list(map(int,input().split())))
    tt = []
    for x in range(n):
        for y in range(m):
            t = 0
            i,j = x,y
            while (i>=0) and (j>=0) and i<n and j<m:
                t += l[i][j]
                i+=1 
                j+=1
            i,j = x,y 
            while (i>=0) and (j>=0) and i<n and j<m:
                t += l[i][j]
                i+=1 
                j-=1
            i,j = x,y   
            while (i>=0) and (j>=0) and i<n and j<m:
                t += l[i][j]
                i-=1 
                j-=1 
            i,j = x,y
            while (i>=0) and (j>=0) and i<n and j<m:
                t += l[i][j]
                i-=1 
                j+=1
            t -= l[x][y]*3
            tt.append(t)
    print(max(tt))