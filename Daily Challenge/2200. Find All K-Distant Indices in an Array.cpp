class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) 
    {
        vector<bool> seen(nums.size(), false);
        vector<int> ans;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(nums[i] == key)
            {
                int left = max(0, i - k);
                int right = min((int)nums.size() - 1, i + k);
                for(int j = left; j <= right; ++j)
                {
                    if(!seen[j])
                    {
                        seen[j] = true;
                        ans.push_back(j);
                    }
                }
            }
        }
        return ans;

    }
};
