matrix = [
   ['F','F','F'],
   ['_','F','_'],
   ['_','F','F'],
   ['#','F','_'],
   ['F','F','_'],
   ['_','_','F'],
   ['F','_','#'],
   ['_','_','_']
]

def solution( matrix ):
   l = len( matrix )
   w = len( matrix[0] )

   F = [ 0 for _ in range( w ) ]
   B = [ l for _ in range( w ) ]
   j = 0
   sB = l-1
   for i in range( l ):
      for j in range( w ):
         if matrix[i][j] == 'F':
            F[j] = i
         elif matrix[i][j] == '#':
            print("break",i,j)
            B[j] = i
      
      mS = []
      for k in range( w ):
         mS.append( (B[k]-F[k]) )
      printMatrix( [ mS, F, B ] )
      sB = min( sB, ( min( mS ) - 1 ) )
      F = [ 0 for _ in range( w ) ]
      B = [ l for _ in range( w ) ]

   print( sB )
   for i in range( l ):
      for j in range( w ):
         if matrix[l-i-1][w-j-1] == 'F':
            matrix[l- i - 1 + sB ][w - j- 1 ] ='F'
            matrix[l-i-1][w-j-1] = "_"
   return matrix

def printMatrix( matrix ):
   for i in matrix:
      print(i)
   print()

ans = solution( matrix )
printMatrix( ans )