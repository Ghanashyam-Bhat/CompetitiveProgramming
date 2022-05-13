trials = int(input())
for trial in range(trials):
    l = list(input().split())
    l = list(map(int,l))
    stri = str(pow(l[0],l[1]))
    if l[2]<= len(stri):
        print(stri[len(stri)-l[2] : ])
    else:
        print("0"*(l[2]-len(stri)),end="")
        print(stri)