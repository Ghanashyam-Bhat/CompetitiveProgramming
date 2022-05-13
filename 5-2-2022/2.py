trials = int(input())
for trial in range(trials):
    s = list(input())
    a = ord(s[0])
    a -= 96
    b = ord(s[1])
    b -= 96
    if a>b:
        x = 0
    else:
        x = 1
    print((a-1)*26+b-a+1-x)