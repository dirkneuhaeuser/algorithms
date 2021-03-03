class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i=n; i>=0; i--){
            for(int j=i; j<n; j++){
                if(i==j) {
                    dp[i][j]=1;
                } else{
                    if (s[i]==s[j]){
                        dp[i][j] = max(max(2 + dp[i+1][j-1], dp[i+1][j]) , dp[i][j-1]);
                    } else{
                        dp[i][j] = max(dp[i+1][j] , dp[i][j-1]);
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};






    //// Different problem
    /// dp[i][j] max number after taking i from left and j from right
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size(), m = multipliers.size();
        vector<vector<int>> dp (m+1, vector<int>(m+1,-1 * (1 << 30)));
        dp[0][0] = 0;
        for(int i = 0; i < m+1; i++){
            for(int j = 0; i+j< m+1; j++){
                int total = i + j;
                if (i){
                    dp[i][j] = multipliers[total-1]*nums[i-1] + dp[i-1][j];
                }
                if (j){
                    dp[i][j] = max( dp[i][j], multipliers[total-1]*nums[n - 1 - (j-1)] + dp[i][j-1]);
                }
            }
        }
        int ret = dp[0][m];
        for(int j=1; j<m+1; j++){
            ret = max(ret, dp[j][m-j]);
        }
        return ret;
        
    }
