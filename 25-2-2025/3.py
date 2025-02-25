lamps = [ [1,7], [5,11], [7,9] ]
points = [ 7, 1, 5, 10, 9, 15 ]

def solution( lamps, points ):
   ans = [ ]
   for p in points:
      a = 0
      for min,max in lamps:
         if p >= min and p <= max:
            a += 1
      ans.append( a )
   return ans

def solution1( lamps, points ):
   l = []
   for i in lamps:
      l += list( range( i[0], i[1]+1 ))
   ans = []
   for i in points:
      if i in l:
         ans.append( l.count( i ) )
      else:
         ans.append( 0 )
   return ans

def solution2(lamps, points):
    light_map = {}
    
    # Mark all illuminated positions
    for start, end in lamps:
        for i in range(start, end + 1):
            light_map[i] = light_map.get(i, 0) + 1  # Count illumination frequency

    # Find how many times each point is illuminated
    return [light_map.get(p, 0) for p in points]

def solution3(lamps, points):
    min_x = min(l[0] for l in lamps)  # Find min lamp position
    max_x = max(l[1] for l in lamps)  # Find max lamp position

    illumination = {}  # Dictionary for difference array

    # Marking the ranges using a difference array approach
    for start, end in lamps:
        illumination[start] = illumination.get(start, 0) + 1
        illumination[end + 1] = illumination.get(end + 1, 0) - 1

    # Compute prefix sum to get illumination at each point
    light_map = {}  # Store illumination count at each position
    current_light = 0

    for i in range(min_x, max_x + 1):
        if i in illumination:
            current_light += illumination[i]
        light_map[i] = current_light  # Store illumination count

    # Answer queries in O(1) using dictionary lookups
    return [light_map.get(p, 0) for p in points]

ans = solution(lamps, points )
print(ans)

ans = solution1(lamps, points )
print(ans)

ans = solution2( lamps, points )
print( ans )

ans = solution3( lamps, points )
print( ans )