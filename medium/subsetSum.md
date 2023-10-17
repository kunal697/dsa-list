## [Question]( https://practice.geeksforgeeks.org/problems/subset-sums2234/1) :

Given an array of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum. 


Example 1:

```
Input:
N = 2
arr[] = {2, 3}
Output:
0 2 3 5
Explanation:
When no elements is taken then Sum = 0.
When only 2 is taken then Sum = 2.
When only 3 is taken then Sum = 3.
When element 2 and 3 are taken then 
Sum = 2+3 = 5.
```

##Solution :
 ```cpp
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> seq;
        vector<int> ans;
         helper(0,arr,seq,ans,0);
        return ans;
        
    }
   void helper(int index, vector<int>&arr, vector<int> &seq,vector<int> &ans,int target)
    {
        if(index==arr.size())
        {
            ans.push_back(target);
            return;         //return is important to avoid segmentation fault
        }
        
        seq.push_back(arr[index]);                 //include
        helper(index+1,arr,seq,ans,target+arr[index]);
       
        
        seq.pop_back();                                  //not include
        helper(index+1,arr,seq,ans,target);
         
        
         
    }
    ```
 
