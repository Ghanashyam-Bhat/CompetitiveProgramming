#Status: Test 1 Passed -> Test 2 Failed 
#https://codeforces.com/problemset/problem/1480/B
def survival(A,B,n,ai,bi):
    #c = list(zip(ai,bi))
    #c.sort(key= lambda x:x[0])
    #ai , bi = zip(*c)
    #ai = list(ai)
    #bi = list(bi)
    x = -1
    y = 0
    for each_monster in range(n): #For each monster
        x += 1
        z = int(bi[x])
        while z > 0 :
            #For each fight
            z -= A
            B -= int(ai[x])
            if z <= 0: #whenever monster dies
                y+=1
            if B <= 0: #when hero dies
                break
        if B <= 0:#when hero dies
            return  "Hero is dead",y
            break
    if y==n :
        return "Hero survived" , y


no_inputs = int(input()) #Number of inputs
k = 0
while k < no_inputs :
    k += 1
    A , B, n = input().split(" ") #Attack power and initial health of the hero
    A , B , n = int(A) , int(B) , int(n) #Total no. of monsters
    ai = list(input().split(" ")) #Attack power of each monster
    bi = list(input().split(" ")) #Initial health of each monster
           
    t = survival(A,B,n,ai,bi)
    i,j = t
    if j == n:
        #print("All the monsters dead and", i)
        print("YES")
    else:
        #print(i,"before killing all the monsters")
        print("NO")