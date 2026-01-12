class Solution:
    def printDiamond(self, N):
        rows= 1
        while(rows<=N):
            spaces = N - rows
            while(spaces):
                print(" ", end = "")
                spaces = spaces-1
            cols = 1    
            while(cols<=rows):
                print("*", end =" ")
                cols = cols+1
            print()
            rows = rows+1
        rows = N
        while(rows>=1):
            spaces = N - rows
            while(spaces):
                print(" ", end = "")
                spaces = spaces-1
                
            cols = 1
            while(cols<=rows):
                print("*", end =" ")
                cols = cols+1
            print()
            rows = rows-1
        