#https://codeforces.com/problemset/problem/1515/C
trials = int(input())
while trials != 0 :
    trials -= 1
    n,m,x = input().split(" ")
    n,m,x = int(n),int(m),int(x)
    h = list(input().split(" "))
    h = list(map(int,h))
    avg = sum(h)/m
    ma = avg + x/2
    mi = avg - x/2
    out = list()
    for i in range(m):
        globals()[f"m{i+1}"] = 0
    o = 0
    for i in h:
        if o%2 == 0:
            for j in range(m):
                if globals()[f"m{j+1}"] + i <= ma :
                    globals()[f"m{j+1}"] += i
                    out.append(j+1)
                    break
        elif o%2 !=0 :
            for j in range(m,0,-1):
                if globals()[f"m{j}"] + i <= ma :
                    globals()[f"m{j}"] += i
                    out.append(j)
                    break
        o += 1
    if len(h) == len(out) :
        for i in range(m):
            if globals()[f"m{j+1}"] < mi :
                print("NO")
                n = 0
                break
        if n!= 0:
            print("YES")
            for i in out:
                print(i , end= " ")
            print()
    else :
        print("NO")