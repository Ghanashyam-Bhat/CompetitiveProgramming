trials  = int(input())
for trial in range(trials):
    n = input()
    if "11" in n :
        x = n.index("11")
        if "00" in n[x:]:
            print("NO")
        else:
            print("YES")
    else:
        print("YES")