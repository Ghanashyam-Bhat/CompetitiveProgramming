#https://codeforces.com/contest/1520/problem/B
#By Ghanashyam Bhat ~ the.giga.byte
trials  = int(input())
for trial in range(trials):
    n = int(input())
    c = len(str(n))-1
    z = 10**c
    x = (c*9 )+ (n//z)-1
    s = set(str(n))
    if len(s) == 1:
        x += 1
    print(x)
