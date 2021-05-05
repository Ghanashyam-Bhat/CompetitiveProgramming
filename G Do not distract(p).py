#https://codeforces.com/contest/1520/problem/A
#From Ghanashyam Bhat ~ the.giga.byte
trials  = int(input())
for trial in range(trials):
    n = int(input())
    s = input()
    k = []
    c = "000"
    z = 0
    for i in s:
        if i != c:
            if i in k:
                z += 1
                print("NO")
                break
            else:
                c = i
                k.append(i)
    if z==0:
        print("YES")
        