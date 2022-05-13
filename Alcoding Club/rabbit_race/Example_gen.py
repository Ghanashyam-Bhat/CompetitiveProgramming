import random
t = 1000
n_limit = 998
a_limit = 1000
print(t)
for _ in range(t):
    n = random.randint(1, n_limit)
    a = [random.randint(0, a_limit) for x in range(n)]
    s = sum(a)
    xor = a[0]
    for i in a[1:]:
        xor^=i
    if 2*xor == s:
        pass
    elif xor == 0:
        a.append(s)
        n += 1
    else:
        a.append(xor)
        a.append(s+xor)
        n += 2
    print(n)
    print(*a, sep=" ")