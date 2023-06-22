def number(n):
    ans = 0
    x = len(f"{n}")
    z = 10**(x-4)
    no = n//2050
    if n%2050 !=0 :
        print(-1)
    else :
        while z != 0:
            ans += no//z
            no = no % z
            z = z//10
        print(ans)
            
t = int(input())
for i in range(t):
    n = int(input())
    number(n)
