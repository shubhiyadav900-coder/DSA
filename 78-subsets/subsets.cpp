class Solution {
public:

    vector<vector<int>> ans;
    vector<int> ds;

    void solve(int index, vector<int>& nums)
    {
        // Base Case
        if(index == nums.size())
        {
            ans.push_back(ds);
            return;
        }

        // Take
        ds.push_back(nums[index]);
        solve(index + 1, nums);

        // Backtrack
        ds.pop_back();

        // Don't Take
        solve(index + 1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums)
    {
        solve(0, nums);
        return ans;
    }
};