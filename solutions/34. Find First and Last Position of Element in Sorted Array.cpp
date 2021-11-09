class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {bs(nums,target), bs(nums,target+1)-1};
        vector<int> a {-1,-1};
        return (res[0] >= 0 && res[1] >= 0 && target == nums[res[0]] && target == nums[res[1]]) ? res : a;
    }
    
    int bs(vector<int> nums, int target){
        int l = 0;
        int r = nums.size()-1;
        int index = -1;
        while(l <= r){
            int mid = (l + r )/2 ;
            if(nums[mid] < target){
                l = mid+1;
            }
            else if (nums[mid] > target){
                r = mid - 1;
            }
            else{
                r = mid - 1;
            }
            index = mid;
        }
        
        return index;
    }
};
