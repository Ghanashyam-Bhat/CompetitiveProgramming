
def countDistinct(arr, n):
    arr.sort()
    c = 0
    for i in range(n):
        if i==0 or i==n-1:
            if i==0:
                if arr[i]!=arr[i+1]:
                    c+=1
            else:
                if arr[i]!=arr[i-1]:
                    c+=1
        else:
            if arr[i]!=arr[i+1] and arr[i]!=arr[i-1] :
                    c+=1
    return c
            

trials = int(input())
for trial in range(trials):
    n = int(input())
    l = list(map(int,list(input().split())))
    c = countDistinct(l,n)
    if c%2==0:
        print(int(c/2))
    else :
        print(int(c/2)+1)
        
