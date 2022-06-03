trials = int(input())
for trial in range(trials):
    n = int(input())
    l = list(map(int,list(input().split())))
    eve = 0
    odd = 0
    for i in l:
        if i%2==0:
            eve += 1
        else:
            odd += 1
    if odd!=0:
        print(eve)
    else:
        xxx = 0
        c = 0
        while(True):
            c+=1
            for i in range(len(l)):
                l[i] =l[i]//2
                if l[i]%2 !=0:
                    xxx = 1
                    break
            if xxx ==1:
                break
        print(c+len(l)-1)