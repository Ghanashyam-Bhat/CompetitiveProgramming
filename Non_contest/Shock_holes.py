n, k = input().split()
n, k = int(n), int(k)
h = []
for i in range(n):
    h.append(list(map(int, list(input().split()))))
p = []
h = sorted(h, key=lambda x: ((x[0])**2 + (x[1])**2)**(1/2))
i = 1
j = 0

while i < n:
    d = ((h[i][0]-h[j][0])**2 + (h[i][1]-h[j][1])**2)**(1/2)
    if d < k:
        i += 1
    elif d > k:
        j += 1
    elif d == k:
        p.append((h[j], h[i]))
        i += 1

x = []
c = 0
for i in p:
    if i[0] not in x:
        x.append(i[1])
        c += 1

print(c)
