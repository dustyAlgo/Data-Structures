class Solution:
    def largestSquareArea(self, bottomLeft: List[List[int]], topRight: List[List[int]]) -> int:
        ans = 0
        for ((x1, y1), (x2, y2)), ((x3, y3), (x4, y4)) in combinations(zip(bottomLeft, topRight), 2):
            w = min(x2, x4) - max(x1, x3)
            h = min(y2, y4) - max(y1, y3)
            e = min(w, h)
            if e > 0:
                ans = max(ans, e * e)
        return ans

# 1895 largest magic square - leetcode
class Solution:
    def largestMagicSquare(self, grid: List[List[int]]) -> int:
        if not grid or not grid[0]:
            return 1
        
        rows, cols = len(grid), len(grid[0])
        
        # Build row and column prefix sums (1-indexed)
        row_prefix = [[0] * (cols + 1) for _ in range(rows + 1)]
        col_prefix = [[0] * (cols + 1) for _ in range(rows + 1)]
        
        for i in range(1, rows + 1):
            for j in range(1, cols + 1):
                row_prefix[i][j] = row_prefix[i][j - 1] + grid[i - 1][j - 1]
                col_prefix[i][j] = col_prefix[i - 1][j] + grid[i - 1][j - 1]
        
        def is_magic(r1: int, c1: int, r2: int, c2: int) -> bool:
            # Target sum from first row
            target = row_prefix[r1 + 1][c2 + 1] - row_prefix[r1 + 1][c1]
            
            # Check rows
            for r in range(r1 + 1, r2 + 1):
                if row_prefix[r + 1][c2 + 1] - row_prefix[r + 1][c1] != target:
                    return False
            
            # Check columns
            for c in range(c1, c2 + 1):
                if col_prefix[r2 + 1][c + 1] - col_prefix[r1][c + 1] != target:
                    return False
            
            # Main diagonal
            diag1 = 0
            for k in range(r2 - r1 + 1):
                diag1 += grid[r1 + k][c1 + k]
            if diag1 != target:
                return False
            
            # Anti-diagonal
            diag2 = 0
            for k in range(r2 - r1 + 1):
                diag2 += grid[r1 + k][c2 - k]
            if diag2 != target:
                return False
            
            return True
        
        # Try from largest size down
        for k in range(min(rows, cols), 0, -1):
            for i in range(rows - k + 1):
                for j in range(cols - k + 1):
                    if is_magic(i, j, i + k - 1, j + k - 1):
                        return k
        
        return 1
