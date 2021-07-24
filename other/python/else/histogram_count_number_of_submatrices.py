class Solution:
    def numSubmat(self, mat: List[List[int]]) -> int:
        """
        LC: 1504
        idea: Use histogram count. to count all the rectanges you have to cases:
        1. case: previous smaller bar
        2. case: previous bigger bar
        
        -if prev. bar is smaller -> no problem. for all elements in prev, you can just extend them and get new elements
        (dp[j] = dp[stack[-1]])
        
        if prev bigger: pop while getting a smaller one. Now you take the bigger ones inton account with 
        histogram[j] * (j-stack[-1])
        and the new smaller one still is covered with dp[stack[-1]
        """
        
        rows, cols = len(mat), len(mat[0])
        ret = 0
        histogram = [0] * (cols + 1)
        for i in range(rows):
            dp = [0] * (cols + 1)
            stack = [-1]
            for j in range(cols):
                histogram[j] = 1 + histogram[j] if mat[i][j] else 0
                while histogram[j] < histogram[stack[-1]]:
                    stack.pop()
                dp[j] = dp[stack[-1]] + histogram[j] * (j-stack[-1])
                stack.append(j)
            ret += sum(dp)
        return ret
