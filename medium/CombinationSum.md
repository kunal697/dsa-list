
## [Question](https://leetcode.com/problems/combination-sum/) : 

Example :
```
Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
```

## Solution :

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> seq;

        // Call the recursive function to find combinations that sum up to the target
        com(candidates, target, 0, 0, ans, seq);
        
        return ans;
    }

    // Recursive function to find combinations
    void com(vector<int>& can, int target, int sum, int index, vector<vector<int>>& ans, vector<int>& seq) {
        // If the sum exceeds the target, return without further exploration
        if (sum > target) {
            return;
        }
        
        // If we've reached the end of the candidates array
        if (index == can.size()) {
            // If the sum equals the target, add the current sequence to the answer
            if (sum == target) {
                ans.push_back(seq);
            }
            return; // Return to explore other possibilities
        }

        // Include the current candidate in the sequence and recurse
        seq.push_back(can[index]);
        com(can, target, sum + can[index], index, ans, seq);

        // Remove the current candidate from the sequence and move to the next candidate
        seq.pop_back();
        com(can, target, sum, index + 1, ans, seq);
    }
};
