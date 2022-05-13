trials = int(input())
for trial in range(trials):
    x = input()
    a = list(map(int,input().split()))
    if len(a)<3:
        print(-1)
    else:
        a.sort()
        max = 0
        prev = a[0]
        for i in a:
            if prev==i:
                max+=1
            else:
                max = 1
            prev = i
            if (max>=3):
                print(i)
                break
        else:
            print(-1)