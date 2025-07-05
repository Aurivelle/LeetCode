class Solution {
public:
    int findLucky(vector<int>& arr) 
    {
        int hash[501] = {0};
        for(int num : arr)
        {
            hash[num]++;
        }   
        int max = -1;
        for(int i = 1; i < arr.size() + 1; ++i)
        {
            if(i == hash[i])
            {
                max = i;
            }
        }
        return max;
    }
};`
