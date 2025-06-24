class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) 
    {
        vector<int> ans;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] == key)
            {
                for(int j = i - 1; j >= 0 && i - j <= k; --j)
                {
                    if(std::find(ans.begin(), ans.end(), j) == ans.end())
                    {
                        ans.push_back(j);
                    }
                }
                for(int j = i; j < nums.size() && j - i <= k; ++j)
                {
                    if(std::find(ans.begin(), ans.end(), j) == ans.end())
                    {
                        ans.push_back(j);
                    }
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;

    }
};
