#from time import sleep


trials = int(input())
for trial in range(trials):
    n,m = input().split()
    n,m = int(n),int(m)
    li = []
    for i in range(n):
        x = list(input())
        li.append(x)
    u = n
    l = m
    for i in range(n):
        for j in range(m):
            if li[i][j]=="R":
                if i<u:
                    u = i 
                if j<l:
                    l = j 
    yes = 0
    #sleep(0.1)
    for i in range(u+1):
        for j in range(l+1):
            if li[i][j]=="R":
                print("YES")
                yes = 1
                break
    if yes==0:
        print("NO")