fish = [ 1, 2, 3 ]
baits = [ 1 ]

def solution( fish, baits ):
   fish.sort( reverse=True ) 
   baits.sort( reverse=True )

   i = 0
   j = 0

   k = 0
   while True:
      if j==len( baits ) or i==len( fish ):
         return i
      if fish[i] > baits[j]:
         k += 1
         i += 1
      else:
         k = 0
      k = k%3
      if k == 0:
         j += 1

ans = solution( fish, baits )
print( ans )