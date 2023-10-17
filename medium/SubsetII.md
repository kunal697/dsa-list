## [Question](https://leetcode.com/problems/subsets-ii/)


Given an integer array nums that may contain duplicates, return all possible 
subsets
 (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 

Example 1:
```
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
```
the Subset 1 problem on leetcode is same you can use this solution also but even if you dont use set and sorting it will fine 


## Solution : 


### this is brute solution beacuse we are using set and then convertong it into vector
```cpp
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans; // Initialize a set to store unique subsets.
        vector<int> seq;      // Initialize a sequence vector to build subsets.
        vector<vector<int>> ans2; // Initialize a vector to store the final answer.
        
        sort(nums.begin(), nums.end()); // Sort the input array to handle duplicates.
        
        helper(0, nums, seq, ans); // Start the recursive process to find subsets.

        // Convert the set of unique subsets to a vector.
        for (vector<int> i : ans) {
            ans2.push_back(i);  
        }
        
        return ans2; // Return the vector of subsets as the answer.
    }

    // Recursive helper function to find unique subsets.
    void helper(int index, vector<int>& num, vector<int>& seq, set<vector<int>>& ans) {
        if (index == num.size()) {
            ans.insert(seq); // Insert the current sequence as a unique subset.
            return;
        }

        // Include the current element in the sequence and recurse.
        seq.push_back(num[index]);
        helper(index + 1, num, seq, ans);

        // Exclude the current element from the sequence and recurse.
        seq.pop_back();
        helper(index + 1, num, seq, ans);
    }
};
