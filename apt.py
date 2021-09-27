l = input().split()
a = input().split()
b = input().split()
l = list(map(int,l))
a = list(map(int,a))
b = list(map(int,b))
a.sort()
b.sort()
k = 0
x= 0
for i in range(len(a)):
    if x<len(b):
        while(abs(a[i]-b[x])<(a[i+1]-b[x])) :
            if (-l[2]<=a[i]-b[x]<=l[2]) :
                k+=1
                b.pop(x)
                break
            x+=1
print(k)