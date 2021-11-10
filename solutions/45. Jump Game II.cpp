class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> memo (nums.size(), INT_MAX);
        int step = 0;
        return dp(nums, memo, 0);
    }
    
    int dp(vector<int>& nums, vector<int>& memo, int index){
        if(index >= nums.size()-1) {
            return 0;
        }
        
        if(memo[index] != INT_MAX)
            return memo[index];
​
        int res = 10000;
        for(int i = 1; i <= nums[index]; i++){
            res = min(res,  1 + dp(nums, memo, index + i));
        }
        
        return memo[index] = res;
    }
};
