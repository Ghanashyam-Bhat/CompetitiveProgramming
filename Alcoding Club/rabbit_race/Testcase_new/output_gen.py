x = input()
file = open(x+".txt","r")
f = file.readlines()
trials = int(f[0][:-1])
ts = 15
x,y,z = 1,2,3
for trial in range(trials):
    tt,n = f[x][:-1].split()
    tt,n = int(tt), int(n)
    rs = list(f[y][:-1].split())
    rs = list(map(int,rs))
    rt = list(f[z][:-1].split())
    rt = list(map(int,rt))
    d = ts*tt
    rs.sort();rt.sort()
    rd1 = sum(list(map(lambda x:x[0]*x[1],list(zip(rt,rs)))))
    #rt.reverse()
    #rd2 = sum(list(map(lambda x:x[0]*x[1],list(zip(rt,rs)))))
    x,y,z = x+3,y+3,z+3
    if rd1<d :
        print(True)
    else:
        print(False)
        #if rd2>d :
         #   print(1)
        #else :
         #   print(2)