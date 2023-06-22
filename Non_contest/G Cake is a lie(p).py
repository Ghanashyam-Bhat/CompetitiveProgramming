#https://codeforces.com/problemset/problem/1519/B
def shift(n,m,k):
    n,m,k = int(n),int(m),int(k)
    if ((n-1)*1+(m-1)*n)==k :
        print("YES")
    else :
        print("NO")

t = int(input())
for i in range(t):
    n,m,k = input().split(" ")
    shift(n,m,k)