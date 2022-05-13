trials = int(input())
ts = 15
for trial in range(trials):
    tt,n = input().split()
    tt,n = int(tt), int(n)
    rs = list(input().split())
    rs = list(map(int,rs))
    rt = list(input().split())
    rt = list(map(int,rt))
    d = ts*tt
    rs.sort();rt.sort()
    rd1 = sum(list(map(lambda x:x[0]*x[1],list(zip(rt,rs)))))
    rt.reverse()
    rd2 = sum(list(map(lambda x:x[0]*x[1],list(zip(rt,rs)))))
    if rd1<d :
        print(True)
    else:
        print(False)
        if rd2>d :
            print(1)
        else :
            print(2)