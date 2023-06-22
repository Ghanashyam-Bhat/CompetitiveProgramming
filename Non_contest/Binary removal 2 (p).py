trials  = int(input())
for trial in range(trials):
    n = input()
    if "11" in n :
        if "00" in n[n.index("11"):]:
            print("NO");n = 0;  
    if n !=0:
        print("YES")