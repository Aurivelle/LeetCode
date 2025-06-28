class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) 
    {
        vector<int> copy = nums;
        int n = nums.size();

        nth_element(copy.begin(), copy.begin() + n - k, copy.end());
        int threshold = copy[n - k];

        int threshold_count = 0;
        for(int num : copy)
        {
            if(num > threshold)
            {
                threshold_count++;
            }
        }
        int remaining = k - threshold_count;

        vector<int> result;

        for(int num : nums)
        {
            if(num > threshold)
            {
                result.push_back(num);
            }
            else if(num == threshold && remaining > 0)
            {
                result.push_back(num);
                --remaining;
            }
            if(result.size() == k)
            {
                break;
            }
        }
        return result;

    }
};
