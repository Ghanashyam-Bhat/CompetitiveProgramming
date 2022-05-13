"""trials = int(input())
for  trial in range(trials):
    n = int(input())
    a = list(map(int,input().split()))
    a.sort();
    max = a.pop();
    if n>1:
        max = a.pop()
    for i in range(n-2):
        max -= a[i]
        max += a[i]*(n-i-3)
    print(max)"""
    
trials = int(input())
for  trial in range(trials):
    n = int(input())
    a = list(map(int,input().split()))
    a.sort(reverse=True);
    while (n>2):
        min = a.pop()
        a = list(map(lambda x:x-min,a))
        n-=1
    if n==2:
        print(a[1])
    else: 
        print(a[0])
        