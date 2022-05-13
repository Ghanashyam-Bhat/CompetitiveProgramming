n = int(input())
l = list(input().split())
l = list(map(int,l))
l1 = list()
l2 = list()
for i in range(n):
    if i%2==0:
        l1.append(l[i])
    else :
        l2.append(l[i])
print(2*max(l)-min(l2)-min(l1))
