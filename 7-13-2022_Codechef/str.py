trials = int(input())
for trial in range(trials):
    n = int(input())
    fs = input()
    x = 1
    for i in range(n):
        s = fs[:n+1]
        if n%2 == 0:
            if s[:int(n/2)]==s[int(n/2):]:
                pass
            else :
                x = 0
                break
        else:
            if s[:int(n/2)]==s[int(n/2):n-1]:
                pass
            else:
                x = 0
                break
    if x:
        print("YES")
    else:
        print("NO")