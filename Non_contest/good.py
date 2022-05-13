trials = int(input())
for trial in range(trials):
    s = list(input())
    s.reverse()
    b = 0
    if len(s)>=2 and s[-1] == "A" and s[0] == "B":
        for i in s:
            if i== "B":
                b+=1
            elif i=="A" and b>0:
                b -=1
        if b==0:
            print("YES")
        else:
            print("NO")
    else:
            print("NO")