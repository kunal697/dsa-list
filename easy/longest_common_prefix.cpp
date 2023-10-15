class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        return helper(strs , 0 , strs.size()-1);
    }
    string helper(vector<string>& strs , int left , int right){
        if(left == right)  return strs[left];
        int mid = (left + right) /2;
        string l = helper(strs , left , mid);
        string r = helper(strs , mid+1 , right);

        int minlen = min(l.length() , r.length());
        string ans = l.substr(0,minlen);
        for(int i = 0 ; i < minlen  ; i++){
            cout << l << "   " << r << "  " << left << " " << right << endl;
            if(l[i]!=r[i]){
                ans = l.substr(0,i);
                break;
            }
        }
        return ans;

    }
};
