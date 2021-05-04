#https://codeforces.com/problemset/problem/1519/A
def distribute(r,b,d):
    if min(r,b) == r and min(r,b) == b:
        print("YES")
    else :
        x = min(r,b)
        y = max(r,b)
        y -= x
        z = y//x
        if y%x != 0:
            z+=1
        if z <= d:
            print("YES")
        if z >d :
            print("NO")
t = int(input())
for i in range(t):
    r,b,d = input().split(" ")
    distribute(int(r),int(b),int(d))