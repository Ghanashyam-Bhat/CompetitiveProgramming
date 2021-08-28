#https://codeforces.com/contest/1546/problem/A
trials = int(input())
for trial in range(trials):
    n = int(input())
    a = list(input().split())
    a = list(map(int,a))
    b = list(input().split())
    b = list(map(int,b))
    i = list()
    j = list()
    if(a==b):
        print(0)
    else:
        while(a!=b):
            for m in range(n):
                if(a[m]<b[m]):
                    a[m]+=1
                    j.append(m+1)
            for m in range(n):
                if(a[m]>b[m]):
                    a[m]-=1
                    i.append(m+1)
        if(len(i)!=len(j)):
            print(-1)
        else:
            print(len(i))
            for z in range(len(i)):
                print(i[z],j[z])