#https://codeforces.com/contest/1638/problem/B
trials = int(input())
for trial in range(trials):
    n = int(input())
    l = list(input().split())
    l = list(map(int,l))
    x = 0
    for i in range(n):
        if l[i]%2==0:
            for j in range(i,n):
                if l[j]%2==0 and l[j]<l[i]:
                    x = 1
                    break
        else:
            for j in range(i,n):
                if l[j]%2!=0 and l[j]<l[i]:
                    x = 1
                    break
    if x:
        print("No")
    else :
        print("Yes")