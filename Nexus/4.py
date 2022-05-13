trials = int(input())
for trial in range(trials):
    l = list(input().split())
    l = list(map(int,l))
    st = str(int("1"*l[0])*int("1"*l[1]))
    x = len(st)
    if x%2!=0:
        print(st[int((x+1)/2)])
    else :
        print(st[int(x/2)])