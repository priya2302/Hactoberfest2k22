/*
return all possible subsets (the power set)
nums = [1,2,3]
subset :-
[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
*/

class Solution {
public:
    void subset(int i,vector<int> &sub,vector<vector<int>> &ans,vector<int> &nums)
    {
        if(i==nums.size())
        {
            ans.push_back(sub);
            return;
        }
        //ith element is not taken
        subset(i+1,sub,ans,nums);
        sub.push_back(nums[i]);
        subset(i+1,sub,ans,nums);
        sub.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
      vector<vector<int>> ans;
        vector<int> sub;
        subset(0,sub,ans,nums);
        return ans;
    }
};
