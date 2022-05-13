n = int(input())
string = input()
t = int(input())
l = list(input().split())
l = list(map(int,l))
for i in range(t):
    x = l[i]/n 
    if x>2 and x%2==0:
        
    print(string[l[i]%n-1])