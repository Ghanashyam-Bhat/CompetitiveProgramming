#Connected components
def dfs(li,i):
    global vi
    for j in range(n):
        if (li[i][j]==1) and (j not in vi):
            vi.append(j)
            dfs(li,j)

trials = int(input())
for trial in range(trials):
    n = int(input())
    l = list(input().split())
    l = list(map(int,l))
    li = []
    for i in range(n):
        li.append([])
        for j in range(n):
            li[i].append(0)

    for i in range(n):
        for j in range(i+1,n):
            if(l[i]>l[j]):
                li[l[i]-1][l[j]-1] = 1
                li[l[j]-1][l[i]-1] = 1

    for i in range(n):
        for j in range(n):
            print(li[i][j],end=" ")
        print()

    c = 0
    vi = []
    for i in range(n):
        if i not in vi:
            dfs(li,0)
            c+=1
    print(c)