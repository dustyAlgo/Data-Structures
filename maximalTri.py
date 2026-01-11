class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if not matrix or not matrix[0]:
            return 0
        
        rows, cols = len(matrix), len(matrix[0])
        heights = [0] * (cols + 1)  # +1 for sentinel
        max_area = 0
        
        def largest_rectangle_histogram(heights):
            stack = []  # (index, height) monotonic increasing
            max_area_local = 0
            
            for i in range(len(heights)):
                while stack and heights[stack[-1][0]] > heights[i]:
                    idx, h = stack.pop()
                    # Width: from prev smaller to current smaller
                    left = stack[-1][0] if stack else -1
                    width = i - left - 1
                    max_area_local = max(max_area_local, h * width)
                
                stack.append((i, heights[i]))
            
            return max_area_local
        
        for i in range(rows):
            # Update heights for current row
            for j in range(cols):
                heights[j] = heights[j] + 1 if matrix[i][j] == '1' else 0
            
            # Calculate largest rectangle for this histogram
            max_area = max(max_area, largest_rectangle_histogram(heights))
        
        return max_area
