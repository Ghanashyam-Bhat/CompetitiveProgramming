# Given a board of cells containing a bubble of a specific color, your task is to emulate a bubble-popping game. In this game, the player can click a cell every turn to pop bubbles. After clicking the cell, the following happens: - The bubble in the clicked cell and bubbles of the same color among its diagonal neighbors are "popped" and removed, resulting in empty cells. - After bubbles are removed, the remaining bubbles in cells above the empty cells drop down to fill all empty cells. - Nothing happens if the clicked cell is empty (it does not contain a bubble). The input consists of two arrays: - An initial board of cells - a multidimensional array of integers representing cells containing different colored bubbles: - A set of player turns -2-element integer arrays describing the coordinates (the row and column) of the cell that the player clicked on during each turn. Return the state of the game board after all are processed. The output should be a multidimensional array of integers with the same size as but replace the integers in all empty cells (without bubbles) with 0 . Note: You are not expected to provide the most optimal solution, but a solution with time complexity not worse than bubbles [0]. length? - operations. Jength] will fit within the execution time limit.
# https://www.chegg.com/homework-help/questions-and-answers/given-board-cells-containing-bubble-specific-color-task-emulate-bubble-popping-game-game-p-q118840390

bubbles = [
   [ 1, 1, 1, 4, 3 ],
   [ 4, 1, 2, 3, 3 ],
   [ 1, 5, 1, 1, 2 ],
   [ 4, 3, 2, 2, 4 ]
]

operations = [
   [ 1, 1 ],
   [ 3, 3 ],
   [ 2, 2 ],
   [ 3, 0 ]
]

def recursive_pop( bubbles, x, y, val, popped, l, w ):
   if ( ( x,y ) not in popped ) and val and x<l and x>=0 and y<w and y>=0 and bubbles[ x ][ y ] == val:
      popped.add( ( x, y ) )
      popped.union(recursive_pop( bubbles, x+1, y+1, val, popped, l, w ))
      popped.union(recursive_pop( bubbles, x-1, y-1, val, popped, l, w ))
      popped.union(recursive_pop( bubbles, x+1, y-1, val, popped, l, w ))
      popped.union(recursive_pop( bubbles, x-1, y+1, val, popped, l, w ))
   return popped

def recursively_shift( bubbles, x, y ):
   bubbles[x][y] = 0
   if x-1 >= 0 and bubbles[x-1][y]!=0:
      bubbles[x][y] = bubbles[x-1][y]
      bubbles = recursively_shift( bubbles, x-1, y )
   return bubbles

def printArray( array ):
   for a in array:
      print( a )

def solution( bubbles, operations ):
   for op in operations:
      l,w = len( bubbles ), len( bubbles[0])
      x,y = op[0],op[1]
      popped = set()
      popped = recursive_pop( bubbles, x, y, bubbles[x][y], popped, l, w )
      print( popped )
      printArray( bubbles )
      for x,y in popped:
         bubbles = recursively_shift( bubbles, x, y )
   return bubbles

ans = solution( bubbles, operations )
print()
printArray( ans )



# <----------- ChatGpt Solution -------------->

from collections import deque

def pop_bubbles(board, clicks):
    rows, cols = len(board), len(board[0])
    
    def get_diagonal_neighbors(r, c, color):
        neighbors = []
        directions = [(-1, -1), (-1, 1), (1, -1), (1, 1)]  # Diagonal directions
        for dr, dc in directions:
            nr, nc = r + dr, c + dc
            if 0 <= nr < rows and 0 <= nc < cols and board[nr][nc] == color:
                neighbors.append((nr, nc))
        return neighbors
    
    def bfs_pop(r, c):
        color = board[r][c]
        queue = deque([(r, c)])
        popped = set([(r, c)])
        
        while queue:
            cr, cc = queue.popleft()
            for nr, nc in get_diagonal_neighbors(cr, cc, color):
                if (nr, nc) not in popped:
                    popped.add((nr, nc))
                    queue.append((nr, nc))
        
        for pr, pc in popped:
            board[pr][pc] = 0  # Mark as empty
    
    def apply_gravity():
        for col in range(cols):
            stack = []
            for row in range(rows - 1, -1, -1):
                if board[row][col] != 0:
                    stack.append(board[row][col])
            
            for row in range(rows - 1, -1, -1):
                board[row][col] = stack.pop(0) if stack else 0
    
    for r, c in clicks:
        if board[r][c] != 0:
            bfs_pop(r, c)
            apply_gravity()
    
    return board

