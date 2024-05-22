class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        if not triangle:
            return 0
        
        # Initialize the dp array with the last row of the triangle
        dp = triangle[-1]
        
        # Start from the second last row and move upwards
        for i in range(len(triangle) - 2, -1, -1):
            for j in range(len(triangle[i])):
                # For each element, choose the minimum path from the two adjacent numbers in the row below
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1])
        
        # The top element of dp will contain the minimum path sum
        return dp[0]
