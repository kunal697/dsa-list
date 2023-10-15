class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right  = height.size()-1;
        int max_water = INT_MIN;
        while(left <right){
            int quantity = (right-left) * min(height[left]  , height[right]);
            max_water = max(max_water , quantity);

            if(height[left] < height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return max_water;
    }
};

