class Solution {
public:
    /// using a vector for memo (NEED to be initialized in method)
    /// Note that if the return value is -1 the cache does actuallu not work (neglectable) 
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> mem(n, vector<int>(n, -1)); 
        return helper(0, s.size()-1, s, mem);
    }
    int helper(int l, int r, string &s, vector<vector<int>> &mem) {
        if (mem[l][r] != -1){
            return mem[l][r];
        }
        if (l > r){
            return 0;
        } else if (l == r){
            return 1;
        }
        return mem[l][r] =  s[l] == s[r] ? 2 + helper(l+1, r-1, s, mem) : max(helper(l+1, r, s, mem), helper(l, r-1, s, mem));
    }
};



class Solution {
public:
    /// dp where a classic c-array is used for memo, c-arrays dont need to be declared
        /// Note that if the return value is -1 the cache does actuallu not work (neglectable) 
    int dp[1001][1001] = {};
    int maximumScore1(vector<int>& nums, vector<int>& multipliers) {
        return dfs(0,0, nums, multipliers);
    }
    int dfs(int i, int j, vector<int>& nums, vector<int>& m){
        if (dp[i][j]){
            return dp[i][j];
        }
        if (i+j == m.size()){
            return 0; 
        }
        int curI = i + j;
        return dp[i][j] = max(m[curI] * nums[i] + dfs(i+1, j, nums, m), m[curI] * nums[nums.size()-1-j] + dfs(i, j+1, nums, m)); 
    }
}