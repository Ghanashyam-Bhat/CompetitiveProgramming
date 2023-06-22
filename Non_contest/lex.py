a = list(input())
b = list(input())
a.sort()
b.sort(reverse=True)
c = ""
x = 0
for i in range(len(a)):
    if i%2==0:
        c+=a[x]
    else :
        c+= b[x]
        x +=1
print(c)