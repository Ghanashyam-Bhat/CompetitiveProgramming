trials = int(input())
for trial in range(trials):
    n,m = input().split()
    n,m=int(n),int(m)
    s = input()
    fs = list((s*m).split("1"))
    fs.sort(key=lambda x:x.count("0") ,reverse=True)
    print(fs[0].count("0"))