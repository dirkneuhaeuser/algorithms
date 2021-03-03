class Solution {
public:
    /// leetcode 943. Find the Shortest Superstring
    /// Traveling salesman problem
    /// dp[mask][j] = you travelled through cities in mask while the last city in mask is j
    /// recursion:  dp[mask][j] = min_i dp[mask^(1<<j)][i] + distance(i, j) // check all other cities in mask, let them be last before and check the distance from them
    string shortestSuperstring(vector<string>& w) {
        int n = w.size();
        vector<vector<int>> overlaps = vector<vector<int>>(n, vector<int>(n, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j) continue;
                int minS = min(w[i].size(), w[j].size());
                for(int k = minS; k>=0; --k){
                    if (w[i].substr(w[i].size()-k) == w[j].substr(0,k)){
                        overlaps[i][j] = k;
                        break;
                    }
                }
                
            }
        }
        
        vector<vector<int>> dp(1<<n, vector<int>(n,0));
        vector<vector<int>> parents(1<<n, vector<int>(n,-1));
        
        for(int mask=0; mask<(1<<n); mask++){ // O(2**n)
            for(int j=0; j<n; j++){ // O(n)
                if(!((mask >> j) & 1)) continue;
                int prevMask = mask^(1<<j);
                for(int prevB=0; prevB<n; prevB++){ // O(n)
                    if(!((prevMask >> prevB) & 1)) continue;
                    int val = dp[prevMask][prevB] + overlaps[prevB][j];
                    if(val > dp[mask][j]){
                        parents[mask][j] = prevB;
                        dp[mask][j] = val;
                    }
                    
                }
            }
        }

        int mask  = (1<<n)-1;
        int i = max_element(dp[mask].begin(),dp[mask].end()) - dp[mask].begin();
        vector<int> order;
        set<int> seen;
        while(i != -1){
            seen.insert(i);
            order.push_back(i);
            int oldI = i;
            i = parents[mask][i];
            mask = mask ^ (1<<oldI);
        }

        reverse(order.begin(), order.end());
        

        string ret = w[order[0]];
        for(int i = 1; i<order.size(); ++i){
            int start = overlaps[order[i-1]][order[i]];
            ret += w[order[i]].substr(start);
        }
        for(int i=0;i<n;i++){
            if(seen.find(i) == seen.end()){
                ret += w[i];
            }
        }
        return ret;

    }
};
