class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int,int>> stk;
        int maxArea = 0;
        int len = heights.size();
        for(int i = 0 ; i < len ; i++){
            if(stk.empty()){
                stk.push({heights[i] , i});
                continue;
            }
            int start = i;
            while( !stk.empty() && stk.top().first > heights[i]){
                int width = i - stk.top().second;
                maxArea = max(maxArea , stk.top().first * width);
                start = stk.top().second;
                stk.pop();
                
            }
            stk.push({heights[i],start});
        }
        while(!stk.empty()){
            int height = stk.top().first ;
            int width = len - stk.top().second;
            maxArea = max(maxArea , height*width);
            stk.pop();
        }
        return maxArea;
    }
};
