from time import sleep


trials = int(input())
for trial in range(trials):
    c = 0
    l = list(map(int,list(input().split())))
    for i in l[1:]:
        if i>l[0]:
            c+=1
    sleep(0.02)
    print(c)