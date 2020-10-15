class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
     
        vector<int> ret;
        for(int i = 0; i < nums1.size(); ++i){
            bool check = true;
            for(int j = i; j < nums2.size(); ++j){
                if (nums[i] < nums[j]){
                    ret.push_back(nums[j]);
                    check = false;
                    break
                }
            }
            if (check) {
                ret.push_back(-1);
            }
            
        }
        return ret;
        
    }
};
