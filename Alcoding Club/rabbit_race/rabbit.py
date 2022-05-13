"""
Inorder to check the truth in a childhood story "Tortois vs Rabbit Race", 2 trainers trained their respective pets. The tortoise owner noticed that, just like the story the tortoise was moving in a constant speed of 15m/s from the start point to the end point. The rabbit was moving in the variable speed for different intervals of time.
Your job is to determine if the tortoise wins the race or the rabbit based on the data provided by the owners.The problem here is, the rabbit owner messed up the data and now he doesn't know what time interval corresponds to what speed.Based on the given data your have to tell if the story is true or it may be false.
Input format
- Number of test cases
- Time taken by the tortoise to complete the race in seconds  Number of chuncks of time intervals/speeds of rabbit
- n chuncks of Speed in m/s 
- n chuncks of time in seconds

Output format
- Print True if if Rabbit can never win and the story is always true
- Print False if Rabbit has chances to win
	If False
		print 1 if Rabbit always wins
		print 2 incase of mixed results

Sample Input
1
10 5
0 0 5 18 4
6 3 4 1 2

Sample Output
True
"""

trials = int(input())
ts = 15
for trial in range(trials):
    tt,n = input().split()
    tt,n = int(tt), int(n)
    rs = list(input().split())
    rs = list(map(int,rs))
    rt = list(input().split())
    rt = list(map(int,rt))
    d = ts*tt
    rs.sort();rt.sort()
    rd1 = sum(list(map(lambda x:x[0]*x[1],list(zip(rt,rs)))))
    rt.reverse()
    rd2 = sum(list(map(lambda x:x[0]*x[1],list(zip(rt,rs)))))
    if rd1<d :
        print(True)
    else:
        print(False)
        if rd2>d :
            print(1)
        else :
            print(2)