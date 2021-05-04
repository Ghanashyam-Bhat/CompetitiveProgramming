t = int(input())
for i in range(t):
    n = int(input())
    m = round((n/2)**0.5)
    k = round((n/4)**0.5)
    if m*m ==(n/2) or k*k == (n/4):
        print("YES")
    else:
        print("NO")