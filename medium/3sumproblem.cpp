class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(begin(nums) , end(nums));
        int target = 0;
        vector<vector<int>> ans;
        for(int i = 0 ; i < nums.size();i++){
            
            int left = i+1;
            int right = nums.size()-1;
            if(nums[i] > 0)break;
            while(i < nums.size()-1 && nums[i] == nums[i+1]) i++;
            while(left < right){
                int sum = nums[i] + nums[left]+ nums[right];

                if(sum > target){
                    right--;
                }
                else if(sum < target){
                    left++;
                }
                else{
                    vector<int> curr_ans = {nums[i] , nums[left] , nums[right]};
                    ans.push_back(curr_ans);
                    left++;
                    right--;

                    while(left <nums.size() && nums[left] == nums[left-1]) left++;
                    while(right > i && nums[right] == nums[right+1]) right --;         
                }
            }
        }

        return ans;
    }
};
