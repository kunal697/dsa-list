/*
 * Title : Longest Substring Without Repeating Characters
 * 
 * Problem Link :
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/
 * Submission Link : https://leetcode.com/submissions/detail/737643234/
 *
 *
 *
 *
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_set<char> sett;
    int left = 0, right = 0, len = s.size(), ans = 0;
    int max_ans = 0;
    while (right < len) {

      if (sett.find(s[right]) == sett.end()) {
        sett.insert(s[right]);
        right++;
        ans = max(right - left, ans);

      } else {
        sett.erase(s[left]);
        left++;
      }
    }
    return ans;
  }
};
